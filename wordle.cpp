#include <iostream>
#include <windows.h>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

int TRIES = 5;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int correct;
// Create a map for the word to color letters yellow
map <char,int> valid;

void PrintChar(char input)
{
    // Print input character capitalized
    char cap = toupper(input);
    cout << cap;
    return;
}

int main ()
{
    
    // Initalize variables to use
    string input = " ";
    int count = 0;
    correct = 0;

    string ran = "start";

    // Have 5 tries
    while (count < TRIES)
    {
        // Set the map with the correct number of repetitions of each letter
        for (int i = 0; i < ran.size(); i++)
        {
            valid[ran[i]] += 1;
        }

        // Validate input
        while (input.size() < TRIES || input.size() > TRIES)
        {
            cout << "Enter a 5 letter word: ";
            getline(cin, input);
        }

        // Check input with the word
        // 1. Capitalize the input
        // 2. Color the letters correctly
        // 3. Increase or decrease counters
        for (int i = 0; i < TRIES; i++)
        {
            if (valid[input[i]] && ran[i] == input[i])
            {
                // Color letter green and print
                SetConsoleTextAttribute(h, 2);
                PrintChar(input[i]);

                // Count correct letters and decrease count of specific letter
                valid[input[i]]--;
                correct++;
            }

            // If this letter is in the map
            else if (valid[input[i]])
            {
                // Color letter yellow, print and decrease specific letter count
                SetConsoleTextAttribute(h, 14);
                PrintChar(input[i]);
                valid[input[i]]--;
            }

            else
            {
                // If in none, print in white
                SetConsoleTextAttribute(h, 7);
                PrintChar(input[i]);
            }
        }

        // Return color of terminal to white
        SetConsoleTextAttribute(h, 7);
        cout << endl;

        // Count tries
        cout << "Tries: " << count + 1 << "/" << TRIES << endl;
        count++;

        // If all letters are green
        if (correct == TRIES)
        {
            cout << "YOU WIN!" << endl;
            break;
        }

        // If arrived at max tries
        else if (count == TRIES)
        {
            cout << "Better luck next time :(" << endl;
            cout << "The word was: ";
            SetConsoleTextAttribute(h, 3);

            // Print the correct word
            cout << "START" << endl;
            SetConsoleTextAttribute(h, 7);
            
        }

        // Reset variables
        input = "";
        correct = 0;
        valid.clear();
    }

    return 0;
}


