/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Linemanager_H
#define Linemanager_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Utilities.h"
#include "Workstation.h"
#include "LineManager.h"

namespace sdds {
	class LineManager {
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;
	public:
		LineManager();
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;

	};
}
#endif