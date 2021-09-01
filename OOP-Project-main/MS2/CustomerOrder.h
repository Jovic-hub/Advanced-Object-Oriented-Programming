/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Customer_Order_H
#define Customer_Order_H
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
#include <algorithm>   
#include <string>
using namespace std;
namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name = "";
		std::string m_product = "";
		size_t m_cntItem = {0};
		Item** m_lstItem = nullptr;

		static size_t m_widthField;
	public:
		CustomerOrder();
		CustomerOrder(string& str);
		CustomerOrder(const CustomerOrder& customer);
		CustomerOrder& operator=(CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&& customer)noexcept;
		CustomerOrder& operator=(CustomerOrder&& customer)noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};

}
#endif