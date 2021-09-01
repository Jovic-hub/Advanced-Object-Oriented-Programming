/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <sstream>
#include <iostream>
#include "Utilities.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* ok = nullptr;
		string check;
		char type = '\0';
		getline(in, check);
		stringstream x(check);
		x >> type;
		if (!check.empty()) {
			if (type == 'C' || type == 'c') {
				ok = new Car(x);
			}
			else if (type == 'R' || type ==  'r') {
				ok = new Racecar(x);
			}
			else {
				throw type;
			}
		}
		return ok;
	}
}

