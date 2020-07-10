#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>

FinancialServicesSystem::FinancialServicesSystem() {

}

std::string FinancialServicesSystem::author(){

	return "kzhu904";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {
	if (verifyCustomer(customer->getID())){
		return false;
	}else{
		this->ListofCustomers.push_back(customer);
		return true;
	}
}


bool FinancialServicesSystem::addAccount(Account* account) {

	if(verifyAccount(account->getAccountID())){
		return false;

	} else if (verifyCustomer(account->getCustomerID())==false){
		return false;

	} else{
		this->Listofaccounts.push_back(account);
		return true;
	}

}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {


	if (checkingduplicatetransaction(transaction)){
		return false;
	}
	if ( verifyAccount(transaction->getFromAccount()->getAccountID())&& verifyAccount(transaction->getToAccount()->getAccountID())){

		this->validaccounts=true;
	}
	if (transaction->getState()==PENDING){

		this->validtransaction=true;
	}

	if (this->validaccounts && this->validtransaction){
		this->ListofTransactions.push_back(transaction);
		return true;
	}

	return false;
}

bool FinancialServicesSystem::checkingduplicatetransaction(Transaction* transaction)const{

	//Looping through the ListofTransactions array and check to see if transaction ID are the same.
	for (unsigned int i = 0; i < ListofTransactions.size(); i++) {
		Transaction* existingtransactions = ListofTransactions[i];
		if (existingtransactions->getID()==transaction->getID()){
			return true;
		}

	}
	return false;
}

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {


	std::vector<Transaction*>PendingTransactions=getTransactions(PENDING);
	std::vector<Transaction*>Tobeperformed=sortingPendingTransactionarray(PendingTransactions);
	std::vector<Transaction*>successfultransactions;


	for (unsigned int i = 0; i <Tobeperformed.size(); i++) {

		bool successful=Tobeperformed[i]->performTransaction();

		if (successful){
			successfultransactions.push_back(Tobeperformed[i]);
		}
	}

	return successfultransactions;
}



std::vector<Transaction*> FinancialServicesSystem::sortingPendingTransactionarray(std::vector<Transaction*> array) const{


	int j=0; //j represents number of times to iterate through the whole array
	int sizeArray=array.size(); //Giving how many elements in given pending transaction array
	unsigned int maxindex=array.size()-1;


	while(j< sizeArray){


		for (unsigned int i = 0; i <maxindex; i++) {

			//Comparing the current element with higher element.
			//If the current element is higher than the next element in the array, then swap.
			if(array[i]->getID()>=array[i+1]->getID()){
				Transaction* bigid=array[i];
				array[i]=array[i+1];
				array[i+1]=bigid;
			}
		}
		j++;
	}

	return array;
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {


	std::vector<Account*>ListofAccounts;
	ListofAccounts=getAccounts();
	Money totalbalance;


	for (unsigned int i=0;i<ListofAccounts.size();i++ ){
//Checking if that array belongs to that customer
		if (customerID==ListofAccounts[i]->getCustomerID()){
			Money balance=ListofAccounts[i]->getBalance();

			if (balance<=0){
				//Translate that balance to positive amount and subtract it
				balance.positiveamount(Money(0,-1));
				totalbalance.subtract(balance);
			} else{
				totalbalance.add(balance);
			}

		}
	}

	return totalbalance;
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {

	for (unsigned int i = 0; i < ListofCustomers.size(); i++) {
		Customer* existingcustomer = ListofCustomers[i];
		if (customerID==existingcustomer->getID()){
			return true;
		}
	}
		return false;
}

bool FinancialServicesSystem::verifyAccount(int accountID) const {

	for (unsigned int i = 0; i < Listofaccounts.size(); i++) {
		Account* existingaccount = Listofaccounts[i];
		if (accountID==existingaccount->getAccountID()){
			return true;
		}
	}
	return false;
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {

	for (unsigned int i = 0; i < ListofTransactions.size(); i++) {
		Transaction* existingtransaction = ListofTransactions[i];
		if (transactionID==existingtransaction->getID()){
			return true;
		}
	}
	return false;
}


std::vector<Account*> FinancialServicesSystem::getAccounts() const {

	return Listofaccounts;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	return ListofCustomers;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	return ListofTransactions;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {

	std::vector<Transaction*>ListofstateTransactions;

	for (unsigned int i = 0; i < ListofTransactions.size(); i++) {
			if (ListofTransactions[i]->getState()==state){
				ListofstateTransactions.push_back(ListofTransactions[i]);
			}
	}
	return ListofstateTransactions;
}

FinancialServicesSystem::~FinancialServicesSystem() {

}

