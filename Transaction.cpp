#include "Transaction.hpp"
#include <string>

int Transaction::uniqueID=1;


Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount): transactionID(uniqueID++)  {

	transactionamount=amount;
	previousAccount=fromAccount;
	newAccount=toAccount;

	//If the amount is negative, then set the amount to equal 0

	if (amount<=0){
		transactionamount=Money(0,0);
	}

	state=PENDING;
}

bool Transaction::performTransaction(){

	validwithdrawAccount=previousAccount->checkwithdrawmoney(transactionamount);
	validDepositAccount=newAccount->checkdepositmoney(transactionamount);

	//If both are valid, then perform the transaction
	if (validwithdrawAccount && validDepositAccount){

		previousAccount->withdrawMoney(transactionamount);
		newAccount->depositMoney(transactionamount);
		state=COMPLETED;
		return true;


	}

	state=FAILED;
	return false;

}

TransactionState Transaction::getState() const {

	return state;
}

Money Transaction::getAmount() const {

	return transactionamount;
}

Account* Transaction::getToAccount() const {

	return newAccount;
}

Account* Transaction::getFromAccount() const {

	return previousAccount;
}

int Transaction::getID() const {

	return transactionID;
}

Transaction::~Transaction() {

}

