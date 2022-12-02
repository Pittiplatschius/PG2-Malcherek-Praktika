#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}

HotelBooking::HotelBooking(const int &pId, const double &pPrice, const std::string &pFromDate, const std::string &pToDate,
                           const std::string &pHotel, const std::string &pTown) :
    hotel(pHotel),
    town(pTown)
{
    Booking::setBookingType(Hotel);
    Booking::setId(pId);
    Booking::setPrice(pPrice);
    Booking::setFromDate(pFromDate);
    Booking::setToDate(pToDate);
}

QString HotelBooking::showDetails()
{
    QString qstr;
    std::string str;
    std::string id = std::to_string(getId());
    std::string price = std::to_string(getPrice());

    //QDate qdate;



    price.erase(price.size() - 4);

    str.append("ID: ");
    str.append(id);
    str.append(" - Hotelreservierung im ");
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

    qstr = QString::fromStdString(str);

    return qstr;
}

const std::string &HotelBooking::getHotel() const
{
    return hotel;
}

const std::string &HotelBooking::getTown() const
{
    return town;
}
