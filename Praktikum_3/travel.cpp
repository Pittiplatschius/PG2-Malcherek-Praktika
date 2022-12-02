#include "travel.h"

Travel::Travel()
{

}

Travel::Travel(const long &pTravelID, const long &pCustomerID) :
    travelID(pTravelID),
    customerID(pCustomerID)
{

}

void Travel::addBooking(Booking *pBooking)
{
    travelBookingsVec.push_back(pBooking);
}

long Travel::getTravelID() const
{
    return travelID;
}

bool Travel::checkBooking(const long &pBbookingID) const
{
    for (auto &k : travelBookingsVec) {
        if (k->getBookingID() == pBbookingID) {
            return true;
        }
    }
    return false;
}

std::vector<Booking *> Travel::getTravelBookingsVec() const
{
    return travelBookingsVec;
}
