#include "StringList.h"

using namespace std;


//Constructor
StringList::StringList()
{
    head = new StringNode("head - You shouldn't be here", NULL, NULL);
    tail = new StringNode("tail - You shouldn't be here", NULL, head);

    head->next = tail;
    currPosPointer = tail;

    currPosInt = 0;
    size = 0;
}

//Destructor
StringList::~StringList()
{
    clear();

    delete head;
    delete tail;
}

void StringList::clear()
{
    NodePtr nodeToClear = head->next;
    NodePtr temp = NULL;

    while(nodeToClear != tail)
    {
        temp = nodeToClear;
        nodeToClear = nodeToClear->next;
        delete temp;
    }

    head->next = tail;
    tail->prev = head;

    currPosPointer = tail;
    currPosInt = 0;

    size = 0;
}

void StringList::insert(const string& item)
{
    NodePtr nodeToInsert = new StringNode(item, currPosPointer, currPosPointer->prev);

    currPosPointer->prev->next = nodeToInsert;
    currPosPointer->prev = nodeToInsert;

    currPosPointer = nodeToInsert;

    size++;
}

void StringList::append(const string& item)
{
    NodePtr nodeToAppend = new StringNode();
    nodeToAppend->data = item;

    if (head->next == tail)
    {
        nodeToAppend->next =  tail;
        nodeToAppend->prev = head;

        head->next = nodeToAppend;
        currPosPointer = head->next;
    }
    else
    {
        nodeToAppend->next = tail;
        nodeToAppend->prev = tail->prev;
        tail->prev->next = nodeToAppend;
    }

    if(currPosInt == size)
    {
        currPosPointer = nodeToAppend;
    }

    tail->prev = nodeToAppend;

    size++;
}

string StringList::remove()
{
    if(head->next == tail || currPosInt > size - 1)
    {
        throw InvalidPositionException();
    }

    string stringToReturn;
    stringToReturn = currPosPointer->data;

    NodePtr nodeToRemove = currPosPointer;

    currPosPointer = currPosPointer->next;

    nodeToRemove->next->prev = nodeToRemove->prev;
    nodeToRemove->prev->next = nodeToRemove->next;

    delete nodeToRemove;

    size--;

    return stringToReturn;
}


void StringList::move_to_start()
{
    currPosPointer = head->next;
    currPosInt = 0;
}

void StringList::move_to_end()
{
    currPosPointer = tail;              
    currPosInt = size;                 
}

void StringList::prev()
{
    if(currPosInt == 0 || head->next == tail)
    {
        return;
    }

    currPosPointer = currPosPointer->prev;
    currPosInt--;
}

void StringList::next()
{
    if(currPosInt == size || head->next == tail)
    {
        return;
    }

    currPosPointer = currPosPointer->next;
    currPosInt++;
}

int StringList::length() const
{
    return size;
}

int StringList::curr_pos() const
{
    return currPosInt;
}

void StringList::move_to_pos(int pos)
{
    if(pos < 0 || pos > size)
    {
        throw InvalidPositionException();
    }

    currPosInt = 0;
    currPosPointer = head->next;

    for(int i = currPosInt; i < pos; i++)
    {
        next();
    }
}

const string& StringList::get_value() const
{
    if(currPosPointer == tail)
    {
        throw InvalidPositionException();
    }

    return currPosPointer->data;
}


ostream& operator <<(ostream& outs, const StringList& lis)
{
    NodePtr nodeToPrint = lis.head->next;

    while(nodeToPrint != lis.tail)
    {
        outs << nodeToPrint->data << " ";
        nodeToPrint = nodeToPrint->next;
    }

    return outs;
}
