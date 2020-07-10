#include "Account.hpp"
#include <iostream>

#ifndef SAVINGSACCOUNT_HPP_
#define SAVINGSACCOUNT_HPP_

class SavingsAccount : public Account {
	//TODO Implement members as needed


private:
	SavingsAccount& operator=(const SavingsAccount &other);

	SavingsAccount(const SavingsAccount &other);
	int numberofSavingtransactions=0;
	Money BonusValue;
public:
	SavingsAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	Money getBonusValue() const;
	bool checkwithdrawmoney(Money amount);
	bool checkdepositmoney(Money amount);


	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_HPP_ */
