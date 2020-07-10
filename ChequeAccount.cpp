#include "ChequeAccount.hpp"
//TODO Implement ChequeAccount class

ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {
	transactionfee->addDollars(1); //initialise transaction fee to $1
}

bool ChequeAccount::withdrawMoney(Money amount) {
	// TODO implement
	//return false;


	if(checkwithdrawmoney(amount)){
		balance.subtract(amount);
		balance.subtract(*getTransactionFee());
		transactionfee->addDollars(1);
		return true;
	}

	return false;
}

bool ChequeAccount::depositMoney(Money amount) {
	if (checkdepositmoney(amount)){ //check if the deposit exceeds $3000 (in asCents)

		balance.add(amount);

		return true;

	}

	return false;
}

Money* ChequeAccount::getTransactionFee() const {
	// TODO implement
	return transactionfee;
}

bool ChequeAccount::checkwithdrawmoney(Money amount){

	totalwithdrawnamount=amount+transactionfee;

	if(amount>=0  && balance>=totalwithdrawnamount){

		return true;
	}
	return false;

}

bool ChequeAccount::checkdepositmoney(Money amount){

	if (amount>=0 && amount<=300000){ //check if the deposit exceeds $3000 (in asCents)
		return true;
	}

	return false;
}

ChequeAccount::~ChequeAccount() {

	delete transactionfee;
}

