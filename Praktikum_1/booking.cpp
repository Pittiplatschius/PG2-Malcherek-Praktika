#include "booking.h"

Booking::Booking()
{

}

unsigned int Booking::getId() const
{
    return id;
}

double Booking::getPrice() const
{
    return price;
}

const std::string &Booking::getFromDate() const
{
    return fromDate;
}

const std::string &Booking::getToDate() const
{
    return toDate;
}

void Booking::setId(unsigned int newId)
{
    id = newId;
}

void Booking::setPrice(double newPrice)
{
    price = newPrice;
}

void Booking::setFromDate(const std::string &newFromDate)
{
    fromDate = newFromDate;
}

void Booking::setToDate(const std::string &newToDate)
{
    toDate = newToDate;
}
