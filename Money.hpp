
#ifndef MONEY_H_
#define MONEY_H_

class Money {
private:
	int totalCents;
public:
	Money();
	Money(int dollars, int cents);

	int getDollars() const;
	int getCents() const;
	int asCents() const;
	friend bool operator>=(const Money &amount, const int &a);
	friend bool operator<=(const Money &amount, const int &a);
	friend bool operator>=(const Money &amount, const Money &a);
	friend int operator+(const Money &amount, const Money *a);
	friend int operator+(const Money &amount, const Money a);

	void addDollars(int dollars);
	void addCents(int cents);
	void subtractDollars(int dollars);
	void subtractCents(int cents);
	void positiveamount(const Money &other);

	void add(const Money &other);
	void subtract(const Money &other);
	void split(Money &other);

	virtual ~Money();
};

#endif /* MONEY_H_ */
