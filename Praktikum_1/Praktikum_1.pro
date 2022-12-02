TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        booking.cpp \
        flightbooking.cpp \
        hotelbooking.cpp \
        main.cpp \
        rentalcarreservation.cpp \
        travelagency.cpp

HEADERS += \
    booking.h \
    flightbooking.h \
    hotelbooking.h \
    rentalcarreservation.h \
    travelagency.h

DISTFILES += \
    ../build-Praktikum_1-Desktop_Qt_5_13_2_clang_64bit-Debug/bookings.txt \
    ../build-Praktikum_1-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/bookings.txt \
    ../build-Praktikum_1-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/bookingsBinary.bin
