#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

TravelAgency::TravelAgency()
{

}

void TravelAgency::readTextFile(QString file)
{
    std::string zeile;
    std::string fileName = file.toStdString();
    std::ifstream inputFilestream;
    int numberOfLine = 1;

    inputFilestream.open(fileName.c_str(), std::ifstream::in);
    if (!inputFilestream.is_open()) {
        throw std::invalid_argument("Datei konnte nicht geoeffnet werden");
    }

    while(!inputFilestream.eof()) {

        types type;
        std::stringstream zeileStringStream;
        std::string fromDate, toDate, pickupLocation, returnLocation, company, hotel, town, fromDestination, toDestination, airline;
        int id, attributes;
        double price;
        int numberOfAttribute = 0, countAttribute = 1;

        getline(inputFilestream, zeile);
        zeileStringStream << zeile;

        for(auto &k : zeile) {
            if(k == '|') {
                countAttribute++;
            }
        }

        while(!zeileStringStream.eof()) {
            std::string attribute;

            switch (numberOfAttribute) {
            case 0: { //Attribut
                getline(zeileStringStream, attribute, '|');
                for(char character : attribute) {
                    switch (character) {
                    case 'F': {
                        type = Flight;
                        attributes = 8;
                    }
                        break;
                    case 'R': {
                        type = Rent;
                        attributes = 8;
                    }
                        break;
                    case 'H': {
                        type = Hotel;
                        attributes = 7;
                    }
                        break;
                    }
                }

                if (countAttribute != attributes) {
                    inputFilestream.close();
                    bookings.clear();
                    throw std::invalid_argument("Falsche Anzahl von Attributen in Zeile " + std::to_string(numberOfLine));
                }
                break;
                }
            case 1: { //ID
                getline(zeileStringStream, attribute, '|');
                id = stoi(attribute);
                break;
                }
            case 2: { //Preis
                getline(zeileStringStream, attribute, '|');
                price = stod(attribute);
                if (checkDigit(price)) {
                    inputFilestream.close();
                    bookings.clear();
                    throw std::invalid_argument("Falsche Preiswert in Zeile " + std::to_string(numberOfLine));
                }
                break;
                }
            case 3: { //Startdatum
                getline(zeileStringStream, fromDate, '|');
                break;
            }
            case 4: { //Zieldatum
                getline(zeileStringStream, toDate, '|');
                break;
            }
            case 5: { //Start/Pickup/Hotel
                switch (type) {
                case Flight: {
                    getline(zeileStringStream, fromDestination, '|');
                    if(fromDestination.length() != 3) {
                        throw std::invalid_argument("Flughafenkuerzel in Zeile " + std::to_string(numberOfLine) + " zu lang/kurz");
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
            case 6: { //Ziel/Return/Stadt
                switch (type) {
                case Flight: {
                    getline(zeileStringStream, toDestination, '|');
                    if(toDestination.length() != 3) {
                        throw std::invalid_argument("Flughafenkuerzel in Zeile " + std::to_string(numberOfLine) + " zu lang/kurz");
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
            case 7: { //Flughafen/Unternehmen
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
            FlightBooking *f = new FlightBooking(id, price, fromDate, fromDestination, toDestination, airline);
            bookings.push_back(f);
            allFlightsCosts += price;
            countFlights++;
            break;
            }
        case Rent: {
            RentalCarReservation *r = new RentalCarReservation(id, price, fromDate, toDate, pickupLocation, returnLocation, company);
            bookings.push_back(r);
            allRentCosts += price;
            countRents++;
            break;
            }
        case Hotel: {
            HotelBooking *h = new HotelBooking(id, price, fromDate, toDate, hotel, town);
            bookings.push_back(h);
            allHotelCosts += price;
            countHotels++;
            break;
            }
        }

        numberOfLine++;

    }

    inputFilestream.close();

    /*
    sort(bookings.begin(), bookings.end(),
         [](Booking* const& a, Booking* const& b) {
        return a->getId() < b->getId();
    }
         );
         */

}

void TravelAgency::exportJsonFile(QString file)
{

    QJsonDocument jsonDocument;

    QJsonArray jsonArrayFlightBookings;
    QJsonArray jsonArrayRentBookings;
    QJsonArray jsonArrayHotelBookings;

    for(auto &b : bookings) {
        if(FlightBooking* fb = dynamic_cast<FlightBooking*>(b)) {
            QJsonObject jsonFlightObject;

            jsonFlightObject["airline"] = QString::fromStdString(fb->getAirline());
            jsonFlightObject["fromDate"] = QString::fromStdString(fb->getFromDate());
            jsonFlightObject["fromDest"] = QString::fromStdString(fb->getFromDestination());
            jsonFlightObject["id"] = QString::number(fb->getId());
            jsonFlightObject["price"] = QString::number(fb->getPrice());
            jsonFlightObject["toDate"] = QString::fromStdString(fb->getToDate());
            jsonFlightObject["toDest"] = QString::fromStdString(fb->getToDestination());

            jsonArrayFlightBookings.push_back(jsonFlightObject);
        } else if(RentalCarReservation* rcr = dynamic_cast<RentalCarReservation*>(b)) {
            QJsonObject jsonRentObject;

            jsonRentObject["company"] = QString::fromStdString(rcr->getCompany());
            jsonRentObject["fromDate"] = QString::fromStdString(rcr->getFromDate());
            jsonRentObject["id"] = QString::number(rcr->getId());
            jsonRentObject["pickupLocation"] = QString::fromStdString(rcr->getPickupLocation());
            jsonRentObject["price"] = QString::number(rcr->getPrice());
            jsonRentObject["returnLocation"] = QString::fromStdString(rcr->getReturnLocation());
            jsonRentObject["toDate"] = QString::fromStdString(rcr->getToDate());

            jsonArrayRentBookings.push_back(jsonRentObject);
        } else if(HotelBooking* hb = dynamic_cast<HotelBooking*>(b)) {
            QJsonObject jsonHotelObject;

            jsonHotelObject["fromDate"] = QString::fromStdString(hb->getFromDate());
            jsonHotelObject["hotel"] = QString::fromStdString(hb->getHotel());
            jsonHotelObject["id"] = QString::number(hb->getId());
            jsonHotelObject["price"] = QString::number(hb->getPrice());
            jsonHotelObject["toDate"] = QString::fromStdString(hb->getToDate());
            jsonHotelObject["town"] = QString::fromStdString(hb->getTown());

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

    QFile datei(file);
    if(!datei.open(QIODevice::WriteOnly)) {
        throw std::invalid_argument("Datei konnte nicht geoeffnet werden");
    }

    datei.write(jsonDocument.toJson());
    datei.close();
}

void TravelAgency::showAllBookings() const
{
    /*
    sort(bookings.begin(), bookings.end(),
         [](Booking* const& a, Booking* const& b) {
        return a->getId() < b->getId();
    }
         );
         */

    for (auto &k : bookings) {
        qPrintable(k->showDetails());
        //std::cout << k->showDetails() << std::endl;
    }
}

QString TravelAgency::bookedMessage() const
{
    QString qstr;
    std::string str;

    std::string str_allFlightsCosts = std::to_string(allFlightsCosts);
    str_allFlightsCosts.erase(str_allFlightsCosts.size() - 4);

    std::string str_allRentCosts = std::to_string(allRentCosts);
    str_allRentCosts.erase(str_allRentCosts.size() - 4);

    std::string std_allHotelCosts = std::to_string(allHotelCosts);
    std_allHotelCosts.erase(std_allHotelCosts.size() - 4);

    str.append("Es wurden ");
    str.append(std::to_string(countFlights));
    str.append(" Flugbuchungen im Wert von ");
    str.append(str_allFlightsCosts);
    str.append(", ");
    str.append(std::to_string(countRents));
    str.append(" Mietwagenbuchungen im Wert von ");
    str.append(str_allRentCosts);
    str.append(" und ");
    str.append(std::to_string(countHotels));
    str.append(" Hotelreservierungen im Wert von ");
    str.append(std_allHotelCosts);
    str.append(" eingelesen.");

    qstr = QString::fromStdString(str);

    return qstr;
}

void TravelAgency::deleteBookings()
{
    bookings.clear();
    countFlights = 0, countRents = 0, countHotels = 0;
    allFlightsCosts = 0, allRentCosts = 0, allHotelCosts = 0;
}

bool TravelAgency::checkDigit(const double &digit) const
{
    if (std::isdigit(digit) != 0) {
        return true;
    }
    return false;

    /*
    return !str.empty() && std::find_if(str.begin(),
        str.end(), [](unsigned char c) { return !std::isdigit(c); }) == str.end();
        */
}

const std::vector<Booking *> &TravelAgency::getBookings() const
{
    return bookings;
}
