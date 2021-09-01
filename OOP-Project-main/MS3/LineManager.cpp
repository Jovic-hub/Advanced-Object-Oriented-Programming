/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#include <iostream>
#include "Utilities.h"
#include "Workstation.h"
#include "LineManager.h"

using namespace std;
namespace sdds {

	LineManager::LineManager(){
		m_cntCustomerOrder = 0;
		m_firstStation = nullptr;
	}

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {

		ifstream file_a(file);
		string str;
		bool ok = true;
		size_t counter = 0;
		m_cntCustomerOrder = pending.size();

		while (getline(file_a, str)) {
			size_t check = str.find('|');
			size_t i = 0;
			while (i < stations.size()) {
				if (stations[i]->getItemName() == str.substr(0, check)) {
					if (check == SIZE_MAX) {
						activeLine.push_back(std::move(stations[i]));
					}
					else {
						size_t j = 0;
						while(j < stations.size()) {
							if (stations[j]->getItemName() == str.substr(check + 1)) {
								stations[i]->setNextStation(stations[j]);
								activeLine.push_back(std::move(stations[i]));
							}
							j++;
						}
					}
				}
				i++;
			}
			size_t a = 0;
			while(a < activeLine.size()) {
				size_t b = 0;
				while(b < activeLine.size()) {
					if (activeLine[b]->getNextStation() != nullptr) {
						if (activeLine[a]->getItemName() == activeLine[b]->getNextStation()->getItemName()) {
							ok = false;
						}
					}
					b++;
				}
				if (ok) {
					m_firstStation = activeLine[a];
				}
				a++;
				ok = true;
			}
			counter++;
		}

	}

	void LineManager::linkStations() {
		Workstation* current_station = m_firstStation;
		vector<Workstation*> work;

		for (size_t i = 0; current_station != nullptr; i++) {
			work.push_back(current_station);
			current_station = current_station->getNextStation();
			activeLine = work;
		}
	}

	size_t counter = 1;
	bool LineManager::run(std::ostream& os) {
		os << "Line Manager Iteration: " << counter++ << endl;
		if (!pending.empty()) {
			*activeLine.front() += std::move(pending.front());
			pending.erase(pending.begin());
		}

		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* work) {
			work->fill(os);
		});
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* work) {
			work->attemptToMoveOrder();
		});

		m_cntCustomerOrder -= ((completed.size() + incomplete.size()) - completed.size() + incomplete.size());
		return m_cntCustomerOrder <= 3;
	}

	void LineManager::display(std::ostream& os) const {
		size_t a = activeLine.size();
		for (size_t i = 0; i < a; i++) {
			activeLine[i]->display(os);
		}
	}

}