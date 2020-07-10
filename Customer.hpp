#include <string>
#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

class Customer {
private:
	// TODO add members as needed
	const std:: string customername;
	const int id;
	static int nextID;

	Customer& operator=(const Customer &other);
    Customer(const Customer &other);


public:
	Customer(const std::string &name);
	std::string getName() const;
	int getID() const;
	virtual ~Customer();
	bool operator==(const Customer* &other) const;
};

#endif /* CUSTOMER_HPP_ */
