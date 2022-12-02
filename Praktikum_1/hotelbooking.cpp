#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}

HotelBooking::HotelBooking(const unsigned int &pId, const double &pPrice, const std::string &pFromDate, const std::string &pToDate,
                           const std::string &pHotel, const std::string &pTown) :
    hotel(pHotel),
    town(pTown)
{
    Booking::setId(pId);
    Booking::setPrice(pPrice);
    Booking::setFromDate(pFromDate);
    Booking::setToDate(pToDate);
}

std::string HotelBooking::showDetails()
{
    std::string str;
    std::string id = std::to_string(Booking::getId());
    std::string price = std::to_string(Booking::getPrice());

    str.append("Hotelreservierung ");
    str.append(id);
    str.append(" im ");
    str.append(hotel);
    str.append(" in ");
    str.append(town);
    str.append(" vom ");
    str.append(getFromDate());
    str.append(" bis zum ");
    str.append(getToDate());
    str.append(". Preis: ");
    str.append(price);
    str.append(" Euro.");

    return str;
}

