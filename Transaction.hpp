#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include <string>
#include "Account.hpp"
#include "Money.hpp"

enum TransactionState {
	COMPLETED,
	PENDING,
	FAILED
};

class Transaction {
	//TODO Implement members as needed
private:
	Transaction& operator=(const Transaction &other);
    Transaction(const Transaction &other);
    static int uniqueID;
    Money transactionamount;
    Account* previousAccount=0;
    Account* newAccount=0;
    int transactionID;
    bool validwithdrawAccount=0;
    bool validDepositAccount=0;


public:
	Transaction(Account* fromAccount, Account* toAccount, Money amount);
	bool performTransaction();
	TransactionState getState() const;
	Money getAmount() const;
	Account* getFromAccount() const;
	Account* getToAccount() const;
	TransactionState state;


	int getID() const;
	virtual ~Transaction();
};

#endif /* TRANSACTION_HPP_ */
