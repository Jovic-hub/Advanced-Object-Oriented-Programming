/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"
namespace sdds
{
	class Racecar : public Car {
		double m_booster = 0;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif
