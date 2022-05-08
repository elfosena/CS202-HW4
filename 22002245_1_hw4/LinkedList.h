/*
* Title: CS202 Spring 2022
* Author: Elifsena Öz
* ID: 22002245
* Section: 1
* Assignment: 4
* Description: Linked List header file
*/

#include <iostream>
using namespace std;

class LinkedList {

    public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    int getMinDuration() const;
    int getMinDest();
    bool retrieve(int index, int& dest, int& dur) const;
    bool insert(int dest, int dur);
    bool remove(int dest, int dur);
    void display();
    int getDuration(int dest);

    private:

    struct Node{
        int destination;
        int duration;
        Node *next;
    }; 

    Node* find(int index) const;

    int size;
    Node* head;

};