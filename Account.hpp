#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_
#include "Money.hpp"
class Account{
//TODO Implement members as needed
private:
	Account& operator=(const Account &other);
	Account(const Account &other);
	const int AccountID;
	static int nextAccountID;
	const int CustomerID;

protected:
	Money balance;
public:
	Account(const int customerID);
	virtual bool withdrawMoney(Money amount) = 0;
	virtual bool depositMoney(Money amount) = 0;
	virtual bool checkwithdrawmoney(Money amount)=0;
	virtual bool checkdepositmoney(Money amount)=0;
	int getCustomerID() const;
	int getAccountID() const;
	Money getBalance() const;
	virtual ~Account();
};

#endif /* ACCOUNT_HPP_ */
