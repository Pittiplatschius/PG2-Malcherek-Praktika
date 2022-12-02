#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "booking.h"

class FlightBooking : virtual public Booking
{
private:
    std::string fromDestination, toDestination, airline;

public:
    FlightBooking();
    FlightBooking(const unsigned int &pId, const double &pPrice, const std::string &pFromDate, const std::string &pFromDestination,
                  const std::string &pToDestination, const std::string &pAirline);

    std::string showDetails() override;
};

#endif // FLIGHTBOOKING_H
