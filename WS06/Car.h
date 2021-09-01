/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"
namespace sdds
{
	class Car : public Vehicle{
		std::string m_maker{};
		std::string m_condition{};
		double m_topSpeed = 0;
	public:
		Car();
		Car(std::istream& car);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif
