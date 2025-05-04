// ListsKursova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


struct elem 
{
    int key;
    elem* next;
}*start1 = nullptr, *start2 = nullptr;


void pushBack(elem*& start, int n) {

    elem* newElem = new elem;

    newElem->key = n;

    newElem->next = nullptr;

    if (!start) {
        start = newElem;
        return;
    }

    elem* p = start;

    while (p->next) {
        p = p->next;
    }

    p->next = newElem;
}

bool exists(elem* list, int val) {
    while (list) {

        if (list->key == val) 
            return true;

        list = list->next;
    }
    return false;
}

elem* symmetricDifference(elem* a, elem* b) {

    elem* result = nullptr;

    while (a) {
        if (!exists(b, a->key) && !exists(result, a->key)) {
            pushBack(result, a->key);
        }
        a = a->next;
    }

    while (b) {
        if (!exists(start1, b->key) && !exists(result, b->key)) {
            pushBack(result, b->key);
        }
        b = b->next;
    }

    return result;
}

void print(elem* start) {

    while (start) {
        cout << start->key << " ";
        start = start->next;
    }
    cout << endl;
}


int main()
{
  
    pushBack(start1, 3);
    pushBack(start1, 2);
    pushBack(start1, 1);

    pushBack(start2, 5);
    pushBack(start2, 4);
    pushBack(start2, 3);

    cout << "List 1: ";
    print(start1);
    cout << "List 2: ";
    print(start2);

    elem* result = symmetricDifference(start1, start2);

    cout << "Symmetric Difference: ";
    print(result);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
