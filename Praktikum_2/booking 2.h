#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <QString>

class Booking
{
private:
    unsigned int id;
    double price;
    std::string fromDate, toDate;

public:
    Booking();

    virtual QString showDetails() = 0;

    int getId() const;
    double getPrice() const;
    const std::string &getFromDate() const;
    const std::string &getToDate() const;
    void setId(int newId);
    void setPrice(double newPrice);
    void setFromDate(const std::string &newFromDate);
    void setToDate(const std::string &newToDate);
};

#endif // BOOKING_H
