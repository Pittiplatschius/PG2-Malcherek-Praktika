#include "booking.h"

Booking::Booking()
{

}

int Booking::getId() const
{
    return id;
}

double Booking::getPrice() const
{
    return price;
}

void Booking::setId(int newId)
{
    id = newId;
}

void Booking::setPrice(double newPrice)
{
    price = newPrice;
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

types Booking::getBookingType() const
{
    return bookingType;
}

void Booking::setBookingType(types newBookingType)
{
    bookingType = newBookingType;
}
