#include "Customer.hpp"
#include <string>

int Customer::nextID=0;

Customer::Customer(const std::string &name): customername(name), id(nextID++)  {}

std::string Customer::getName() const {
	// TODO implement
	return this->customername;
}

int Customer::getID() const {
	// TODO implement
	return id;
}


// This operator is used to check if the customer are the same
bool Customer::operator==(const Customer* &other) const {
	bool sameName = this->customername == other->customername;
	bool sameID = this->id == other->id;
	return sameName&&sameID;
}

Customer::~Customer() {

}

