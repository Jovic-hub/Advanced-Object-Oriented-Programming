/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef SetSummable_H
#define SetSummable_H
#include <iostream>
#include "Set.h"
namespace sdds {
	template <int N, typename T>
	class SetSummable : public Set <N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T a(filter);
			for (size_t i = 0; i < this->size(); i++) {
				if (a.isCompatibleWith(this->get(i))) {
					a += this->get(i);
				}
			}
			return a;
		}
	};
}

#endif