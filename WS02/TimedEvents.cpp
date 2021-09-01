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
#include "TimedEvents.h"
#include "TimedEvents.h"
using namespace std;
namespace sdds {
	TimedEvents::TimedEvents(){
		Storage = 0;
		start = chrono::steady_clock::now();
		end = chrono::steady_clock::now();
	}
	void TimedEvents::startClock(){
		start = chrono::steady_clock::now();
	}
	void TimedEvents::stopClock(){
		end = chrono::steady_clock::now();
	}
	void TimedEvents::addEvent(const char name[]){
		m_event[Storage].Name = name, m_event[Storage].Time = "nanoseconds";
		std::chrono::duration<long, std::nano> time = end - start;
		m_event[Storage].duration = time;
		Storage++;
	}
	ostream& operator<<(ostream& os, const TimedEvents& R) {
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		std::string a = "";
		int i = 0;
		while(R.m_event[i].Name != a) {
			os.width(21);
			os.setf(ios::left);
			os << R.m_event[i].Name;
			os.unsetf(ios::left);
			os.width(13);
			os.setf(ios::right);
			os << R.m_event[i].duration.count() << " " << R.m_event[i].Time << endl;
			os.unsetf(ios::right);
			i++;
		}
		os << "--------------------------" << endl;
		return os;
	}
}
