#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include "booking.h"

class HotelBooking : virtual public Booking
{
private:
    std::string hotel, town;

public:
    HotelBooking();
    HotelBooking(const unsigned int &pId, const double &pPrice, const std::string &pFromDate, const std::string &pToDate,
                 const std::string &pHotel, const std::string &pTown);

    std::string showDetails() override;
};

#endif // HOTELBOOKING_H
