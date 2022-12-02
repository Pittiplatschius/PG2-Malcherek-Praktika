#include "travelagency.h"

void printMenu() {
    std::cout << "Text- oder Bnaerdatei lesen?" << std::endl;
    std::cout << "t eingeben fuer Textatei" << std::endl;
    std::cout << "b eingeben fuer Binaerdatei" << std::endl;
    std::cout << "x eingeben fuer Programmstopp" << std::endl;
    std::cout << "Eingabe: ";
}

void menu() {
    char eingabe;
    TravelAgency tA;
    bool invalid;
    bool readFile = false;

    do {

        printMenu();
        std::cin >> eingabe;

        invalid = false;

        try {
            switch (eingabe) {
            case 't':
                tA.readFile();
                readFile = true;
                break;
            case 'b':
                tA.readBinaryFile();
                break;
            case 'x':
                std::cout << "Programm wurde gestoppt" << std::endl;
                return;
            default:
                std::cout << "Falscheinabge!" << std::endl;
                break;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            invalid = true;
        }

        if (invalid) {
            char eingabe_2;

            do {
                std::cout << "Haben Sie die Datei korrigiert? (j/n)" << std::endl;
                std::cin >> eingabe_2;
                if (eingabe_2 == 'j') {
                    invalid = false;
                }
            }while(eingabe_2 != 'j');
        } else if(readFile) {
           char eingabe_3;

            do {
                std::cout << "Alle eingegeben Daten auflisten? (j/n)" << std::endl << "Eingabe: ";
                std::cin >> eingabe_3;

                switch (eingabe_3) {
                case 'j':
                    tA.showAllBookings();
                    break;
                case 'n':
                    std::cout << "Keine Ausgabe gefordert" << std::endl;
                    break;
                default:
                    std::cout << "Falscheingabe!" << std::endl;
                    break;
                }
            } while(eingabe_3 != 'n');
        }

    } while (eingabe != 'x');
}

int main()
{

    menu();

    return 0;
}
