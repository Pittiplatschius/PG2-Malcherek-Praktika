#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

TravelAgency::TravelAgency()
{

}

void TravelAgency::readFile(QString pFile, const int &pNumberOfLine)
{
    std::string line;
    std::string fileName = pFile.toStdString();
    std::ifstream inputFilestream;
    int numberOfLine = pNumberOfLine;
    countFlights = 0, countRents = 0, countHotels = 0, totalValue = 0, countTravels = 0, countCustomer = 0;

    inputFilestream.open(fileName.c_str(), std::ifstream::in);
    if (!inputFilestream.is_open()) {
        inputFilestream.close();
        throw std::invalid_argument("Datei konnte nicht geoeffnet werden");
    }

    /*
    if(numberOfLine > 1) {
        inputFilestream.seekg(numberOfLine-1);
    }
    */

    while(!inputFilestream.eof()) {

        types type;
        std::stringstream zeileStringStream;
        std::string fromDate, toDate, pickupLocation, returnLocation, company, hotel, town, fromDestination, toDestination, airline, customerName;
        long bookingID, travelID, customerID;
        int attributes;
        double price;
        int numberOfAttribute = 1, countAttribute = 1;

        getline(inputFilestream, line);
        zeileStringStream << line;

        for(auto &k : line) {
            if(k == '|') {
                countAttribute++;
            }
        }

        while(!zeileStringStream.eof()) {
            std::string attribute;

            switch (numberOfAttribute) {
            case 1: { //Attribut
                getline(zeileStringStream, attribute, '|');
                for(char character : attribute) {
                    switch (character) {
                    case 'F': {
                        type = Flight;
                        attributes = 11;
                    }
                        break;
                    case 'R': {
                        type = Rent;
                        attributes = 11;
                    }
                        break;
                    case 'H': {
                        type = Hotel;
                        attributes = 10;
                    }
                        break;
                    }
                }

                if (countAttribute != attributes) {
                    inputFilestream.close();
                    throw std::invalid_argument("Falsche Anzahl von Attributen in Zeile: " + std::to_string(numberOfLine));
                }
                break;
                }
            case 2: { //BookingID
                getline(zeileStringStream, attribute, '|');
                bookingID = stoi(attribute);
                break;
                }
            case 3: { //Preis
                getline(zeileStringStream, attribute, '|');
                price = stod(attribute);
                if (checkDigit(price)) {
                    inputFilestream.close();
                    throw std::invalid_argument("Falsche Preiswert in Zeile: " + std::to_string(numberOfLine));
                }
                break;
                }
            case 4: { //Startdatum
                getline(zeileStringStream, fromDate, '|');
                break;
                }
            case 5: { //Zieldatum
                getline(zeileStringStream, toDate, '|');
                break;
                }
            case 6: { //TravelID
                getline(zeileStringStream, attribute, '|');
                travelID = stoi(attribute);
                break;
                }
            case 7: { //CustomerID
                getline(zeileStringStream, attribute, '|');
                customerID = stoi(attribute);
                break;
                }
            case 8: { //Customer Name
                getline(zeileStringStream, customerName, '|');
                break;
                }
            case 9: { //Start/Pickup/Hotel
                switch (type) {
                case Flight: {
                    getline(zeileStringStream, fromDestination, '|');
                    if(fromDestination.length() != 3) {
                        inputFilestream.close();
                        throw std::invalid_argument("Flughafenkuerzel in Zeile: " + std::to_string(numberOfLine) + " zu lang/kurz");
                    }
                    break;
                    }
                case Rent:
                    getline(zeileStringStream, pickupLocation, '|');
                    break;
                case Hotel:
                    getline(zeileStringStream, hotel, '|');
                    break;
                }
                break;
                }
            case 10: { //Ziel/Return/Stadt
                switch (type) {
                case Flight: {
                    getline(zeileStringStream, toDestination, '|');
                    if(toDestination.length() != 3) {
                        throw std::invalid_argument("Flughafenkuerzel in Zeile: " + std::to_string(numberOfLine) + " zu lang/kurz");
                    }
                    break;
                    }
                case Rent:
                    getline(zeileStringStream, returnLocation, '|');
                    break;
                case Hotel:
                    getline(zeileStringStream, town);
                    break;
                }
                break;
                }
            case 11: { //Flughafen/Unternehmen
                switch (type) {
                case Flight:
                    getline(zeileStringStream, airline);
                    break;
                case Rent:
                    getline(zeileStringStream, company);
                    break;
                default:
                    break;
                }
                break;
                }
            }
            numberOfAttribute++;
        }

        switch (type) {
        case Flight: {
            FlightBooking *flightBooking = dynamic_cast<FlightBooking*>(findBooking(bookingID));
            if (flightBooking == nullptr) {
                flightBooking = new FlightBooking(bookingID, travelID, price, fromDate, fromDestination, toDestination, airline);
                allBookingsVec.push_back(flightBooking);
                totalValue += price;
                countFlights++;
            } else {
                break;
            }

            Travel *travel = findTravel(travelID);
            if (travel == nullptr) {
                travel = new Travel(travelID, customerID);
                allTravelVec.push_back(travel);
                travel->addBooking(flightBooking);
                countTravels++;
            } else {
                if (!travel->checkBooking(bookingID)) {
                    travel->addBooking(flightBooking);
                }
                break;
            }

            Customer *customer = findCustomer(customerID);
            if (customer == nullptr) {
                Customer *customer = new Customer(customerID, customerName);
                allCustomerVec.push_back(customer);
                customer->addTravel(travel);
                countCustomer++;
            } else {
                if (!customer->checkTravel(travelID)) {
                    customer->addTravel(travel);
                }
                break;
            }
        }
        case Rent: {
            RentalCarReservation *rentalCarRes = dynamic_cast<RentalCarReservation*>(findBooking(bookingID));
            if (rentalCarRes == nullptr) {
                rentalCarRes = new RentalCarReservation(bookingID, travelID, price, fromDate, toDate, pickupLocation, returnLocation, company);
                allBookingsVec.push_back(rentalCarRes);
                totalValue += price;
                countRents++;
            } else {
                break;
            }

            Travel *travel = findTravel(travelID);
            if (travel == nullptr) {
                travel = new Travel(travelID, customerID);
                allTravelVec.push_back(travel);
                travel->addBooking(rentalCarRes);
                countTravels++;
            } else {
                if (!travel->checkBooking(bookingID)) {
                    travel->addBooking(rentalCarRes);
                }
                break;
            }

            Customer *customer = findCustomer(customerID);
            if (customer == nullptr) {
                Customer *customer = new Customer(customerID, customerName);
                allCustomerVec.push_back(customer);
                customer->addTravel(travel);
                countCustomer++;
            } else {
                if (!customer->checkTravel(travelID)) {
                    customer->addTravel(travel);
                }
                break;
            }
        }
        case Hotel: {
            HotelBooking *hotelBooking = dynamic_cast<HotelBooking*>(findBooking(bookingID));
            if (hotelBooking == nullptr) {
                hotelBooking = new HotelBooking(bookingID, travelID, price, fromDate, toDate, hotel, town);
                allBookingsVec.push_back(hotelBooking);
                totalValue += price;
                countHotels++;
            } else {
                break;
            }

            Travel *travel = findTravel(travelID);
            if (travel == nullptr) {
                travel = new Travel(travelID, customerID);
                allTravelVec.push_back(travel);
                travel->addBooking(hotelBooking);
                countTravels++;
            } else {
                if (!travel->checkBooking(bookingID)) {
                    travel->addBooking(hotelBooking);
                }
                break;
            }

            Customer *customer = findCustomer(customerID);
            if (customer == nullptr) {
                Customer *customer = new Customer(customerID, customerName);
                allCustomerVec.push_back(customer);
                customer->addTravel(travel);
                countCustomer++;
            } else {
                if (!customer->checkTravel(travelID)) {
                    customer->addTravel(travel);
                }
                break;
            }
        }
        }
        numberOfLine++;
    }
    inputFilestream.close();
}

