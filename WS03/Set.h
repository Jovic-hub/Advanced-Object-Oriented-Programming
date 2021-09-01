/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Set_H
#define Set_H
#include <iostream>
namespace sdds {
	template <int N, typename T>
	class Set {
		size_t total_number = 0;
		T m_get[N];
	public:
		size_t size() const {
			return total_number;
		}
		const T& get(size_t idx) const {
			return m_get[idx];
		}
		void operator+=(const T& item) {
			if (total_number < N) {
				m_get[total_number] = item;
				total_number++;
			}
		}
	};
}

#endif