/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Reservation_H
#define Reservation_H
#include<iostream>
#include<string>
using namespace std;
namespace sdds {
	class Reservation {
		string id = "";
		string name = "";
		string email = "";
		int party_size = 0;
		int day = 0;
		int hour = 0;
	public:
		Reservation();
		Reservation(const string& res);
		friend ostream& operator<<(ostream& os, const Reservation& res);
	};
}
#endif