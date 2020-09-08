#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <iostream>
#include <string>

#include "StringNode.h"

using namespace std;

class InvalidPositionException { };

class StringList {
    public:
        StringList();
        ~StringList();

        // Clear contents from the list, to make it empty.
        // Worst-case time complexity: Linear
        void clear();

        // Insert an element at the current location.
        // item: The element to be inserted
        // Worst-case time complexity: Constant
        void insert(const string& item);

        // Append an element at the end of the list.
        // item: The element to be appended.
        // Worst-case time complexity: Constant
        void append(const string& item);

        // Remove and return the current element.
        // Return: the element that was removed.
        // Worst-case time complexity: Constant
        // Throws InvalidPositionException if current position is
        // behind the last element
        string remove();

        // Set the current position to the start of the list
        // Worst-case time complexity: Constant
        void move_to_start();

        // Set the current position to the end of the list
        // Worst-case time complexity: Constant
        void move_to_end();

        // Move the current position one step left. No change
        // if already at beginning.
        // Worst-case time complexity: Constant
        void prev();

        // Move the current position one step right. No change
        // if already at end.
        // Worst-case time complexity: Constant
        void next();

        // Return: The number of elements in the list.
        // Worst-case time complexity: Constant
        int length() const;

        // Return: The position of the current element.
        // Worst-case time complexity: Constant
        int curr_pos() const;

        // Set current position.
        // pos: The position to make current.
        // Worst-case time complexity: Linear
        // Throws InvalidPositionException if 'pos' is not a valid position
        void move_to_pos(int pos);

        // Return: The current element.
        // Worst-case time complexity: Constant
        // Throws InvalidPositionException if current position is
        // behind the last element
        const string& get_value() const;


        // Outputs the elements of 'lis' to the stream 'outs', separated
        // by a single space.
        friend ostream& operator <<(ostream& outs, const StringList& lis);


    private:
        NodePtr head;
        NodePtr tail;

        NodePtr currPosPointer;
        int currPosInt;

        int size;
};


#endif // INTLIST_H
