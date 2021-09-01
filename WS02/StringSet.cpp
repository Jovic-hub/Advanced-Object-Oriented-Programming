/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "StringSet.h"
#include "StringSet.h"

namespace sdds {
	StringSet::StringSet() {
		FileName = nullptr;
		NumOfStrings = 0;
	}
	StringSet::StringSet(char* file) {
		std::ifstream fi(file);
		int b = 0;
		std::string a;
		while (getline(fi, a, ' ')) {
			b++;
		}
		NumOfStrings = b, FileName = new std::string[b];
		fi.clear(), fi.seekg(0, std::ios::beg);
		b = 0;
		while (fi) {
			getline(fi, FileName[b], ' ');
			b++;
		}
	}
	StringSet::StringSet(const StringSet& source) {
		*this = source;
	}
	StringSet& StringSet::operator=(const StringSet& source) {
		if (this != &source) {
			NumOfStrings = source.NumOfStrings;
			FileName = new std::string[NumOfStrings];
			for (unsigned int i = 0; i < source.NumOfStrings; ++i) {
				FileName[i] = source.FileName[i];
			}
		}
		return *this;
	}
	StringSet::StringSet(StringSet&& source) {
		*this = std::move(source);
	};

	StringSet& StringSet::operator=(StringSet&& source) {

		if (this != &source) {
			FileName = source.FileName;
			source.FileName = nullptr;

			NumOfStrings = source.NumOfStrings;
			source.NumOfStrings = 0;
		}
		return *this;
	}
	StringSet::~StringSet() {
		delete[] FileName;
		FileName = nullptr;
	}
	std::string StringSet::operator[](size_t index) {
		std::string a = "";
		if (index < NumOfStrings) {
			a = FileName[index];
		}
		return a;
	}
	size_t StringSet::size()const {
		return NumOfStrings;
	}
}
