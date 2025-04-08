#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

class Customer {
    private:
        int id;
        int startTime;

    public:
        Customer(int = -1, int = -1);

        int getId() const;
        int getStartTime() const;
};

#endif
