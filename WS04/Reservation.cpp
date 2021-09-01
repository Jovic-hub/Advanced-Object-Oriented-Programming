/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include "Reservation.h"
#include "Reservation.h"

using namespace std;
namespace sdds {
	Reservation::Reservation(){
		id = "" ;
		name = "" ;
		email =  "" ;
		party_size = 0 ;
		day = 0 ;
		hour = 0;
	}

	Reservation::Reservation(const string& res) {
		string reservation = res;
		int i = 1;
		char empty = ' ';

		id = reservation.substr(0, reservation.find(':'));
		reservation.erase(0, reservation.find(':') + i);
		id.erase(0, id.find_first_not_of(empty));
		id.erase(id.find_last_not_of(empty) + i);

		name = reservation.substr(0, reservation.find(','));
		reservation.erase(0, reservation.find(',') + i);
		name.erase(0, name.find_first_not_of(empty));
		name.erase(name.find_last_not_of(empty) + i);

		email = reservation.substr(0, reservation.find(','));
		reservation.erase(0, reservation.find(',') + i);
		email.erase(0, email.find_first_not_of(' '));
		email.erase(email.find_last_not_of(empty) + i);

		string party;
		party = reservation.substr(0, reservation.find(','));
		reservation.erase(0, reservation.find(',') + i);
		party_size = stoi(party);

		string date;
		date = reservation.substr(0, reservation.find(','));
		reservation.erase(0, reservation.find(',') + i);
		day = stoi(date);

		string time;
		time = reservation.substr(0, reservation.find(','));
		reservation.erase(0, reservation.find(',') + i);
		hour = stoi(time);
	}

	ostream& operator<<(ostream& os, const Reservation& res) {
		os << "Reservation" << setw(13) << res.id + ": " << setw(20) << res.name;
		os.width(26);
		os.setf(ios::left);
		os << "  <" + res.email + ">";
		os.unsetf(ios::left);
		if (res.hour >= 6 && res.hour <= 9) {
			os << "Breakfast";
		}
		else if (res.hour >= 11 && res.hour <= 15) {
			os << "Lunch";
		}
		else if (res.hour >= 17 && res.hour <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}
		os << " on day " << res.day << " @ " << res.hour << ":00" << " for " << res.party_size;
		if (res.party_size > 1) {
			os << " people.";
		}
		else {
			os << " person.";
		}
		os << endl;
		return os;
	}
}
