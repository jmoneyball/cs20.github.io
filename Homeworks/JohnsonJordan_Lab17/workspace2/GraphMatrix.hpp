#ifndef GRAPH_MATRIX_HPP
#define GRAPH_MATRIX_HPP

#include "Graph.hpp"
#include <iostream>
using namespace std;

class GraphMatrix : public Graph {
    private:
        bool** adjMatrix;

    public:
        // constructor
        GraphMatrix(int, bool);

        // destructor
        virtual ~GraphMatrix();

        // determine if an edge exists
        virtual bool isEdge(int, int) const override;

        // print a representation of the graph
        virtual void print() const override;

        // toggle the existence of an edge
        virtual void toggleEdge(int, int) override;
};

GraphMatrix::GraphMatrix(int numV, bool dirFlag) {
    // TODO
	v = numV;
	directed = dirFlag;

	adjMatrix = new bool*[v];
	for(int i = 0; i < v; i++) {
		adjMatrix[i] = new bool[v];
		for(int j = 0; j < v; j++) {
			adjMatrix[i][j] = false;
		}
	}
}

GraphMatrix::~GraphMatrix() {
    // TODO
	for(int i = 0; i < v; i++)
		delete adjMatrix[i];
	delete[] adjMatrix;
}

bool GraphMatrix::isEdge(int i, int j) const {
    // TODO
	if(i >= v || i < 0 || j >= v || j < 0) {
		cerr << "ERROR... position you entered does not exist in the graph." << endl;
		return NULL;
	}
	else {
		if(adjMatrix[i][j] == 1)
			return true;
		else return false;
	}
}

void GraphMatrix::print() const {
    cout << "    ";
    for (int i = 0; i < v; i++) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "---";
    for (int i = 0; i < v; i++) {
        cout << "--";
    }
    cout << endl;

    for (int i = 0; i < v; i++) {
        cout << i << " | ";
        for (int j = 0; j < v; j++) {
            cout << adjMatrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void GraphMatrix::toggleEdge(int i, int j) {
    // TODO
	if(i >= v || i < 0 || j >= v || j < 0)
		cerr << "ERROR... position you entered does not exist in the graph." << endl;
	else {
		if(adjMatrix[i][j] == true) {
			adjMatrix[i][j] = false;
			e++;
		}
		else {
			adjMatrix[i][j] = true;
			e--;
		}
	}
}

#endif
