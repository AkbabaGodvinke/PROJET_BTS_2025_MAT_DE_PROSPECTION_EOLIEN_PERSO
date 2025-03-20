#include "HORLOGE_RTC.h"

HORLOGE_RTC::HORLOGE_RTC(byte adresse) {
    adresseI2C = adresse;
    Wire.begin();
}

int HORLOGE_RTC::BCDversDEC(byte valeur) {
    return ((valeur / 16) * 10) + (valeur % 16);
}

byte HORLOGE_RTC::DECversBCD(int valeur) {
    return ((valeur / 10) << 4) | (valeur % 10);
}

void HORLOGE_RTC::reglerHeure(byte secondes, byte minutes, byte heures, byte jourSemaine, byte jour, byte mois, byte annee) {
    Wire.beginTransmission(adresseI2C);
    Wire.write(0x00);
    Wire.write(DECversBCD(secondes));
    Wire.write(DECversBCD(minutes));
    Wire.write(DECversBCD(heures));
    Wire.write(DECversBCD(jourSemaine));
    Wire.write(DECversBCD(jour));
    Wire.write(DECversBCD(mois));
    Wire.write(DECversBCD(annee));
    Wire.endTransmission();
}

void HORLOGE_RTC::lireHeure(byte &secondes, byte &minutes, byte &heures, byte &jourSemaine, byte &jour, byte &mois, byte &annee) {
    Wire.beginTransmission(adresseI2C);
    Wire.write(0x00);
    Wire.endTransmission();
    
    Wire.requestFrom(adresseI2C, 7);
    secondes = BCDversDEC(Wire.read());
    minutes = BCDversDEC(Wire.read());
    heures = BCDversDEC(Wire.read() & 0x3F);
    jourSemaine = BCDversDEC(Wire.read());
    jour = BCDversDEC(Wire.read());
    mois = BCDversDEC(Wire.read());
    annee = BCDversDEC(Wire.read());
}

void HORLOGE_RTC::afficherHeure() {
    byte secondes, minutes, heures, jourSemaine, jour, mois, annee;
    lireHeure(secondes, minutes, heures, jourSemaine, jour, mois, annee);

    Serial.print("Heure: ");
    if (heures < 10) Serial.print("0");
    Serial.print(heures);
    Serial.print(":");
    if (minutes < 10) Serial.print("0");
    Serial.print(minutes);
    Serial.print(":");
    if (secondes < 10) Serial.print("0");
    Serial.println(secondes);

    Serial.print("Date: ");
    if (jour < 10) Serial.print("0");
    Serial.print(jour);
    Serial.print("-");
    if (mois < 10) Serial.print("0");
    Serial.print(mois);
    Serial.print("-20");
    if (annee < 10) Serial.print("0");
    Serial.println(annee);

    Serial.println("*************************************");
}