#include <Wire.h>
#include "HORLOGE_RTC.h"

HORLOGE_RTC horloge(0x68);

void setup() {
    Serial.begin(9600);
    horloge.reglerHeure(0, 7, 11, 4, 20, 3, 25);
}

void loop() {
  byte secondes, minutes, heures, jourSemaine, jour, mois, annee;
    horloge.afficherHeure();
    horloge.lireHeure(secondes, minutes, heures, jourSemaine, jour, mois, annee);
        char horodatage[20];
    sprintf(horodatage, "%02d:%02d:%02d;%02d-%02d-20%02d", 
            heures, minutes, secondes, 
            jour, mois, annee);
    Serial.println(horodatage);
    delay(5000);
}