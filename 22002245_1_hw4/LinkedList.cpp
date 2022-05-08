/*
* Title: CS202 Spring 2022
* Author: Elifsena Öz
* ID: 22002245
* Section: 1
* Assignment: 4
* Description: Linked List cpp file
*/

#include "LinkedList.h"

LinkedList::LinkedList() : size(0) , head(NULL) {}

LinkedList::~LinkedList(){
    while (!isEmpty())
        remove(head->destination, head->duration);
} 

bool LinkedList::isEmpty() const{
   if (size == 0) {
       return true;
   }
   return false;
}  

int LinkedList::getLength() const{
    return size;
}  

LinkedList::Node* LinkedList::find(int index) const{
    if ( (index >= 1) && (index <= getLength()) ) {
        Node *cur = head;
        for (int i = 1; i < index; ++i)
            cur = cur->next;
        return cur;
    }
    return NULL;
} 

bool LinkedList::retrieve(int index, int& dest, int& dur) const {
    if ((index >= 1) && (index <= getLength())) {
        Node *cur = find(index);
        dest = cur->destination;
        dur = cur->duration;
        return true;
    }
    return false;
} 


bool LinkedList::insert(int dest, int dur) {
    Node *newPtr = new Node;
    newPtr->destination = dest;
    newPtr->duration = dur;
    newPtr->next = NULL;
    size++;

    if (head == NULL) {
        head = newPtr;
        return true;
    }

    Node* cur = head;

    for (int index = 1; index < size; ++index) {
        if (cur->destination > newPtr->destination || 
            (cur->destination == newPtr->destination && cur->duration > newPtr->duration)) {
            if (index == 1) {
                newPtr->next = head;
                head = newPtr;
            }
            else {
                Node *prev = find(index-1);
                newPtr->next = prev->next;
                prev->next = newPtr;
            }
            return true;
        }
        if (cur->next == NULL) {
            cur->next = newPtr;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool LinkedList::remove(int dest, int dur) {

    Node* cur = head;
    for (int index = 1; index <= size; ++index) {
        if (cur->destination == dest && cur->duration == dur) {
            if (index == 1) {
                cur = head;  
                head = head->next;
            }
            else {
                Node *prev = find(index-1);
                cur = prev->next;
                prev->next = cur->next;
            }
            --size;
            index++;
            cur->next = NULL;
            delete cur;
            cur = NULL;
            return true;
        }
        cur = cur->next;
    }
   
    return false;
}  

void LinkedList::display() {
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        cout << "- " << cur->destination << " " << cur->duration << endl << " ";
    }
}

int LinkedList::getDuration(int dest) {
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        if (cur->destination == dest) {
            return cur->duration;
        }
    }
    return -2;
}

int LinkedList::getMinDuration() const {
    int min = 2147483647;
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        if (cur->duration <= min) {
            min = cur->duration;
        }
    }
    return min;
}

int LinkedList::getMinDest() {
    int min = 2147483647;
    int dest;
    Node* cur = head;
    for (; cur != NULL; cur = cur->next) {
        if (cur->duration <= min) {
            min = cur->duration;
            dest = cur->destination;
        }
    }
    return dest;
}