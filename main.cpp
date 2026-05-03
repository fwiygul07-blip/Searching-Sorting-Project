#include <iostream>
#include <string>

// random number
// used for: list initialization
#include <ctime>
#include <cstdlib>

#include "linkedlist.h"

using namespace std;

void initializeList(LinkedList &numbers);

int main()
{
    LinkedList numbers;

    initializeList(numbers);

    cout << "\nInitial list: " << endl;
    numbers.display();

    cout << endl << "Welcome to the numbers display manager." << endl << endl;

    while(1)
    {
        string option;

        cout << "0. Exit" << endl;

        // some organization
        cout << "1. Sort Numbers" << endl;
        cout << "2. Shuffle Numbers" << endl;
        cout << "3. Display Numbers" << endl;
        cout << "4. Search Numbers" << endl;
        cout << "5. Reverse Sort Numbers" << endl;
        cout << "6. Remove Values" << endl;
        cout << "7. Sort Numbers -- a different way" << endl;

        cout << endl << "Which option would you like? ";
        cin >> option;

        cout << endl;

        // exiting
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // sorting
        else if(option == "1")
        {
            numbers.sort();
            numbers.display();
        }

        // shuffle
        else if(option == "2")
        {
            numbers.shuffle();
            numbers.display();
        }

        // display
        else if(option == "3")
        {
            numbers.display();
        }

        // searching
        else if(option == "4")
        {
            cout << "CAUTION: Will not work properly if the list was not sorted first!" << endl << endl;

            int number;

            cout << "What number would you like to search? ";
            cin >> number;

            int result = numbers.binarySearch(number);

            if(result >= 0)
            {
                cout << endl << "Number found at position " << result << endl;
            }

            else
            {
                cout << endl << "Number not found." << endl;
            }
        }

        // reversing
        else if(option == "5")
        {
            numbers.reverseSort();
            numbers.display();
        }

        // remove values
        else if(option == "6")
        {
            numbers.display();

            cout << endl << "CAUTION: Will not work properly if the list was not sorted first!" << endl << endl;

            int num;

            cout << endl << "What number value would you like to remove? ";
            cin >> num;

            numbers.removeValues(num);
        }

        else if(option == "7")
        {
            numbers.differentSort();
            numbers.display();
        }

        // **********************************************

        // incorrect option
        else
        {
            cout << "That's not a valid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

void initializeList(LinkedList &numbers)
{
    // seeds random number
    srand(time(NULL));

    for(int i = 0; i < 20; i++)
    {
        numbers.append(rand() % 10);
    }
}
