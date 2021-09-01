/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Utilities.h"
namespace sdds
{
	class Autoshop{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			auto i = m_vehicles.begin();
			while (i != m_vehicles.end()) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
				i++;
			}
		}
	};
}

#endif
