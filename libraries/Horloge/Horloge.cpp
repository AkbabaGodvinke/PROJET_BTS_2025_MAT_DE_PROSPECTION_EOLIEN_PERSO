#include "Arduino.h"
#include "Horloge.h"
#include "Wire.h"

Horloge::Horloge()
{
	
}
void Horloge::SetTimeHeure(byte heure)
{	
	byte heureBCD = ((heure/10)<<4)+(heure%10);
	Wire.beginTransmission(0x68);
	Wire.write(0x02);
	Wire.write(heureBCD);
	Wire.endTransmission();
}

void Horloge::SetTimeMinute(byte minute)
{
	byte minuteBCD = ((minute/10)<<4)+(minute%10);
	Wire.beginTransmission(0x68);
	Wire.write(0x01);
	Wire.write(minuteBCD);
	Wire.endTransmission();
}

void Horloge::SetTimeSeconde(byte seconde)
{
	byte secondeBCD = ((seconde/10)<<4)+(seconde%10);
	Wire.beginTransmission(0x68);
	Wire.write(0X00);
	Wire.write(secondeBCD);
	Wire.endTransmission();
}

void Horloge::SetTimeAnnee(byte annee)
{
	byte anneeBCD = ((annee/10)<<4)+(annee%10);
	Wire.beginTransmission(0x68);
	Wire.write(0x06);
	Wire.write(anneeBCD);
	Wire.endTransmission();
}

void Horloge::SetTimeMois(byte mois)
{
	byte moisBCD = ((mois/10)<<4)+(mois%10);
	Wire.beginTransmission(0x68);
	Wire.write(0x05);
	Wire.write(moisBCD);
	Wire.endTransmission();
}
byte Horloge::getTimeHeure()
{	
	lireDate();
	return _heure;
}


void Horloge::lireDate()
{
  Wire.beginTransmission(0x68);    
  Wire.write(0);                   
  Wire.endTransmission();          
  Wire.requestFrom(0x68,7);
  _seconde = Wire.read();
  _minute = Wire.read();
  _heure = Wire.read();
  _jour = Wire.read();
  _date = Wire.read();
  _mois = Wire.read();
  _annee = Wire.read();
	
}