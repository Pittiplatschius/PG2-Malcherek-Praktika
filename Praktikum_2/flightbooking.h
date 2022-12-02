#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "booking.h"

class FlightBooking : virtual public Booking
{
private:
    std::string fromDestination, toDestination, airline;

public:
    FlightBooking();
    FlightBooking(const int &pId, const double &pPrice, const std::string &pFromDate,
                  const std::string &pFromDestination, const std::string &pToDestination, const std::string &pAirline);

    QString showDetails() override;

    //QDate formatDate(std::string& date);
    const std::string &getFromDestination() const;
    const std::string &getToDestination() const;
    const std::string &getAirline() const;
};

#endif // FLIGHTBOOKING_H
