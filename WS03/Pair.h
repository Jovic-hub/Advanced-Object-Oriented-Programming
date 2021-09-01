/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Pair_H
#define Pair_H
#include <iostream>
namespace sdds {
	template <typename V, typename K>
	class Pair {
		V m_value;
		K m_key;
	public:
		Pair():m_value{}, m_key{}{}
		Pair(const K& key, const V& value) : m_value(value), m_key(key){}
		const V& value() const {
			return m_value;
		}
		const K& key() const {
			return m_key;
		}
		virtual void display(std::ostream& os) const {
			os << m_key << ": " << m_value << std::endl;
		}
	};
	template <typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}
}
#endif