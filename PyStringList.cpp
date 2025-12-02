#include "PyStringList.h"
#include <iostream>
#include <cctype>

PyStringList::PyStringList(int initialCapacity)
    : capacity(initialCapacity), length(0)
{
    items = new void*[capacity];
}

PyStringList::~PyStringList()
{
    clear();
    delete[] items;
}

void PyStringList::resize()
{
    int newCapacity = capacity * 2;
    void** newArray = new void*[newCapacity];

    for (int i = 0; i < length; i++)
        newArray[i] = items[i];

    delete[] items;
    items = newArray;
    capacity = newCapacity;
}

bool PyStringList::isValidInput(const string& s)
{
    if (s.empty())
    {
        cout << "Error: Empty string is not allowed.\n";
        return false;
    }

    for (char c : s)
    {
        if (!isprint(static_cast<unsigned char>(c)))
        {
            cout << "Error: Invalid character.\n";
            return false;
        }
    }

    return true;
}

void PyStringList::append(const string& value)
{
    if (!isValidInput(value))
        return;

    if (length == capacity)
        resize();

    string* stored = new string(value);
    items[length] = stored;
    length++;
}

string PyStringList::get(int index) const
{
    if (index < 0 || index >= length)
    {
        cout << "Error: Index out of range.\n";
        exit(1);
    }

    return *static_cast<string*>(items[index]);
}

void PyStringList::set(int index, const string& value)
{
    if (index < 0 || index >= length)
    {
        cout << "Error: Index out of range.\n";
        return;
    }

    if (!isValidInput(value))
        return;

    *static_cast<string*>(items[index]) = value;
}

void PyStringList::removeAt(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Error: Index out of range.\n";
        return;
    }

    delete static_cast<string*>(items[index]);

    for (int i = index; i < length - 1; i++)
        items[i] = items[i + 1];

    length--;
}

void PyStringList::clear()
{
    for (int i = 0; i < length; i++)
        delete static_cast<std::string*>(items[i]);

    length = 0;
}

int PyStringList::size() const
{
    return length;
}

bool PyStringList::isEmpty() const
{
    return length == 0;
}
