#ifndef HORLOGE_RTC_H
#define HORLOGE_RTC_H

#include <Wire.h>
#include <Arduino.h>

class HORLOGE_RTC {
private:
    byte adresseI2C;  // Adresse I2C du module RTC

    int BCDversDEC(byte valeur);
    byte DECversBCD(int valeur);

public:
    HORLOGE_RTC(byte adresse);

    void reglerHeure(byte secondes, byte minutes, byte heures, byte jourSemaine, byte jour, byte mois, byte annee);
    void lireHeure(byte &secondes, byte &minutes, byte &heures, byte &jourSemaine, byte &jour, byte &mois, byte &annee);
    void afficherHeure();
};

#endif