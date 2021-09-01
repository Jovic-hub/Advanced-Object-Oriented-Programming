///**********************************************************
// * Name: Joao Victor Fernandes dos Santos
// * Student ID:155858194
// * Seneca email: jvfernandes-dos-sant@myseneca.ca
// * Section: OOP345 - NFF
// **********************************************************/
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstring>
//#include "event.h"
//#include "event.h"
//
//extern unsigned int g_sysClock;
//namespace sdds {
//	Event::Event() {
//		description = nullptr;
//		seconds = 0;
//	}
//	Event::~Event() {
//		delete[]description;
//		description = nullptr;
//	}
//	void Event::display() {
//		static int counter = 0;
//		counter++;
//		if (counter < 10) {
//			std::cout << " " << counter << ". ";
//		}
//		else {
//			std::cout << counter << ". ";
//		}
//		char column[] = ":";
//		if (description[0] != 'e') {
//			int HH = 0, MM = 0, SS = 0, total_minutes = 0;
//			total_minutes = seconds / 60;
//			SS = seconds % 60;
//			HH = total_minutes / 60;
//			MM = total_minutes % 60;
//			if (HH < 10) {
//				std::cout << 0 << HH;
//			}
//			else {
//				std::cout << HH;
//			}
//			std::cout << column;
//			if (MM < 10) {
//				std::cout << 0 << MM;
//			}
//			else {
//				std::cout << MM;
//			}
//			std::cout << column;
//			if (SS < 10) {
//				std::cout << 0 << SS;
//			}
//			else {
//				std::cout << SS;
//			}
//			std::cout << " => " << description;
//			std::cout << std::endl;
//		}
//		else {
//			std::cout << "| No Event |" << std::endl;
//		}
//	}
//	void Event::set(char address[]) {
//		const char* empty = "e";
//		if (address != NULL && address[0] != '\0') {
//			delete[]description;
//			description = nullptr;
//			description = new char[strlen(address) + 1];
//			strcpy(description, address);
//			seconds = g_sysClock;
//		}
//		else {
//			strcpy(this->description, empty);
//		}
//	}
//	Event::Event(const Event& R) {
//		operator=(R);
//	}
//	Event& Event::operator=(const Event& R){
//		if (this != &R) {
//			if (R.description != nullptr) {
//				seconds = R.seconds;
//				delete[]description;
//				description = nullptr;
//				description = new char[strlen(R.description) + 1];
//				strcpy(description, R.description);
//			}
//			else {
//				delete[]description;
//				description = nullptr;
//				seconds = 0;
//			}
//		}
//		return *this;
//	}
//}