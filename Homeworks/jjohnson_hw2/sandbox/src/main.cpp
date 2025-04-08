#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "DoublyList.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>

/*******************************************************************************
*   The Timer class below was taken from the following GitHub repository:
*       https://gist.github.com/gongzhitaao/7062087
*   All credit for this class goes to that author.
*******************************************************************************/

class Timer {
    public:
        Timer()
        : beg_(clock_::now()) {

        }

        void reset() {
            beg_ = clock_::now();
        }

        double elapsed() const { 
            return std::chrono::duration_cast<second_>
                   (clock_::now() - beg_).count();
        }

    private:
        typedef std::chrono::high_resolution_clock clock_;
        typedef std::chrono::duration<double, std::ratio<1> > second_;
        std::chrono::time_point<clock_> beg_;
};

int main() {
    // seed the random number generator using the current system time
    srand(time(0));

    // variables
    const int MAX_SIZE = 100000;
    ArrayList<int> myAL(MAX_SIZE);
    LinkedList<int> myLL;
    DoublyList<int> myDL;
    int r = 0, p = 0;
    Timer tmr;
    double elpsArray = 0.0, elpsLinked = 0.0, elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING APPEND
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE / 4; i++) {
        r = rand() % MAX_SIZE;

        tmr.reset();
        myAL.append(r);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.append(r);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.append(r);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for appending in array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for appending in singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for appending in doubly linked list: "
         << elpsDoubly << endl << endl;

    elpsArray = elpsLinked = elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING INSERT (random)
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE / 4; i++) {
        p = rand() % (MAX_SIZE / 4 + i);
        r = rand() % MAX_SIZE;

        tmr.reset();
        myAL.insert(p, r);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.insert(p, r);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.insert(p, r);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for inserting randomly in array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for inserting randomly in singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for inserting randomly in doubly linked list: "
         << elpsDoubly << endl << endl;

    elpsArray = elpsLinked = elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING INSERT (front)
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE / 4; i++) {
        r = rand() % MAX_SIZE;

        tmr.reset();
        myAL.insert(0, r);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.insert(0, r);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.insert(0, r);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for inserting to the front of array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for inserting to the front of singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for inserting to the front of doubly linked list: "
         << elpsDoubly << endl << endl;

    elpsArray = elpsLinked = elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING INSERT (back)
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE / 4; i++) {
        r = rand() % MAX_SIZE;

        tmr.reset();
        myAL.insert(myAL.getLength() - 1, r);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.insert(myLL.getLength() - 1, r);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.insert(myDL.getLength() - 1, r);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for inserting to the back of array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for inserting to the back of singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for inserting to the back of doubly linked list: "
         << elpsDoubly << endl << endl;

    elpsArray = elpsLinked = elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING REPLACE (random)
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE; i++) {
        p = rand() % MAX_SIZE;
        r = rand() % MAX_SIZE;

        tmr.reset();
        myAL.replace(p, r);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.replace(p, r);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.replace(p, r);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for replacing randomly in array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for replacing randomly in singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for replacing randomly in doubly linked list: "
         << elpsDoubly << endl << endl;

    elpsArray = elpsLinked = elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING REPLACE (front-half)
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE / 2; i++) {
        r = rand() % MAX_SIZE;

        tmr.reset();
        myAL.replace(i, r);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.replace(i, r);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.replace(i, r);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for replacing the front-half of array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for replacing the front-half of singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for replacing the front-half of doubly linked list: "
         << elpsDoubly << endl << endl;

    elpsArray = elpsLinked = elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING REPLACE (back-half)
    ***************************************************************************/

    for (int i = MAX_SIZE / 2; i < MAX_SIZE; i++) {
        r = rand() % MAX_SIZE;

        tmr.reset();
        myAL.replace(i, r);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.replace(i, r);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.replace(i, r);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for replacing the back-half of array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for replacing the back-half of singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for replacing the back-half of doubly linked list: "
         << elpsDoubly << endl << endl;

    elpsArray = elpsLinked = elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING REMOVE (random)
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE / 3; i++) {
        p = rand() % (MAX_SIZE - i);

        tmr.reset();
        myAL.remove(p);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.remove(p);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.remove(p);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for removing randomly in array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for removing randomly in singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for removing randomly in doubly linked list: "
         << elpsDoubly << endl << endl;

    elpsArray = elpsLinked = elpsDoubly = 0.0;

    /***************************************************************************
    *   TESTING REMOVE (front)
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE / 3; i++) {
        tmr.reset();
        myAL.remove(0);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.remove(0);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.remove(0);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for removing the front of array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for removing the front of singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for removing the front of doubly linked list: "
         << elpsDoubly << endl << endl;

    /***************************************************************************
    *   TESTING REMOVE (back)
    ***************************************************************************/

    for (int i = 0; i < MAX_SIZE / 3; i++) {
        tmr.reset();
        myAL.remove(myAL.getLength() - 1);
        elpsArray += tmr.elapsed();

        tmr.reset();
        myLL.remove(myLL.getLength() - 1);
        elpsLinked += tmr.elapsed();

        tmr.reset();
        myDL.remove(myDL.getLength() - 1);
        elpsDoubly += tmr.elapsed();
    }

    cout << "Elapsed time for removing the back of array-based list: "
         << elpsArray << endl;
    cout << "Elapsed time for removing the back of singly linked list: "
         << elpsLinked << endl;
    cout << "Elapsed time for removing the back of doubly linked list: "
         << elpsDoubly << endl << endl;

    // terminate
    return 0;
}
