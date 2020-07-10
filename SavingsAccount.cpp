#include "SavingsAccount.hpp"
#include <iostream>
using namespace std;
//TODO Implement the SavingsAccount class





SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	// TODO implement
	BonusValue.addDollars(10); // Set initial bonus value ($10 dollars)

}



bool SavingsAccount::withdrawMoney(Money amount) {
	// TODO implement
	if(checkwithdrawmoney(amount)){




		if (BonusValue>=200){ //Check if the dollar amount is still positive
			BonusValue.subtractDollars(2);

		}

		balance.subtract(amount);


		return true;
	}


	return false;
}

bool SavingsAccount::depositMoney(Money amount) {

	//Checking if the deposit amount is valid.
	if (checkdepositmoney(amount)){
		if (getBonusValue()>=0){ // Check if that "if" condition is neccessary.


			numberofSavingtransactions++;

			if(numberofSavingtransactions%2==0){
				balance.add(BonusValue);
				balance.add(amount);

			} else{
				balance.add(amount);
			}

			return true;
		}
	}

	return false;


}

bool SavingsAccount::checkwithdrawmoney(Money amount){

	if(amount>=0  && balance>=amount){
		return true;
	}else{
		return false;
	}

}

bool SavingsAccount::checkdepositmoney(Money amount){

	if (amount>=0){
		return true;
	} else{
		return false;
	}

}



Money SavingsAccount::getBonusValue() const {

	return BonusValue;
}

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


