/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#include <iostream>
#include "Workstation.h"

using namespace std;

std::vector<sdds::CustomerOrder> pending;
std::vector<sdds::CustomerOrder> completed;
std::vector<sdds::CustomerOrder> incomplete;

namespace sdds {

	Workstation::Workstation(){
		m_pNextStation = nullptr;
	}

	Workstation::Workstation(const string& str) : Station(str){
		m_pNextStation = nullptr;
	}

	void Workstation::fill(std::ostream& os) {
		if(!m_orders.empty()) {
			m_orders.begin()->fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder() {
		bool ok = false;
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() < 1) {
				if (m_pNextStation == nullptr) {
					if (!m_orders.front().isFilled()) {
						incomplete.push_back(std::move(m_orders.front()));
					}
					else {
						completed.push_back(std::move(m_orders.front()));
					}
					m_orders.erase(m_orders.begin());
				}
				else {
					*m_pNextStation += move(m_orders.front());
					m_orders.erase(m_orders.begin());
				}
				ok = true;
			}
		}
		return ok;
	}

	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		os << getItemName() << " --> ";
		if (m_pNextStation != nullptr) {
			os << m_pNextStation->getItemName();
		}
		else {
			os << "End of Line";
		}
		os << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

}