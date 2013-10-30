#include "sportsman.h"

using namespace std;


istream& operator>> (istream &s, SportsMan &sm)
{
	cout << "\nEnter name: "; s >> sm.name;
	cout << "\nEnter country: "; s >> sm.country;
	cout << "\nEnter sport: "; s >> sm.sport;
	cout << "\nEnter place: "; s >> sm.place;
	return s;
}


ostream& operator<< (ostream &s, SportsMan &sm)
{
	s << "\nName: " << sm.name
	  << "\nSport: " << sm.sport
	  << "\nCountry: " << sm.country
	  << "\nPlace: " << sm.place;
	return s;
}


SportsMan::SportsMan(SportsMan &sm)
{
	name = sm.name;
	place = sm.place;
	sport = sm.sport;
	country = sm.country;
}


SportsMan::SportsMan(): name("N/A"), sport("N/A"), place(0), country("N/A")
{ }
