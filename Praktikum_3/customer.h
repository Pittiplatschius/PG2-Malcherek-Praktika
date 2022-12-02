#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "travel.h"

class Customer
{
private:
    long customerID;
    std::string name;

    std::vector<Travel*> travelListVec;

public:
    Customer();
    Customer(const long& pCustomerID, const std::string& pName);

    void addTravel(Travel* pTravel);
    long getCustomerID() const;
    bool checkTravel(const long& pTravelID) const;

    std::string getName() const;
    std::vector<Travel *> getTravelListVec() const;
};

#endif // CUSTOMER_H
