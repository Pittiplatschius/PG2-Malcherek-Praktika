#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "booking.h"

enum types {Flight, Rent, Hotel};

class TravelAgency
{
private:
    std::vector<Booking*> bookings;

public:
    TravelAgency();

    void readFile();
    void readBinaryFile();

    void showAllBookings() const;
    void showExpensiveBooking() const;

};

#endif // TRAVELAGENCY_H
