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
#include "customer.h"
#include "travel.h"

class TravelAgency
{
private:
    int countFlights, countRents, countHotels, countTravels, countCustomer;
    double totalValue;

    std::vector<Booking*> allBookingsVec;
    std::vector<Customer*> allCustomerVec;
    std::vector<Travel*> allTravelVec;

public:
    TravelAgency();

    void readFile(QString pFile, const int &pNumberOfLine = 1);
    void exportJsonFile(QString pFile);

    void showAllBookings() const;
    QString bookedMessage();
    void deleteBookings();
    bool checkDigit(const double &pDigit) const;
    void sortBookings();

    const std::vector<Booking*> &getAllBookingsVec() const;
    const std::vector<Customer *> &getAllCustomerVec() const;

    Booking* findBooking(const long& pID);
    Travel* findTravel(const long& pID);
    Customer* findCustomer(const long& pID);
};

#endif // TRAVELAGENCY_H
