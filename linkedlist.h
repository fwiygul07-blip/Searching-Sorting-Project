#include <iostream>

// random number
// used for: shuffle
#include <ctime>
#include <cstdlib>

// Node structure
#include "node.h"

using std::cout;
using std::endl;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
    private:
        Node *head, *tail;
        int size;

    public:
        // constructor and destructor
        LinkedList();
        ~LinkedList();

        // display, add, and pop functions
        void display();
        
        void append(int number);
        
        void pop();

        // shows: selection sort
        void sort();

        void shuffle();

        int binarySearch(int number);
        
        void reverseSort();     

        void removeValues(int number);

        void differentSort();
};

#endif // LINKEDLIST_H
