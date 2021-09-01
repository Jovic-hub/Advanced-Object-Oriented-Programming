/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#include <iostream>
#include <algorithm>
#include "CustomerOrder.h"
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder() :m_name{ "" }, m_product{ "" }, m_cntItem{ 0 }, m_lstItem{ nullptr }{}

	CustomerOrder::CustomerOrder(string& str){
		Utilities m_uti;
		bool check = true;
		size_t delimiter = 0;
		m_cntItem = 0;

		m_name = m_uti.extractToken(str, delimiter, check);
		m_product = m_uti.extractToken(str, delimiter, check);
		size_t next_delimiter = delimiter;

		for (size_t i = 1; check; i++) {
			m_uti.extractToken(str, delimiter, check);
			m_cntItem = i;
		}
		m_lstItem = new Item * [m_cntItem];
		for (size_t j = 0; j < m_cntItem; j++) {
			m_lstItem[j] = new Item(m_uti.extractToken(str, next_delimiter, check));
		}
		if (m_widthField < m_uti.getFieldWidth()) {
			m_widthField = m_uti.getFieldWidth();
		}
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& customer){
		throw string("No copy");
	}	
	CustomerOrder::CustomerOrder(CustomerOrder&& customer) noexcept {
		*this = move(customer);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& customer) noexcept{
		if (this != &customer) {
			delete[] m_lstItem;
			m_name = customer.m_name;
			m_product = customer.m_product;
			m_cntItem = customer.m_cntItem;
			m_lstItem = customer.m_lstItem;
			customer.m_lstItem = nullptr;
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder(){
		delete[]m_lstItem;
		m_lstItem = nullptr;
	}
	bool CustomerOrder::isFilled() const{
		bool ok = true;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				ok = false;
			}
		}
		return ok;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const{
		bool ok = true;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				if (m_lstItem[i]->m_isFilled) {
					ok = true;
				}
				else {
					ok = false;
				}
			}
		}
		return ok;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (station.getItemName() == m_lstItem[i]->m_itemName) {
				if (station.getQuantity() == 0) {
					os << setw(11) << setfill(' ') << right << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << setw(11) << setfill(' ') << right << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]"<< endl;
				}
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const {
		if (m_name != "") {
			os << m_name << " - " << m_product << endl;
		}
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << setfill(' ') << "]"<< left << " " << setw(m_widthField) << m_lstItem[i]->m_itemName;
			if (!m_lstItem[i]->m_isFilled) {
				os << " - TO BE FILLED" << endl;
			}
			else {
				os << " - FILLED" << endl;
			}
		}
	}
}