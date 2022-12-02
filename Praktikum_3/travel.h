#ifndef TRAVEL_H
#define TRAVEL_H

#include "booking.h"

class Travel
{
private:
    long travelID;
    long customerID;

    std::vector<Booking*> travelBookingsVec;

public:
    Travel();
    Travel(const long& pTravelID, const long& pCustomerID);

    void addBooking(Booking* pBooking);
    long getTravelID() const;
    bool checkBooking(const long& pBbookingID) const;
    std::vector<Booking *> getTravelBookingsVec() const;
};

#endif // TRAVEL_H
