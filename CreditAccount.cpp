#include "CreditAccount.hpp"
//TODO Implement CreditAccount class

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {

}

bool CreditAccount::withdrawMoney(Money amount) {


	if(checkwithdrawmoney(amount)){
		balance.subtract(amount);
		return true;
	}

	return false;
}

bool CreditAccount::depositMoney(Money amount) {
	// TODO implement

	if (checkdepositmoney(amount)){
		balance.add(amount);
		return true;
	}


	return false;
}

bool CreditAccount::checkwithdrawmoney(Money amount){
	if(amount>=0){

		return true;
	}

	return false;

}


bool CreditAccount::checkdepositmoney(Money amount){

	//Check if deposit is positive and below 5000 dollars
	if (amount>=0 && amount+balance<=500000){

		return true;
	}
	return false;
}


CreditAccount::~CreditAccount() {

}
