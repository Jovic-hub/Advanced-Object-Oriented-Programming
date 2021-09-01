/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<string>
#include "Car.h"
#include "Car.h"
using namespace std;
namespace sdds {
	Car::Car() {
		m_maker = nullptr;
		m_condition = nullptr;
		m_topSpeed = 0;
	}
	Car::Car(std::istream& car) {
		string tag, cond, maxSpeed, mak;
		getline(car, tag, ',');
		getline(car, mak, ',');
		mak.erase(0, mak.find_first_not_of(' '));
		mak.erase(mak.find_last_not_of(' ') + 1);
		m_maker = mak;

		getline(car, cond, ',');
		cond.erase(0, cond.find_first_not_of(' '));
		cond.erase(cond.find_last_not_of(' ') + 1);
		if (cond == "" || cond == "n" || cond == "N") {
			cond = "n";
		}
		else if (cond == "U" || cond == "u") {
			cond = "u";
		}
		else if (cond == "B" || cond == "b") {
			cond = "b";
		}
		else {
			throw std::string("Invalid record!");
		}
		m_condition = cond;
		
		getline(car, maxSpeed, ',');
		maxSpeed.erase(0, maxSpeed.find_first_not_of(' '));
		maxSpeed.erase(maxSpeed.find_last_not_of(' ') + 1);
		try {
			m_topSpeed = std::stod(maxSpeed);
		}
		catch (...)
		{
			throw std::string("Invalid record!");
		}

	}
	std::string Car::condition() const {
		string cond;
		if (m_condition == "n") {
			cond = "new";
		}
		else if (m_condition == "u") {
			cond = "used";
		}
		else if (m_condition == "b") {
			cond = "broken";
		}
		return cond;
	}
	double Car::topSpeed() const {
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const {
		out << "| " << setw(10) << m_maker << " | ";
		out.setf(ios::left);
		out << setw(6) << condition() << " | " << setw(6);
		out << setprecision(2) << fixed << topSpeed() << " |";
		out.unsetf(ios::left);
	}
}