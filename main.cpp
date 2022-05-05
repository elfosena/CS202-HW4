#include "LinkedList.h"

int main() {

    LinkedList list;

    list.display();

    cout << list.insert( 'A', 5) << endl;
    cout << list.insert( 'Z', 3) << endl;
    cout << list.insert( 'S', 3) << endl;
    cout << list.insert( 'Z', 7) << endl;
    cout << list.insert( 'M', 3) << endl;

    cout << list.remove( 'A', 5) << endl;
    cout << list.remove( 'Z', 3) << endl;
    cout << list.remove( 'S', 3) << endl;
    cout << list.remove( 'Z', 7) << endl;
    cout << list.remove( 'M', 3) << endl;

    list.display();

    return 0;
}