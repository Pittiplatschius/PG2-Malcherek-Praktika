#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include "booking.h"

class HotelBooking : virtual public Booking
{
private:
    std::string hotel, town;

public:
    HotelBooking();
    HotelBooking(const int &pId, const double &pPrice, const std::string &pFromDate,
                 const std::string &pToDate, const std::string &pHotel, const std::string &pTown);

    QString showDetails() override;

    const std::string &getHotel() const;
    const std::string &getTown() const;
};

#endif // HOTELBOOKING_H
