#include <iostream>
#include <string>
#include <limits>
#include "PyStringList.h"

using namespace std;

int readInt(const string& message)
{
    int number;
    bool valid = false;

    cout << message;

    while (!valid)  
    {
        if (cin >> number)
        {
            if (number >= 0)
                valid = true;
            else
                cout << "Error: number must be non-negative. Try again: ";
        }
        else
        {
            cout << "Error: please enter a valid number: ";
            cin.clear();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return number;
}

bool isAllSpaces(const string& s)
{
    for (char c : s)
        if (c != ' ')
            return false;
    return true;
}

string readString(const string& message)
{
    string s;
    bool valid = false;

    while (!valid) 
    {
        cout << message;
        getline(cin, s);

        if (s.empty() || isAllSpaces(s))
            cout << "Error: empty or space-only string is not allowed.\n";
        else
            valid = true;
    }

    return s;
}

int main()
{
    PyStringList list;

    int count = readInt("How many strings do you want to enter? ");

    for (int i = 0; i < count; i++)
    {
        string s = readString("Enter data " + to_string(i + 1) + ": ");
        list.append(s);
    }

    cout << "\nList contents:\n";
    for (int i = 0; i < list.size(); i++)
        cout << "- " << list.get(i) << "\n";

    return 0;
}
