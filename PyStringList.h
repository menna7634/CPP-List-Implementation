#ifndef PYSTRINGLIST_H
#define PYSTRINGLIST_H

#include <string>
using namespace std;

class PyStringList
{
private:
    void** items;     
    int capacity;      
    int length;       

private:
    void resize();
    bool isValidInput(const string& s);

public:
    PyStringList(int initialCapacity = 4);
    ~PyStringList();

    void append(const string& value);
    string get(int index) const;
    void set(int index, const string& value);
    void removeAt(int index);
    void clear();

    int size() const;
    bool isEmpty() const;
};

#endif
