// sportsman.h

#ifndef SPORTSMAN_H_
#define SPORTSMAN_H_

#include <string>
#include <iostream>

using namespace std;

class SportsMan
{
private:
	string name;
	string sport;
	string country;
	int place;
public:
	SportsMan();
	SportsMan(SportsMan &);
	friend istream& operator>> (istream&, SportsMan&);
	friend ostream& operator<< (ostream&, SportsMan&);
};

#endif
