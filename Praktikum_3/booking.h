#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <QString>
#include <QDate>

enum types {Flight, Rent, Hotel};

class Booking
{
private:
    long booking_ID;
    long travelID;
    double price;
    types bookingType;
    std::string fromDate, toDate;
    QDate qFromDate, qToDate;

public:
    Booking();

    virtual QString showDetails() = 0;
    //virtual who am i methode die enum zurückgibt

    long getBookingID() const;
    void setbookingID(int newId);
    double getPrice() const;
    void setPrice(double newPrice);

    long getTravelID() const;
    void setTravelID(long newTravelID);

    types getBookingType() const;
    void setBookingType(types newBookingType);

    const std::string &getFromDate() const;
    void setFromDate(const std::string &newFromDate);
    const std::string &getToDate() const;
    void setToDate(const std::string &newToDate);

    QDate getQFromDate() const;
    void setQFromDate(const std::string &newFromDate);
    QDate getQToDate() const;
    void setQToDate(const std::string &newToDate);
};

#endif // BOOKING_H
