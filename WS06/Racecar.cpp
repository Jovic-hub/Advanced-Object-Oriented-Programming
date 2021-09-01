/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<string>
#include "Racecar.h"
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in) {
		string boost;
		getline(in, boost, ',');
		boost.erase(0, boost.find_first_not_of(' '));
		boost.erase(boost.find_last_not_of(' ') + 1);
		m_booster = std::stod(boost);
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << '*';
	}
	double Racecar::topSpeed() const {
		double a = Car::topSpeed() * (1 + m_booster);
		return a;
	}
}