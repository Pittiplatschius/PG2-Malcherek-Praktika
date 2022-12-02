#include "travelAgencyUI.h"
#include "qapplication.h"

#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    //für buttons auf deutsch
    QTranslator translator;
    if(translator.load("qtbade_de")) {
        a.installTranslator(&translator);
    }*/

    TravelAgency tA;
    TravelAgencyUI tA_UI;
    tA_UI.show();

/*
    Ungelöste aufgabe aus Praktikum 3
        - Aufgabe 1:
            - In main legen Sie zunächst eine Instanz von TravelAgency an und übergeben einen Zeiger darauf an das UI (also an den Konstruktor der Klasse TravelAgencyUI
            - ist digit geht wohl nicht da zeile 106 bei der der preis unter 100 ist nicht eingelesen werden kann. Wirft fehler aus.
        - Aufgabe 2:
            - Liste aller Kunden und Reisen augeben. Ist ez aber wie stellt er sich das vor also welches format/aussehen?
            - kann kunde 17 iwi nicht ausgeben
        - Aufgabe 3:
            -

    Aktuelle "Probleme"

        - QString ausgabe richtig machen
        - nach fehler einlesen bei retry mit zeile beginnen wo aufgehört wurde funktioniert noch nciht
        - bei fehlermeldung nach cancel nur neuen einträge löschen und nicht alle
        - sort funktion. Nach was soll sortiert werden? aktuell nur nach ID
        - Booking Date sache nochmal durchgehen
*/

    return a.exec();
}
