#include "customer.h"

Customer::Customer()
{

}

Customer::Customer(const long &pCustomerID, const std::string &pName) :
    customerID(pCustomerID),
    name(pName)
{

}

void Customer::addTravel(Travel *pTravel)
{
    travelListVec.push_back(pTravel);
}

long Customer::getCustomerID() const
{
    return customerID;
}

bool Customer::checkTravel(const long &pTravelID) const
{
    for (auto &k : travelListVec) {
        if (k->getTravelID() == pTravelID) {
            return true;
        }
    }
    return false;
}

std::string Customer::getName() const
{
    return name;
}

std::vector<Travel *> Customer::getTravelListVec() const
{
    return travelListVec;
}
