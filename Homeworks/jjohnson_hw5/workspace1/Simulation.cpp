#include "Simulation.hpp"
#include <ctime>

Simulation::Simulation(int e, int c) {
	epochs = e;
	custQ = new ArrayQueue<Customer*>(c);
	bari1 = new Barista(1);
	bari2 = new Barista(2);
	avgWaitTime = 0;

}

Simulation::~Simulation() {
	//deletes individual pointers in the array queue
	custQ->clear();
	//deletes pointer to the array queue
	delete custQ;
	//deletes barista objects
	delete bari1;
	delete bari2;
}

void Simulation::help(Barista *b, int ct) {
	//declarations
	int minVal = 5, maxVal = 10;
	int randNum = minVal + rand() % (maxVal - minVal + 1);

	//assign the customer to the barista and remove it from the queue
	b->setCurrentCustomer(custQ->front());
	custQ->dequeue();

	//set the start/end times for the customer
	b->setStartTime(ct);
	b->setEndTime(ct + randNum);

	//output message
	cout << "Barista #" << b->getId() << " is helping customer #" << b->getCurrentCustomer()->getId() << " at time " << ct << endl;
}

void Simulation::finish(Barista *b, int ct) {
	//update total customers helped
	b->updateTotal();

	//add total time to average
	avgWaitTime += (ct - b->getCurrentCustomer()->getStartTime());

	//output message
	cout << "Customer #" << b->getCurrentCustomer()->getId() << " finished at time " << ct << endl;

	//delete the customer object
	delete b->getCurrentCustomer();
	b->setCurrentCustomer(nullptr);

}

void Simulation::run() {
	//declarations
	srand(time(0));
	int id = 1;
	int minVal = 1, maxVal = 100;

	//runs simulation for "epochs" amount of time
	for(int i = 1; i <= epochs; i++) {
		cout << "\n\n=== " << i << " === \n";

		//generates a random number
		int randNum = minVal + rand() % (maxVal - minVal + 1);
		//30% chance to create a customer if the queue isn't full
		if(randNum <= 30 && !custQ->isFull()) {
			Customer* newCust = new Customer(id, i);
			custQ->enqueue(newCust);
			cout << "Customer #" << id << " entered the queue at time " << i << endl;
			id++;
		}

		//baristas finish helping customers if their time is up
		if(bari1->getEndTime() == i)
			finish(bari1, i);
		if(bari2->getEndTime() == i)
			finish(bari2, i);

		//if the queue is empty, try to generate a new customer
		if(custQ->isEmpty())
			continue;
		//if it isn't empty, try to help a new customer
		else {
			if(bari1->getCurrentCustomer() == nullptr && !custQ->isEmpty())
				help(bari1, i);
			if(bari2->getCurrentCustomer() == nullptr && !custQ->isEmpty())
				help(bari2, i);
		}
}
	//simulation data
	cout << "\nSIMULATION FINISHED!\n";
	cout << "Barista #1 helped " << bari1->getTotal() << " customers.\n";
	cout << "Barista #2 helped " << bari2->getTotal() << " customers.\n";
	cout << "Average wait time for a customer: " << avgWaitTime / (bari1->getTotal() + bari2->getTotal());
}
