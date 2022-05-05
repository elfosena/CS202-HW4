#include "LinkedList.h"

class Graph {
    public:
    Graph(int size);
    ~Graph();

    bool insert(int a1, int a2, int dur);
    void list(int u);

    private:
    LinkedList* lists;
    int size;
};