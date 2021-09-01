/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef PairSummable_H
#define PairSummable_H
#include <iostream>
#include "Pair.h"
namespace sdds {
	template <typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initialValue;
		static size_t min_field;
	public:
		PairSummable() {}
		PairSummable(const K& key, const V& value = initialValue): Pair<V, K>(key, value) {
			if (min_field < key.size()) {
				min_field = key.size() + 1;
			}
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			bool a = false;
			if (this -> key() == b.key()) {
				a = true;
			}
			return a;
		}
		PairSummable& operator+=(const PairSummable<V, K>& obj) {
		if (Pair<V, K>::key() == obj.key()) {
			PairSummable add(Pair<V, K>::key(), Pair<V, K>::value() + obj.value());
			*this = add;
		}
		return *this;
		}
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(min_field);
			Pair<V, K>::display(os);
			os.unsetf(std::ios::left);

		}
	};

	template<typename V, typename K>
	size_t PairSummable <V, K> ::min_field = 0;

	template<>int PairSummable<int, std::string>::initialValue = 0;
	template<>std::string PairSummable <std::string, std::string>::initialValue = "";

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable& obj) {
		std::string empty = "";
		if (value() == empty) {
			PairSummable<std::string, std::string> add(key(), value() + obj.value());
			*this = add;
		}
		else if (value() != empty){
			PairSummable<std::string, std::string> add(key(), value() +", " + obj.value());
			*this = add;
		}
		return *this;
	}
}
#endif