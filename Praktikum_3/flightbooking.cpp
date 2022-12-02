#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}

FlightBooking::FlightBooking(const long &pBooking_ID, const long &pTravelID, const double &pPrice, const std::string &pFromDate,
                             const std::string &pFromDestination, const std::string &pToDestination, const std::string &pAirline) :
    fromDestination(pFromDestination),
    toDestination(pToDestination),
    airline(pAirline)
{
    Booking::setBookingType(Flight);
    Booking::setbookingID(pBooking_ID);
    Booking::setTravelID(pTravelID);
    Booking::setPrice(pPrice);
    Booking::setQFromDate(pFromDate);
}

QString FlightBooking::showDetails()
{
    QString qstr;
    std::string str;
    std::string id = std::to_string(getBookingID());
    std::string price = std::to_string(getPrice());
    std::string fromDate = getQFromDate().toString().toStdString();

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
    str.append(fromDate);
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
