/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef String_Set_H
#define String_Set_H
#include <chrono>
#include <string>
namespace sdds {
	class StringSet {
		std::string * FileName;
		unsigned int NumOfStrings;
	public:
		StringSet();
		StringSet(char*);
		StringSet(const StringSet& source);
		StringSet& operator=(const StringSet& source);
		StringSet(StringSet&& source);
		StringSet& operator=(StringSet&& source);
		~StringSet();
		std::string operator[](size_t);
		size_t size()const;
	};
}
#endif