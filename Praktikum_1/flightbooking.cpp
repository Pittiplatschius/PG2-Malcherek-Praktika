#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}

FlightBooking::FlightBooking(const unsigned int &pId, const double &pPrice, const std::string &pFromDate, const std::string &pFromDestination,
                             const std::string &pToDestination, const std::string &pAirline) :
    fromDestination(pFromDestination),
    toDestination(pToDestination),
    airline(pAirline)
{
    Booking::setId(pId);
    Booking::setPrice(pPrice);
    Booking::setFromDate(pFromDate);
}

std::string FlightBooking::showDetails()
{
    std::string str;
    std::string id = std::to_string(Booking::getId());
    std::string price = std::to_string(Booking::getPrice());

    str.append("Flugbuchung ");
    str.append(id);
    str.append(" von ");
    str.append(fromDestination);
    str.append(" nach ");
    str.append(toDestination);
    str.append(" mit ");
    str.append(airline);
    str.append(" am ");
    str.append(getFromDate());
    str.append(". Preis: ");
    str.append(price);
    str.append(" Euro.");

    return str;
}
