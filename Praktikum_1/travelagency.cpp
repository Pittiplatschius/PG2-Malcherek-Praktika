#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

TravelAgency::TravelAgency()
{

}

void TravelAgency::readFile()
{
    int countFlights = 0, countRents = 0, countHotels = 0;
    double allFlightsCosts = 0, allRentCosts = 0, allHotelCosts = 0;
    std::string zeile;
    std::string fileName = "bookings.txt";
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

    std::cout << "Es wurden " << countFlights << " Flugbuchungen im Wert von " << allFlightsCosts << "," << std::endl;
    std::cout << countRents << " Mietwagenbuchungen im Wert von " << allRentCosts << " und" << std::endl;
    std::cout << countHotels << "  Hotelreservierungen im Wert von " << allHotelCosts << " eingelesen." << std::endl;
}

void TravelAgency::readBinaryFile()
{
    int countFlights = 0, countRents = 0, countHotels = 0;
    double allFlightsCosts = 0.0, allRentCosts = 0.0, allHotelCosts = 0;

    char type;
    char aFromDestination[3], aToDestination[3];
    char aFromDate[8], aToDate[8];
    char aHotel[15], aTown[15], aAirline[15], aCompany[15], aPickupLocation[15], aReturnLocation[15];
    std::string fromDate, toDate, pickupLocation, returnLocation, company, hotel, town, fromDestination, toDestination, airline;
    long id;
    double price;

    std::string inputFileName = "bookingsBinary.bin";
    std::ifstream inputFileStream;

    inputFileStream.open(inputFileName.c_str(),std::ifstream::binary | std::ifstream::in);
    if(!inputFileStream) {
        std::cerr << inputFileName << " kann nicht geoeffnet werden!" << std::endl;
    }

    do{

        //fall 1
        inputFileStream.read(reinterpret_cast<char*>(&type), sizeof(char));
        //fall 2
        inputFileStream.read(reinterpret_cast<char*>(&id),sizeof(long));
        //fall 3
        inputFileStream.read(reinterpret_cast<char*>(&price),sizeof(double));

        //fall4
        for(size_t i = 0; i < sizeof(aFromDate); i++) {
            inputFileStream.read(reinterpret_cast<char*>(&aFromDate[i]),sizeof(char));
        }
        fromDate = aFromDate;
        aFromDate[0] = 0;

        //fall 5
        for(size_t i = 0; i < sizeof(aToDate); i++) {
            inputFileStream.read(reinterpret_cast<char*>(&aToDate[i]),sizeof(char));
        }
        toDate = aToDate;
        aToDate[0] = 0;

        //fall6
        switch (type ) {
        case 'F':
            for(size_t i = 0; i < sizeof(aFromDestination); i++) {
                inputFileStream.read(reinterpret_cast<char*>(&aFromDestination[i]),sizeof(char)*3);
            }
            fromDestination.assign(aFromDestination, 3);
            aFromDestination[0] = 0;
            break;
        case 'R':
            for(size_t i = 0; i < sizeof(aPickupLocation); i++) {
                inputFileStream.read(reinterpret_cast<char*>(&aPickupLocation[i]),sizeof(char));
            }
            pickupLocation = aPickupLocation;
            aPickupLocation[0] = 0;
            break;
        case 'H':
            for(size_t i = 0; i < sizeof(aHotel); i++) {
                inputFileStream.read(reinterpret_cast<char*>(&aHotel[i]),sizeof(char));
            }
            hotel = aHotel;
            aHotel[0] = 0;
            break;
        }

        //fall7
        switch (type) {
        case 'F':
            for(size_t i = 0; i < sizeof(aToDestination); i++) {
                inputFileStream.read(reinterpret_cast<char*>(&aToDestination[i]),sizeof(char));
            }
            toDestination = aToDestination;
            aToDestination[0] = 0;
            break;
        case 'R':
            for(size_t i = 0; i < sizeof(aReturnLocation); i++) {
                inputFileStream.read(reinterpret_cast<char*>(&aReturnLocation[i]),sizeof(char));
            }
            returnLocation = aReturnLocation;
            aReturnLocation[0] = 0;
            break;
        case 'H':
            for(size_t i = 0; i < sizeof(aTown); i++) {
                inputFileStream.read(reinterpret_cast<char*>(&aTown[i]),sizeof(char));
            }
            town = aTown;
            aTown[0] = 0;
            break;
        }

        //fall8
        switch (type) {
        case 'F':
            for(size_t i = 0; i < sizeof(aAirline); i++) {
                inputFileStream.read(reinterpret_cast<char*>(&aAirline[i]),sizeof(char));
            }
            airline = aAirline;
            aAirline[0] = 0;
            break;
        case 'R':
            for(size_t i = 0; i < sizeof(aCompany); i++) {
                inputFileStream.read(reinterpret_cast<char*>(&aCompany[i]),sizeof(char));
            }
            company = aCompany;
            aCompany[0] = 0;
            break;
        }

        switch (type) { //obejekte erstellen und speichern
        case 'F': {
            FlightBooking *f = new FlightBooking(id, price, fromDate, fromDestination, toDestination, airline);
            bookings.push_back(f);
            allFlightsCosts += price;
            countFlights++;
        }
            break;
        case 'R': {
            RentalCarReservation *r = new RentalCarReservation(id, price, fromDate, toDate, pickupLocation, returnLocation, company);
            bookings.push_back(r);
            allRentCosts += price;
            countRents++;
        }
            break;
        case 'H': {
            HotelBooking *h = new HotelBooking(id, price, fromDate, toDate, hotel, town);
            bookings.push_back(h);
            allHotelCosts += price;
            countHotels++;
        }
            break;
        }

    }while (!inputFileStream.eof());

    inputFileStream.close();

    std::cout << "Es wurden " << countFlights << " Flugbuchungen im Wert von " << allFlightsCosts << "," << std::endl;
    std::cout << countRents << " Mietwagenbuchungen im Wert von " << allRentCosts << " und" << std::endl;
    std::cout << countHotels << "  Hotelreservierungen im Wert von " << allHotelCosts << " eingelesen." << std::endl;
}

void TravelAgency::showAllBookings() const
{
    for (auto &k : bookings) {
        std::cout << k->showDetails() << std::endl;
    }
}

void TravelAgency::showExpensiveBooking() const
{
    int price;
    int highesPrice = 0;
    int place;

    for(size_t i = 0; i < bookings.size(); i++) {
        price = bookings.at(i)->getPrice();
        if (price > highesPrice) {
            highesPrice = price;
            place = i;
        }
    }
    std::cout << "Hoechster Preis: " << std::endl;
    bookings.at(place)->showDetails();
}
