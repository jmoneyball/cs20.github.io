#ifndef GRAPH_LIST_HPP
#define GRAPH_LIST_HPP

#include "Graph.hpp"
#include "LinkedList.hpp"
#include <iostream>
using namespace std;

class GraphList : public Graph {
    private:
        LinkedList<int>** adjList;

    public:
        // constructor
        GraphList(int, bool);

        // destructor
        virtual ~GraphList();

        // determine if an edge exists
        virtual bool isEdge(int, int) const override;

        // print a representation of the graph
        virtual void print() const override;

        // toggle the existence of an edge
        virtual void toggleEdge(int, int) override;
};

GraphList::GraphList(int numV, bool dirFlag) {
    // TODO
	v = numV;
	directed = dirFlag;
	adjList = new LinkedList<int>*[v];
	for(int i = 0; i < v; i++)
		adjList[i] = new LinkedList<int>;
}

GraphList::~GraphList() {
    // TODO
	for(int i = 0; i < v; i++)
		delete adjList[i];
	delete[] adjList;
}

bool GraphList::isEdge(int i, int j) const {
    // TODO
	if(i >= v || i < 0 || j >= v || j < 0) {
		cerr << "ERROR... position you entered does not exist in the graph." << endl;
		return NULL;
		}
	else {
		if(adjList[i]->getElement(j) == i)
			return true;
		else return false;
	}
}

void GraphList::print() const {
    for (int i = 0; i < v; i++) {
        cout << i << " | ";
        for (int j = 0; j < adjList[i]->getLength(); j++) {
            cout << adjList[i]->getElement(j);

            if (j != adjList[i]->getLength() - 1) {
                cout << " --> ";
            }
        }
        cout << endl;
    }
}

void GraphList::toggleEdge(int i, int j) {
    // TODO
	if(i >= v || i < 0 || j >= v || j < 0)
		cerr << "ERROR... position you entered does not exist in the graph." << endl;
	else {
			adjList[i]->append(j);
			adjList[j]->append(i);
			e++;
	}
}

#endif
