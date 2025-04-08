#ifndef BARISTA_HPP
#define BARISTA_HPP

#include "Customer.hpp"

class Barista {
    private:
        int id;
        int startTime;
        int endTime;
        int totalCustomers;
        Customer* currentCustomer;

    public:
        Barista(int);

        int getId() const;
        int getStartTime() const;
        int getEndTime() const;
        int getTotal() const;
        Customer* getCurrentCustomer() const;

        void setStartTime(int);
        void setEndTime(int);
        void setCurrentCustomer(Customer*);

        void updateTotal();
};

#endif
