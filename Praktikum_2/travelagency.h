#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

#include "booking.h"

class TravelAgency
{
private:
    std::vector<Booking*> bookings;
    int countFlights = 0, countRents = 0, countHotels = 0;
    double allFlightsCosts = 0, allRentCosts = 0, allHotelCosts = 0;

public:
    TravelAgency();

    void readTextFile(QString file);
    void exportJsonFile(QString file);

    void showAllBookings() const;
    QString bookedMessage() const;
    void deleteBookings();
    bool checkDigit(const double& digit) const;

    const std::vector<Booking*> &getBookings() const;

};

#endif // TRAVELAGENCY_H
