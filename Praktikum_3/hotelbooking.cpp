#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}

HotelBooking::HotelBooking(const long &pBooking_ID, const long &pTravelID, const double &pPrice, const std::string &pFromDate,
                           const std::string &pToDate, const std::string &pHotel, const std::string &pTown) :
    hotel(pHotel),
    town(pTown)
{
    Booking::setBookingType(Hotel);
    Booking::setbookingID(pBooking_ID);
    Booking::setTravelID(pTravelID);
    Booking::setPrice(pPrice);
    Booking::setQFromDate(pFromDate);
    Booking::setQToDate(pToDate);
}

QString HotelBooking::showDetails()
{
    QString qstr;
    std::string str;
    std::string id = std::to_string(getBookingID());
    std::string price = std::to_string(getPrice());
    std::string fromDate = getQFromDate().toString().toStdString();
    std::string toDate = getQFromDate().toString().toStdString();

    price.erase(price.size() - 4);

    str.append("ID: ");
    str.append(id);
    str.append(" - Hotelreservierung im ");
    str.append(hotel);
    str.append(" in ");
    str.append(town);
    str.append(" vom ");
    str.append(fromDate);
    str.append(" bis zum ");
    str.append(toDate);
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
