#ifndef FINANCIALSERVICESSYSTEM_HPP_
#define FINANCIALSERVICESSYSTEM_HPP_


#include "Customer.hpp"
#include "Account.hpp"
#include "Transaction.hpp"
#include "Money.hpp"
#include <vector>
#include <iostream>


class FinancialServicesSystem {
//TODO Add members as needed
private:
	
	std::vector<Account*>Listofaccounts;
	std::vector<Customer*>ListofCustomers;
	std::vector<Transaction*>ListofTransactions;

	bool validaccounts=0;
	bool validtransaction=0;
	Money totalbalance;





public:
	FinancialServicesSystem();
	static std::string author();
	bool addCustomer(Customer* customer);
	bool addAccount(Account* account);
	bool addTransaction(Transaction* transaction);

	std::vector<Transaction*> performPendingTransactions();
	Money getCustomerBalance(int customerID) const;

	bool verifyCustomer(int customerID) const;
	bool verifyAccount(int accountID) const;
	bool verifyTransaction(int transactionID) const;
	bool checkingduplicatetransaction(Transaction* transaction) const;
	bool operator==(const Customer* &other) const;

	std::vector<Account*> getAccounts() const;
	std::vector<Customer*> getCustomers() const;
	std::vector<Transaction*> getTransactions() const;
	std::vector<Transaction*> getTransactions(TransactionState state) const;
	std::vector<Transaction*> sortingPendingTransactionarray(std::vector<Transaction*>array) const;


	virtual ~FinancialServicesSystem();
};

#endif /* FINANCIALSERVICESSYSTEM_HPP_ */
