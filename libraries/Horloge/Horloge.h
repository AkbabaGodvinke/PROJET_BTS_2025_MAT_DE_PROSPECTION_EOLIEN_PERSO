#ifndef Horloge_h
#define Horloge_h

#include "Wire.h"
#include "Arduino.h"

class Horloge
{
	public:
		Horloge();
		void SetTimeHeure(byte heure);
		void SetTimeSeconde(byte seconde);
		void SetTimeMinute(byte minute);
		void SetTimeAnnee(byte annee);
		void SetTimeMois(byte mois);
		void lireDate();
		byte getTimeHeure();
		
		
	
	
	private:
		byte _heure;
		byte _minute;
		byte _seconde;
		byte _annee;
		byte _mois;
		byte _jour;
		byte _date;
		
		
};


#endif