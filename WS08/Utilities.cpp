// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#include <memory>
#include <vector>
#include <string>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		int desc_size = desc.size();
		int price_size = price.size();
		int i = 0;
		while (i < desc_size) {
			int j = 0;
			while (j < price_size) {
				if (desc[i].code == price[j].code) {
					Product* product = new Product(desc[i].desc, price[j].price);
					product->validate();
					priceList += product;
					delete product;
				}
				j++;
			}
			i++;
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		int desc_size = desc.size();
		int price_size = price.size();
		int i = 0;
		while(i < desc_size){
			int j = 0;
			while (j < price_size) {
				if (desc[i].code == price[j].code) {
					shared_ptr<Product> product{ 
						new Product(desc[i].desc, price[j].price) 
					};
					product->validate();
					priceList += product;
				}
				j++;
			}
			i++;
		}
		return priceList;
	}
}