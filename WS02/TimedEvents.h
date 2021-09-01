/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Timed_Event_H 
#define Timed_Event_H 
#include <chrono>
#include <string>
namespace sdds {
	struct Event {
		std::string Name;
		std::string Time;
		std::chrono::steady_clock::duration duration;
	};
	class TimedEvents {
		int Storage = 0;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		Event m_event[10];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char name[] = NULL);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& R);
	};
}
#endif