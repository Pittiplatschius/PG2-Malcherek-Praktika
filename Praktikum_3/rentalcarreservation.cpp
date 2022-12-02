#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::RentalCarReservation(const long &pBooking_ID, const long &pTravelID, const double &pPrice, const std::string &pFromDate, const std::string &pToDate,
                                           const std::string &pPickpupLocation, const std::string &pReturnLocation, const std::string &pCompany) :
    pickupLocation(pPickpupLocation),
    returnLocation(pReturnLocation),
    company(pCompany)
{
    Booking::setBookingType(Rent);
    Booking::setbookingID(pBooking_ID);
    Booking::setTravelID(pTravelID);
    Booking::setPrice(pPrice);
    Booking::setQFromDate(pFromDate);
    Booking::setQToDate(pToDate);
}

QString RentalCarReservation::showDetails()
{
    QString qstr;
    std::string str;
    std::string id = std::to_string(getBookingID());
    std::string price = std::to_string(getPrice());
    std::string fromDate = getQFromDate().toString().toStdString();
    std::string toDate = getQFromDate().toString().toStdString();

    price.erase(price.size() - 4);

    str.append("ID: ");
    str.append(id);
    str.append(" - Mietwagenreservierung mit ");
    str.append(company);
    str.append(". Abholung am ");
    str.append(fromDate);
    str.append(" in ");
    str.append(pickupLocation);
    str.append(". Rueckgabe am ");
    str.append(toDate);
    str.append(" in ");
    str.append(returnLocation);
    str.append(". Preis: ");
    str.append(price);
    str.append(" Euro.");

    qstr = QString::fromStdString(str);

    return qstr;
}

const std::string &RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}


const std::string &RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

const std::string &RentalCarReservation::getCompany() const
{
    return company;
}
