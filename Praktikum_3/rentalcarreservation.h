#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include "booking.h"

class RentalCarReservation : virtual public Booking
{
private:
    std::string pickupLocation, returnLocation, company;

public:
    RentalCarReservation();
    RentalCarReservation(const long &pBooking_ID, const long &pTravelID, const double &pPrice, const std::string &pFromDate, const std::string &pToDate,
                         const std::string &pPickpupLocation, const std::string &pReturnLocation, const std::string &pCompany);

    QString showDetails() override;

    const std::string &getPickupLocation() const;
    const std::string &getReturnLocation() const;
    const std::string &getCompany() const;
};

#endif // RENTALCARRESERVATION_H
