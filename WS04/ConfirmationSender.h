/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef ConfirmationSender_H
#define ConfirmationSender_H
#include<iostream>
#include<string>
#include "Reservation.h"
using namespace std;
namespace sdds {
	class ConfirmationSender {
		const Reservation** reservation = nullptr;
		size_t numOfReservations = 0;
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& source);
		ConfirmationSender& operator=(const ConfirmationSender& source);
		ConfirmationSender(ConfirmationSender&& source) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& source) noexcept;
		bool InTheArray(const Reservation& res);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator<<(std::ostream& os, const ConfirmationSender& R);
	};
}
#endif