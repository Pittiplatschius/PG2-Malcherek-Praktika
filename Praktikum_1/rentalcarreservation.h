#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include "booking.h"

class RentalCarReservation : virtual public Booking
{
private:
    std::string pickupLocation, returnLocation, company;

public:
    RentalCarReservation();
    RentalCarReservation(const unsigned int &pId, const double &pPrice, const std::string &pFromDate, const std::string &pToDate,
                         const std::string &pPickpupLocation, const std::string &pReturnLocation, const std::string &pCompany);

    std::string showDetails() override;
};

#endif // RENTALCARRESERVATION_H
