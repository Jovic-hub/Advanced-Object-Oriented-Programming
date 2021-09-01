/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#include <iostream>
#include "Utilities.h"
#include "Utilities.h"
#include <string>
using namespace std;
namespace sdds {
	char Utilities::m_delimiter = ' ';
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string temp = "";
		size_t next = next_pos;
		next_pos = str.find(m_delimiter, next);
		size_t b = -1;
		if (next_pos == b) {
			temp = str.substr(next);
			m_widthField = max(temp.size(), m_widthField);
			more = false;
		}
		else if (next == next_pos) {
			more = false;
			throw "No token.";
		}
		else {
			temp = str.substr(next, next_pos - next);
			m_widthField = max(temp.size(), m_widthField);
			more = true;
		}
		if(temp.size() > m_widthField){
			m_widthField++;
		}
		next_pos++;
		return temp;
	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}