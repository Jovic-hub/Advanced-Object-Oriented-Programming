/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#include <iostream>
#include <algorithm>
#include "Station.h"
#include "Station.h"
using namespace std;
namespace sdds {
	size_t Station::m_widthField = 0;
	int Station::id_generator = 1;

	Station::Station(const string& file) {
		Utilities m_uti;
		size_t next_pos = 0;
		bool check = true;
		m_id = id_generator;
		m_name = m_uti.extractToken(file, next_pos, check);
		m_serial = stoi(m_uti.extractToken(file, next_pos, check));
		m_stock = stoi(m_uti.extractToken(file, next_pos, check));
		m_widthField = max(m_uti.getFieldWidth(), m_widthField);
		m_des = m_uti.extractToken(file, next_pos, check);
		id_generator++;
	}
	const std::string& Station::getItemName() const {
		return m_name;
	}
	size_t Station::getNextSerialNumber() {
		return m_serial++;
	}
	size_t Station::getQuantity() const {
		return m_stock;
	}
	void Station::display(std::ostream& os, bool full) const {
		if (!full) {
			os << "[" << setw(3) << setfill('0') << m_id << setfill(' ') << "] " <<	"Item: " << left << setw(m_widthField) << m_name << right << " [" << setw(6) << setfill('0') << m_serial << "]" << setfill(' ') << endl;
		}
		else {
			os << "[" << setw(3) << setfill('0') << right << m_id << setfill(' ') << "] " << "Item: " << left << setw(m_widthField) << m_name << right << " [" << setw(6) << setfill('0') << m_serial << "] " << setfill(' ') << "Quantity: " << left << setw(15) << m_stock <<  "Description: " << left << m_des <<endl;
		}
	}
	void Station::updateQuantity() {
		if (m_stock > 0) {
			m_stock--;
		}
	}
}