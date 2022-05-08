/*
* Title: CS202 Spring 2022
* Author: Elifsena Öz
* ID: 22002245
* Section: 1
* Assignment: 4
* Description: Graph header file
*/

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