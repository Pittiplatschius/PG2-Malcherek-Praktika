#include "booking.h"

Booking::Booking()
{

}

long Booking::getBookingID() const
{
    return booking_ID;
}

void Booking::setbookingID(int newId)
{
    booking_ID = newId;
}

double Booking::getPrice() const
{
    return price;
}

long Booking::getTravelID() const
{
    return travelID;
}

void Booking::setTravelID(long newTravelID)
{
    travelID = newTravelID;
}

void Booking::setPrice(double newPrice)
{
    price = newPrice;
}

types Booking::getBookingType() const
{
    return bookingType;
}

void Booking::setBookingType(types newBookingType)
{
    bookingType = newBookingType;
}

const std::string &Booking::getFromDate() const
{
    return fromDate;
}

void Booking::setFromDate(const std::string &newFromDate)
{
    fromDate = newFromDate;
}

const std::string &Booking::getToDate() const
{
    return toDate;
}

void Booking::setToDate(const std::string &newToDate)
{
    toDate = newToDate;
}

QDate Booking::getQFromDate() const
{
    return qFromDate;
}

void Booking::setQFromDate(const std::string &newFromDate)
{
    QString qstr = QString::fromStdString(newFromDate);
    qFromDate = QDate::fromString(qstr, "yyyyMMdd");
}

QDate Booking::getQToDate() const
{
    return qToDate;
}

void Booking::setQToDate(const std::string &newToDate)
{
    QString qstr = QString::fromStdString(newToDate);
    qToDate = QDate::fromString(qstr, "yyyyMMdd");
}
