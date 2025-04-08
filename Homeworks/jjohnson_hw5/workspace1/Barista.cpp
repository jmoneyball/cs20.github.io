#include "Barista.hpp"

Barista::Barista(int i)
: id(i), startTime(0), endTime(0), totalCustomers(0), currentCustomer(nullptr)
{ }

int Barista::getId() const {
    return id;
}

int Barista::getStartTime() const {
    return startTime;
}

int Barista::getEndTime() const {
    return endTime;
}

int Barista::getTotal() const {
    return totalCustomers;
}

Customer* Barista::getCurrentCustomer() const {
    return currentCustomer;
}

void Barista::setStartTime(int s) {
    startTime = s;
}

void Barista::setEndTime(int e) {
    endTime = e;
}

void Barista::setCurrentCustomer(Customer* c) {
    currentCustomer = c;
}

void Barista::updateTotal() {
    totalCustomers++;
}
