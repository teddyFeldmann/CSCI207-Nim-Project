/*
    Author: Teddy Feldmann
    Date: 20 Feb 2021
    Name: Nim
    Description: This program is a game called Nim where 
                 two players alternate turns taking items 
                 from a heap until there are none left
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{

    // Initialize random seed
    srand(time(NULL));

    string userInput;
    int userNumber;
    int computerNumber;
    int heapCount = 23;
    bool gameInSession = true;
    bool isUserInput = false;
    bool computerNeedsToGo = true;

    // While loops repeats turns until game is over
    while (gameInSession)
    {
        // Get user input of integer 1, 2, or 3 (loop continues if invalid input)
        while (!isUserInput)
        {
            cout << "------------------------------------" << endl;
            if (heapCount > 3)
            {
                cout << "Please enter 1, 2, or 3 to indicate how many objects you remove." << endl;
                cout << "User Number: ";
                cin >> userInput;
                // Checks to see if user input is valid
                if (userInput == "1" || userInput == "2" || userInput == "3")
                {
                    // Converts string input to integer
                    if (userInput == "1")
                    {
                        userNumber = 1;
                    }
                    else if (userInput == "2")
                    {
                        userNumber = 2;
                    }
                    else if (userInput == "3")
                    {
                        userNumber = 3;
                    }
                    isUserInput = true;
                }
                else
                {
                    cout << "The value you entered is invalid." << endl;
                }
            }

            // In case heap has 3 items, user would only input 1 or 2
            else if (heapCount == 3)
            {
                cout << "Please enter 1 or 2 to indicate how many objects you remove." << endl;
                cout << "User Number: ";
                cin >> userInput;
                if (userInput == "1" || userInput == "2")
                {
                    if (userInput == "1")
                    {
                        userNumber = 1;
                    }
                    else if (userInput == "2")
                    {
                        userNumber = 2;
                    }
                    isUserInput = true;
                    cout << userNumber << endl;
                }
                else
                {
                    cout << "The value you entered is invalid." << endl;
                }
            }
        }
        // Set isUserInput back to false so it will enter loop again
        isUserInput = false;

        // Update heap
        heapCount -= userNumber;

        // Check for winner to determine if computer will go
        if (heapCount == 1)
        {
            cout << "Computer lost -- human wins" << endl;
            computerNeedsToGo = false;
            gameInSession = false;
        }
        else if (heapCount == 2)
        {
            cout << "Computer plays 1, then human draws last 1. Computer wins." << endl;
            computerNeedsToGo = false;
            gameInSession = false;
        }
        else
        {
            cout << "Heap Count: " << heapCount << endl;
            computerNeedsToGo = true;
        }

        // Determine if computer needs to go
        while (computerNeedsToGo)
        {
            cout << "------------------------------------" << endl;

            // Get random computer number based on heap count and update heap
            if (heapCount > 3)
            {
                computerNumber = rand() % 3 + 1;
                cout << "Computer Number: " << computerNumber << endl;
                heapCount -= computerNumber;
                cout << "Heap Count: " << heapCount << endl;
            }
            else if (heapCount == 3)
            {
                computerNumber = rand() % 2 + 1;
                cout << "Computer Number: " << computerNumber << endl;
                heapCount -= computerNumber;
                cout << "Heap Count: " << heapCount << endl;
            }

            // Check for winners before completing next loop through
            if (heapCount == 1)
            {
                cout << "Human lost, computer wins" << endl;
                gameInSession = false;
            }
            else if (heapCount == 2)
            {
                cout << "Human plays 1, then Computer draws last 1. Human wins." << endl;
                gameInSession = false;
            }

            // Ensure computer can choose a number again next loop through
            computerNeedsToGo = false;
        }

    }
    cout << "------------------------------------" << endl;

    return 0;
}