void TravelAgency::exportJsonFile(QString pFile)
{

    QJsonDocument jsonDocument;

    QJsonArray jsonArrayFlightBookings;
    QJsonArray jsonArrayRentBookings;
    QJsonArray jsonArrayHotelBookings;

    for(auto &b : allBookingsVec) {
        if(FlightBooking* flightBooking = dynamic_cast<FlightBooking*>(b)) {
            QJsonObject jsonFlightObject;

            jsonFlightObject["airline"] = QString::fromStdString(flightBooking->getAirline());
            jsonFlightObject["fromDate"] = QString::fromStdString(flightBooking->getFromDate());
            jsonFlightObject["fromDest"] = QString::fromStdString(flightBooking->getFromDestination());
            jsonFlightObject["id"] = QString::number(flightBooking->getBookingID());
            jsonFlightObject["price"] = QString::number(flightBooking->getPrice());
            jsonFlightObject["toDate"] = QString::fromStdString(flightBooking->getToDate());
            jsonFlightObject["toDest"] = QString::fromStdString(flightBooking->getToDestination());

            jsonArrayFlightBookings.push_back(jsonFlightObject);
        } else if(RentalCarReservation* rentalCarRes = dynamic_cast<RentalCarReservation*>(b)) {
            QJsonObject jsonRentObject;

            jsonRentObject["company"] = QString::fromStdString(rentalCarRes->getCompany());
            jsonRentObject["fromDate"] = QString::fromStdString(rentalCarRes->getFromDate());
            jsonRentObject["id"] = QString::number(rentalCarRes->getBookingID());
            jsonRentObject["pickupLocation"] = QString::fromStdString(rentalCarRes->getPickupLocation());
            jsonRentObject["price"] = QString::number(rentalCarRes->getPrice());
            jsonRentObject["returnLocation"] = QString::fromStdString(rentalCarRes->getReturnLocation());
            jsonRentObject["toDate"] = QString::fromStdString(rentalCarRes->getToDate());

            jsonArrayRentBookings.push_back(jsonRentObject);
        } else if(HotelBooking* hotelBooking = dynamic_cast<HotelBooking*>(b)) {
            QJsonObject jsonHotelObject;

            jsonHotelObject["fromDate"] = QString::fromStdString(hotelBooking->getFromDate());
            jsonHotelObject["hotel"] = QString::fromStdString(hotelBooking->getHotel());
            jsonHotelObject["id"] = QString::number(hotelBooking->getBookingID());
            jsonHotelObject["price"] = QString::number(hotelBooking->getPrice());
            jsonHotelObject["toDate"] = QString::fromStdString(hotelBooking->getToDate());
            jsonHotelObject["town"] = QString::fromStdString(hotelBooking->getTown());

            jsonArrayHotelBookings.push_back(jsonHotelObject);
        }
    }

    QJsonObject flights, rents, hotels;
    flights["Flugbuchungen"] = jsonArrayFlightBookings;
    rents["Mietwagenreservierungen"] = jsonArrayRentBookings;
    hotels["Hotelbuchungen"] = jsonArrayHotelBookings;

    QJsonArray allBookings;
    allBookings.append(flights);
    allBookings.append(rents);
    allBookings.append(hotels);

    jsonDocument.setArray(allBookings);

    QFile datei(pFile);
    if(!datei.open(QIODevice::WriteOnly)) {
        throw std::invalid_argument("Datei konnte nicht geoeffnet werden");
    }

    datei.write(jsonDocument.toJson());
    datei.close();
}

