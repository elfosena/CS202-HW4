#include "Graph.h"
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "Error! You have to enter file name." << endl;
    }
    else {
        string filename = argv[1];
        ifstream infile;
        infile.open((filename).c_str());

        if (!infile) {
            cout << "Error! Cannot open file." << endl;
        }
        else {
            int airportcount;
            int opcount;
            char op;

            infile >> airportcount;
            infile >> opcount;
            Graph flightmap = Graph(airportcount);

            for (int i = 0; i < opcount; i++) {
                infile >> op;

                if (op == 'I') {
                    int u, v, w;
                    infile >> u;
                    infile >> v;
                    infile >> w;
                    flightmap.insert(u, v, w);
                }
                else if (op == 'L') {
                    int u;
                    infile >> u;
                    flightmap.list(u);
                }
                else if (op == 'S') {
                    int s, t;
                    infile >> s;
                    infile >> t;
                    flightmap.shortestPath(s, t);
                }
                else if (op == 'M') {
                    flightmap.minimizeCosts();
                }
            }
        }
    }
    

    return 0;
}