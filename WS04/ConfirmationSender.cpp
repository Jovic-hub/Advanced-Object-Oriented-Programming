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
#include "ConfirmationSender.h"
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		reservation =  nullptr ;
		numOfReservations = 0 ;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] reservation;
		reservation = nullptr;
		numOfReservations = 0;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& source) {
		*this = source;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& source) {
		if (this != &source) {
			numOfReservations = source.numOfReservations;
			delete[] reservation;
			reservation = new const Reservation * [numOfReservations];
			size_t i = 0;
			while (i < numOfReservations) {
				reservation[i] = source.reservation[i];
				i++;
			}

		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& source) noexcept  {
		*this = move(source);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& source) noexcept {
		if (this != &source) {
			numOfReservations = source.numOfReservations;
			source.numOfReservations = 0;
			reservation = source.reservation;
			source.reservation = nullptr;
		}
		return *this;
	}
	bool ConfirmationSender::InTheArray(const Reservation& res) {
		bool found = false;
		for (size_t i = 0; i < numOfReservations; i++) {
			if (reservation[i] == &res) {
				found = true;
			}
		}
		return found;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		if (!InTheArray(res)) {
			const Reservation** a = nullptr;
			a = new const Reservation* [numOfReservations + 1];
			for (size_t i = 0; i < numOfReservations; i++) {
				a[i] = reservation[i];
			}
			a[numOfReservations] = &res;
			reservation = a;
			numOfReservations++;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool found = false;
		size_t j = 0;
		for (size_t i = 0; i < numOfReservations; i++) {
			if (reservation[i] == &res) {
				found = true;
				j = i - 1;
			}
		}
		if (found) {
			const Reservation** a = nullptr;
			a = new const Reservation* [numOfReservations - 1];
			for (size_t i = 0; i < (numOfReservations - 1); i++) {
				if (i > j) {
					a[i] = reservation[i + 1];
				}
				else {
					a[i] = reservation[i];
				}
			}
			numOfReservations--;
			reservation = a;
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& R) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (R.numOfReservations > 0) {
			for (size_t i = 0; i < R.numOfReservations; i++) {
				if (R.reservation[i] != nullptr) {
					os << *R.reservation[i];
				}
			}
		}
		else {
			os << "There are no confirmations to send!" << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}