#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

TravelAgency::TravelAgency()
{

}

void TravelAgency::readFile(QString file)
{
    std::string zeile;
    //std::string fileName = "bookings.txt";
    std::string fileName = file.toStdString();
    std::ifstream inputFilestream;

    inputFilestream.open(fileName.c_str(), std::ifstream::in);
    if (!inputFilestream.is_open())
        std::cerr << "Datei konnte nicht geoeffnet werden" << std::endl;

    while(!inputFilestream.eof()) {

        types type;
        std::stringstream zeileStringStream;
        std::string fromDate, toDate, pickupLocation, returnLocation, company, hotel, town, fromDestination, toDestination, airline;
        unsigned int id;
        double price;
        int numberOfAttribute = 0, countAttribute = 1, numberOfLine = 1;
        int attributes;

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
            case 0: {
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
            case 1: {
                getline(zeileStringStream, attribute, '|');
                id = stoi(attribute);
                break;
                }
            case 2: {
                getline(zeileStringStream, attribute, '|');
                price = stod(attribute);

                if (std::isdigit(price) != 0) {
                    inputFilestream.close();
                    bookings.clear();
                    throw std::invalid_argument("Falsche Preiswert in Zeile " + std::to_string(numberOfLine));
                }
                break;
                }
            case 3: {
                getline(zeileStringStream, fromDate, '|');
                break;
            }
            case 4: {
                getline(zeileStringStream, toDate, '|');
                break;
            }
            case 5: {
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
            case 6: {
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
            case 7: {
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
}

void TravelAgency::showAllBookings() const
{
    for (auto &k : bookings) {
        std::cout << k->showDetails() << std::endl;
    }
}

std::string& TravelAgency::readData()
{
    /*
    std::cout << "Es wurden " << countFlights << " Flugbuchungen im Wert von " << allFlightsCosts << "," << std::endl;
    std::cout << countRents << " Mietwagenbuchungen im Wert von " << allRentCosts << " und" << std::endl;
    std::cout << countHotels << "  Hotelreservierungen im Wert von " << allHotelCosts << " eingelesen." << std::endl;
    */

    std::string str;

    std::string flights = std::to_string(countFlights);
    std::string flightCosts = std::to_string(allFlightsCosts);
    std::string rents = std::to_string(countRents);
    std::string rentCosts = std::to_string(allRentCosts);
    std::string hotels = std::to_string(countHotels);
    std::string hotelCosts = std::to_string(allHotelCosts);

    str.append("Es wurden ");
    str.append(flights);
    str.append(" Flugbuchungen im Wert von ");
    str.append(flightCosts);
    str.append(", ");
    str.append(rents);
    str.append(" Mietwagenbuchungen im Wert von ");
    str.append(rentCosts);
    str.append(" und ");
    str.append(hotels);
    str.append(" Hotereservierungen im Wert von ");
    str.append(hotelCosts);
    str.append(" eingelesen. ");

    return str;
}
