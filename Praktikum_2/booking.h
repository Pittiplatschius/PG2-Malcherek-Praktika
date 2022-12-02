#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <QString>

enum types {Flight, Rent, Hotel};

class Booking
{
private:
    int id;
    double price;
    std::string fromDate, toDate;
    types bookingType;

public:
    Booking();

    virtual QString showDetails() = 0;
    //virtual who am i methode die enum zurückgibt

    int getId() const;
    double getPrice() const;
    void setId(int newId);
    void setPrice(double newPrice);

    const std::string &getFromDate() const;
    void setFromDate(const std::string &newFromDate);
    const std::string &getToDate() const;
    void setToDate(const std::string &newToDate);
    types getBookingType() const;
    void setBookingType(types newBookingType);
};

#endif // BOOKING_H
