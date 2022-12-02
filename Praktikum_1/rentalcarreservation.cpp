#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::RentalCarReservation(const unsigned int &pId, const double &pPrice, const std::string &pFromDate, const std::string &pToDate,
                                           const std::string &pPickpupLocation, const std::string &pReturnLocation, const std::string &pCompany) :
    pickupLocation(pPickpupLocation),
    returnLocation(pReturnLocation),
    company(pCompany)
{
    Booking::setId(pId);
    Booking::setPrice(pPrice);
    Booking::setFromDate(pFromDate);
    Booking::setToDate(pToDate);
}

std::string RentalCarReservation::showDetails()
{
    std::string str;
    std::string id = std::to_string(getId());
    std::string price = std::to_string(getPrice());

    str.append("Mietwagenreservierung ");
    str.append(id);
    str.append(" mit ");
    str.append(company);
    str.append(". Abholung am ");
    str.append(getFromDate());
    str.append(" in ");
    str.append(pickupLocation);
    str.append(". Rueckgabe am ");
    str.append(getToDate());
    str.append(" in ");
    str.append(returnLocation);
    str.append(". Preis: ");
    str.append(price);
    str.append(" Euro.");

    return str;
}
