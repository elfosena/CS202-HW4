#include "Graph.h"

Graph::Graph(int size) {
    this->size = size;
    lists = new LinkedList[size];
}

Graph::~Graph() {
    delete [] lists;
}

bool Graph::insert(int u, int v, int w) {
    if (u < size && v < size) {
        lists[u].insert(v, w);
        lists[v].insert(u, w);
        
        cout << "Inserted a new flight between " << u << " and " << v << "." << endl;
        cout << "The number of flights from " << u << " is " << lists[u].getLength() << "." << endl;
        return true;
    }
    return false;
}

void Graph::list(int u) {
    if (lists[u].getLength() == 0) {
        cout << "No flights from " << u << endl;
    }
    else {
        cout << "List of flights from " << u << ":" << endl;

        for (int i = 1; i <= lists[u].getLength(); i++) {
            int destination;
            int duration;

            lists[u].retrieve(i, destination, duration);
            cout << u << " to " << destination << " with a duration of " << duration << "." << endl;
        }

        cout << "The number of flights is " << lists[u].getLength() << "." << endl;
    }
}