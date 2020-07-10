#include "Account.hpp"


int Account::nextAccountID=0;

Account::Account(const int customerID): AccountID(nextAccountID++),CustomerID(customerID) { }

int Account::getAccountID() const {
	return AccountID;
}

int Account::getCustomerID() const {
	return CustomerID;
}

Money Account::getBalance() const {
	return balance;
}

Account::~Account() {

}