void TravelAgency::showAllBookings() const
{
    for (auto &k : allBookingsVec) {
        qPrintable(k->showDetails());
    }
}

QString TravelAgency::bookedMessage()
{
    QString qstr;
    std::string str;
    int one = findCustomer(1)->getTravelListVec().size();
    //int two = findCustomer(17)->getTravelListVec().size();

    std::string str_TotalValue = std::to_string(totalValue);
    str_TotalValue.erase(str_TotalValue.size() - 4);

    str.append("Es wurden ");
    str.append(std::to_string(countFlights));
    str.append(" Flugbuchungen , ");
    str.append(std::to_string(countHotels));
    str.append(" Hotelreservierungen und ");
    str.append(std::to_string(countRents));
    str.append(" Mietwagenreservierungen im Gesamtwert von ");
    str.append(str_TotalValue);
    str.append(" eingelesen. Es wurden ");
    str.append(std::to_string(countTravels));
    str.append(" Reisen und ");
    str.append(std::to_string(countCustomer));
    str.append(" Kunden angelegt.\nDer Kunde mit der ID 1 hat ");
    str.append(std::to_string(one));
    str.append(" Reisen gebucht. Zur Reise mit der ID 17 gehören ");
    //str.append(std::to_string(two));
    str.append(" Buchungen.");

    qstr = QString::fromStdString(str);

    return qstr;
}

void TravelAgency::deleteBookings()
{
    allBookingsVec.clear();
    countFlights = 0, countRents = 0, countHotels = 0;
    totalValue = 0;
}

bool TravelAgency::checkDigit(const double &pDigit) const
{
    if (std::isdigit(pDigit) != 0) {
        return true;
    }
    return false;

    /*
    return !str.empty() && std::find_if(str.begin(),
        str.end(), [](unsigned char c) { return !std::isdigit(c); }) == str.end();
        */
}

void TravelAgency::sortBookings()
{
    sort(allBookingsVec.begin(), allBookingsVec.end(),
         [](Booking* const &a, Booking* const &b) {
        return a->getBookingID() < b->getBookingID();
    }
         );
}

const std::vector<Booking *> &TravelAgency::getAllBookingsVec() const
{
    return allBookingsVec;
}

const std::vector<Customer *> &TravelAgency::getAllCustomerVec() const
{
    return allCustomerVec;
}

Booking* TravelAgency::findBooking(const long &pID)
{
    for(auto &b : allBookingsVec) {
        if(b->getBookingID() == pID) {
            return b;
        }
    }
    return nullptr;
}

Travel* TravelAgency::findTravel(const long &pID)
{
    for(auto &t : allTravelVec) {
        if(t->getTravelID() == pID) {
            return t;
        }
    }
    return nullptr;
}

Customer* TravelAgency::findCustomer(const long &pID)
{
    for(auto &c : allCustomerVec) {
        if(c->getCustomerID() == pID) {
            return c;
        }
    }
    return nullptr;
}
