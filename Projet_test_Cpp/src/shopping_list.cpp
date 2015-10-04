#include "shopping_list.hpp"

using namespace std;

// Default constructor
Article::Article() :
_quantity(1), _unit(NULL),
_description(NULL) {

}

// Copy constructor
Article::Article(	const int quant, 
					const string unit,
					const string desc) {
	setQuantity(quant);
	setUnit(unit);
	setDescription(desc);
}

Article::~Article() {

}

bool Article::setQuantity(const int quant) {
	if (quant >= 1) {
		_quantity = quant;
		return true; // Valid output data
	};
	return false;
}

bool Article::setUnit(const string unit) {
	if (!unit.empty()) {
		_unit = unit;
		return true; // Valid output data
	}
	return false;
}

bool Article::setDescription(const string desc) {
	if (!desc.empty()) {
		_description = desc;
		return true; // Valid output data
	}
	return false;
}

int Article::getQuantity() {
	return _quantity;
}

string Article::getUnit() {
	return _unit;
}

string Article::getDescription() {
	return _description;
}

bool Article::init(	const int quant, 
					const string unit,
					const string desc) {
	if (setQuantity(quant) && 
		setUnit(unit) && 
		setDescription(desc)) {
		return true; // Valid output data
	};
	return false;
}

// int Article::retrieve() {

// }