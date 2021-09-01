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
#include "Autoshop.h"
#include "Autoshop.h"
using namespace std;
namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		auto i = m_vehicles.begin();
		while (i != m_vehicles.end()) {
			(*i)->display(out);
			out << endl;
			i++;
		}
		out << "--------------------------------" << endl;
	}
	Autoshop::~Autoshop() {
		auto i = m_vehicles.begin();
		while (i != m_vehicles.end()) {
			delete *i;
			i++;
		}
	}

}