#include <iostream>
using namespace std;

class LinkedList {

    public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, int dest, int dur) const;
    bool insert(int dest, int dur);
    bool remove(int dest, int dur);
    void display();

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