
#include "Money.hpp"

Money::Money() : totalCents(0) {
}

Money::Money(int dollars, int cents) {

	this->totalCents = dollars*100 + cents;
}

bool operator>=(const Money &amount, const int &a){

	return amount.asCents()>=a;
}

 //Comparing two & money objects
bool operator>=(const Money &amount, const Money &a){

	return amount.asCents()>=a.asCents();
}

int operator+(const Money &amount, const Money *a){ //One with money object as a pointer

	return amount.asCents()+a->asCents();
}

int operator+(const Money &amount, const Money a){ //One with money object

	return amount.asCents()+a.asCents();
}

bool operator<=(const Money &amount, const int &a){

	return amount.asCents()<=a;
}

int Money::getDollars() const {
	return totalCents/100;
}

int Money::getCents() const {
	return totalCents%100;
}

int Money::asCents() const {
	return totalCents;
}

void Money::addDollars(int dollars) {
	if (dollars > 0) {
		this->totalCents += dollars*100;
	}
}

void Money::addCents(int cents) {
	if (cents > 0) {
		this->totalCents += cents;
	}
}

void Money::subtractDollars(int dollars) {
	if (dollars > 0) {
		this->totalCents -= dollars*100;
	}
}

void Money::subtractCents(int cents) {
	if (cents >=0) {
		this->totalCents -= cents;
	}
}

void Money::add(const Money &other) {
	if (other.totalCents>=0){
		this->totalCents += other.totalCents;
	}
}

void Money::subtract(const Money &other) {
	if (other.totalCents>=0) {
		this->totalCents -= other.totalCents;
	}
}

void Money::split(Money &other) {
	int newTotal = (this->totalCents + other.totalCents)/2;
	this->totalCents = newTotal;
	other.totalCents = newTotal;
}

void Money::positiveamount(const Money &other){

	this->totalCents *= other.totalCents;

}

Money::~Money() {
}
