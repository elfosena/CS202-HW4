#include <iostream>
using namespace std;

class LinkedList {

    public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, char dest, int dur) const;
    bool insert(char dest, int dur);
    bool remove(char dest, int dur);
    void display();

    private:

    struct Node{
        char destination;
        int duration;
        Node *next;
    }; 

    Node* find(int index) const;

    int size;
    Node* head;

};