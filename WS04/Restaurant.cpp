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
#include "Restaurant.h"
#include "Restaurant.h"

using namespace std;
namespace sdds {
	Restaurant::Restaurant() {
		reservation = nullptr;
		numOfReservations = 0;
	}

	Restaurant::~Restaurant() {
		delete[] reservation;
		reservation = nullptr;
		numOfReservations = 0;
	}

	Restaurant::Restaurant(const sdds::Reservation* reservations[], size_t cnt) {
		reservation = new Reservation[cnt];
		numOfReservations = cnt;
		size_t i = 0;
		while (i < cnt) {
			reservation[i] = *reservations[i];
			i++;
		}
	}

	Restaurant::Restaurant(const Restaurant& source) {
		*this = source;
	}
	Restaurant& Restaurant::operator=(const Restaurant& source) {
		if (this != &source) {
			numOfReservations = source.numOfReservations;
			size_t i = 0;
			reservation = new Reservation[numOfReservations];
			while (i < numOfReservations) {
				reservation[i] = source.reservation[i];
				i++;
			}
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& source) noexcept {
		*this = move(source);
	}

	Restaurant& Restaurant::operator=(Restaurant&& source) noexcept {
		if (this != &source) {
			reservation = source.reservation;
			source.reservation = nullptr;
			numOfReservations = source.numOfReservations;
			source.numOfReservations = 0;
		}
		return *this;
	}


	size_t Restaurant::size() const {
		return numOfReservations;
	}

	ostream& operator<<(ostream& os, Restaurant& R) {
		static size_t i = 0;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant " << "(" << ++i << ")" << endl;			
		os << "--------------------------" << endl;
		if (R.numOfReservations > 0) {
			for (size_t i = 0; i < R.numOfReservations; i++) {
				os << R.reservation[i];
			}
		}
		else {
			os << "This restaurant is empty!" << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}