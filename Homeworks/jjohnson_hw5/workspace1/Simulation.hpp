#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "ArrayQueue.hpp"
#include "Barista.hpp"

class Simulation {
    private:
		ArrayQueue<Customer*> *custQ;
		Barista *bari1;
		Barista *bari2;
		int epochs;
		double avgWaitTime;
    public:
		Simulation(int, int);
		~Simulation();

		void run();
		void finish(Barista*, int);
		void help(Barista*, int);
};
#endif
