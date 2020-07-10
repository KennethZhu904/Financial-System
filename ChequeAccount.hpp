#include "Account.hpp"

#ifndef CHEQUEACCOUNT_HPP_
#define CHEQUEACCOUNT_HPP_

class ChequeAccount : public Account {
//TODO Implement members as needed
private:
	ChequeAccount& operator=(const ChequeAccount &other);
    ChequeAccount(const ChequeAccount &other);
    Money* transactionfee=new Money(0,0);
    int totalwithdrawnamount=0;
public:
	ChequeAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	bool checkwithdrawmoney(Money amount);
	bool checkdepositmoney(Money amount);
	Money* getTransactionFee() const;
	virtual ~ChequeAccount();
};

#endif /* CHEQUEACCOUNT_HPP_ */
