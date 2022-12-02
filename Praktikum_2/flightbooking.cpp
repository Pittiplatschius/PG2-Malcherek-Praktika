#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}

FlightBooking::FlightBooking(const int &pId, const double &pPrice, const std::string &pFromDate,
                             const std::string &pFromDestination, const std::string &pToDestination, const std::string &pAirline) :
    fromDestination(pFromDestination),
    toDestination(pToDestination),
    airline(pAirline)
{
    Booking::setBookingType(Flight);
    Booking::setId(pId);
    Booking::setPrice(pPrice);
    Booking::setFromDate(pFromDate);
}

QString FlightBooking::showDetails()
{
    QString qstr;
    std::string str;
    std::string id = std::to_string(getId());
    std::string price = std::to_string(getPrice());
    price.erase(price.size() - 4);

    str.append("ID: ");
    str.append(id);
    str.append(" - Flugbuchung von ");
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

    qstr = QString::fromStdString(str);

    return qstr;
}

const std::string &FlightBooking::getFromDestination() const
{
    return fromDestination;
}

const std::string &FlightBooking::getToDestination() const
{
    return toDestination;
}

const std::string &FlightBooking::getAirline() const
{
    return airline;
}
