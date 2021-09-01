/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Station_H
#define Station_H
#include<iostream>
#include <iomanip>
#include "Utilities.h"
#include <algorithm>   
#include<string>
using namespace std;
namespace sdds {
	class Station {
		int m_id;
		string m_name;
		string m_des;
		unsigned int m_serial;
		unsigned int m_stock;

		static size_t m_widthField;
		static int id_generator;
	public:
		Station() {

		}
		Station(const string& file);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void display(std::ostream& os, bool full) const;
		void updateQuantity();
	};

}
#endif