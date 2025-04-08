#include "LinkedList.hpp"
#include <string>

int main() {
    LinkedList<string> myList;

    myList.append("Heart");
    myList.insert(0, "Your");
    myList.insert(0, "May");
    myList.append("Citrus");
    myList.insert(5, "kweh"); // should display error
    myList.remove(3);
    cout << myList;
    myList.append("Beat");
    cout << myList;
    myList.remove(4); // should display error
    myList.clear();
    cout << myList;

    return 0;
}
