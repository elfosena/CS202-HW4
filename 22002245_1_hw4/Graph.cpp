/*
* Title: CS202 Spring 2022
* Author: Elifsena Öz
* ID: 22002245
* Section: 1
* Assignment: 4
* Description: Graph cpp file
*/

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
        cout << "   " << "The number of flights from " << u << " is " << lists[u].getLength() << "." << endl;
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
            cout << "   " << u << " to " << destination << " with a duration of " << duration << "." << endl;
        }

        cout << "The number of flights is " << lists[u].getLength() << "." << endl;
    }
}

void Graph::shortestPath(int s, int t) {
    int* duration = new int[size];
    int* visited = new int[size];
    int* prev = new int[size];
    int dest;
    int dur;

    for (int i = 0; i < size; i++) {
        duration[i] = 0;
        visited[i] = 0;
        prev[i] = 0;
    }

    // Step 1
    visited[s] = 1;
    for (int i = 0; i < size; i++) {
        duration[i] = 2147483647;
        for (int j = 1; j <= lists[s].getLength(); j++) {
            lists[s].retrieve(j, dest, dur);
            if (dest == i) {
                duration[i] = dur;
                prev[i] = s;
                break;
            }
        }
    }

    // Step 2 to n
    for (int j = 1; j < size; j++) {
        int minIndex = 0;
        for (int i = 0; i < size; i++) {
            if ((duration[i] < duration[minIndex] && visited[i] == 0) || visited[minIndex] == 1) {
                minIndex = i;
            }
        }

        visited[minIndex] = 1;
    
        for (int i = 1; i <= lists[minIndex].getLength(); i++) {
            lists[minIndex].retrieve(i, dest, dur);

            if (duration[dest] > duration[minIndex] + dur && visited[dest] == 0) {
                duration[dest] = duration[minIndex] + dur;
                prev[dest] = minIndex;
            }
        }
    }

    // Print Result

    if (duration[t] == 2147483647) {
        cout << "No paths from " << s << " to " << t << endl;
    }
    else {
        string result;
        
        cout << "Shortest path from " << s << " to " << t << endl;
        for (int j = t; j != s; j = prev[j]) {
            result = "  " + toString(prev[j]) + " to " + toString(j) + " with a duration " + 
                    toString(lists[prev[j]].getDuration(j)) + "\n" + result;
        }
        cout << result;
        cout << "Total flight duration of path: " << duration[t] << endl;
    }

    delete [] duration;
    delete [] visited;
    delete [] prev;
}

void Graph::minimizeCosts() {

    cout << "Total cost of operations before minimization: " << getTotalCost() << endl;
    LinkedList* spanningtree = new LinkedList[size];
    int* visited = new int[size];
    int visitcount = 0;
    
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
    
    visited[0] = 1;
    
    while (visitcount < size) {
        int min = lists[0].getMinDuration();
        int dest;
        int vis = 0;

        for (int i = 0; i < size; i++) {
            if ((lists[i].getMinDuration() < min && visited[i] == 0) || visited[vis] == 1) {
                min = lists[i].getMinDuration();
                dest = lists[i].getMinDest();
                vis = i;
            }
        }
        
        spanningtree[vis].insert(dest, min);
        spanningtree[dest].insert(vis, min);
        visited[vis] = 1;
        visitcount++;
    }

    delete [] lists;
    delete [] visited;
    lists = spanningtree;
    cout << "Total cost of operations after minimization: " << getTotalCost() << endl;

}

int Graph::getTotalCost() {
    int totalcost = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j <= lists[i].getLength(); j++) {
            int dest;
            int dur;

            lists[i].retrieve(j, dest, dur);
            totalcost += dur;
        }
    }
    return totalcost / 2;
}

string Graph::toString(int x) {
    stringstream ss;
    string result;
    ss << x;
    ss >> result;
    return result;
}