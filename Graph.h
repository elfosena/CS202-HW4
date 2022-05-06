#include "LinkedList.h"
#include <sstream>

class Graph {
    public:
    Graph(int size);
    ~Graph();

    bool insert(int a1, int a2, int dur);
    void list(int u);
    void shortestPath(int s, int t);
    void minimizeCosts();

    private:
    string toString(int x);
    int getTotalCost();
    LinkedList* lists;
    int size;
};