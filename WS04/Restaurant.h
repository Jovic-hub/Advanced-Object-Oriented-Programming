/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Restaurant_H
#define Restaurant_H
#include<iostream>
#include<string>
#include "Reservation.h"
using namespace std;
namespace sdds {
	class Restaurant {
		Reservation* reservation = nullptr;
		size_t numOfReservations = 0;
	public:
		Restaurant();
		~Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size() const;
		Restaurant& operator=(const Restaurant& source);
		Restaurant(const Restaurant& source);
		Restaurant(Restaurant&& source) noexcept;
		Restaurant& operator=(Restaurant&& source) noexcept;
		friend ostream& operator<<(std::ostream& os, Restaurant& R);
	};
}
#endif