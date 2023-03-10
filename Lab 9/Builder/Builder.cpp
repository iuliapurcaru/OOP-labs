#include <iostream>
#include <string>

using namespace std;

// Builder

class Builder 
{
public:

	virtual void Reset() = 0;

	virtual void getBread() = 0;
	virtual void getMeat() = 0;
	virtual void getCheese() = 0;
	virtual void getSalad() = 0;
	virtual void getSauce() = 0;

	virtual void getTomatoes() {};
	virtual void getPickles() {};
	virtual void getOnions() {};
};

// Product

class Burger
{
public:

	void listIngredients(string ingredient)
	{
		cout << ingredient << endl;
	}
};

// ConcreteBuilder1

class BigMacBuilder : public Builder
{
private:

	Burger* BigMac;

public:

	BigMacBuilder() 
	{
		this->Reset();
	}

	~BigMacBuilder()
	{
		delete BigMac;
	}

	void Reset() 
	{
		BigMac = new Burger();
	}

	void getBread()
	{
		this->BigMac->listIngredients("bread");
	}

	void getMeat()
	{
		this->BigMac->listIngredients("meat");
	}

	void getCheese()
	{
		this->BigMac->listIngredients("cheese");
	}

	void getSauce()
	{
		this->BigMac->listIngredients("sauce");
	}

	void getSalad()
	{
		this->BigMac->listIngredients("salad");
	}

	void getPickles()
	{
		this->BigMac->listIngredients("pickles");
	}

	Burger* getProduct() 
	{
		Burger* result = this->BigMac;
		this->Reset();
		return result;
	}

};

// ConcreteBuilder2

class BigTastyBuilder : public Builder
{
private:

	Burger* BigTasty;

public:

	BigTastyBuilder()
	{
		this->Reset();
	}

	~BigTastyBuilder()
	{
		delete BigTasty;
	}

	void Reset()
	{
		BigTasty = new Burger();
	}

	void getBread()
	{
		this->BigTasty->listIngredients("bread");
	}

	void getMeat()
	{
		this->BigTasty->listIngredients("meat");
	}

	void getCheese()
	{
		this->BigTasty->listIngredients("cheese");
	}

	void getSauce()
	{
		this->BigTasty->listIngredients("sauce");
	}

	void getSalad()
	{
		this->BigTasty->listIngredients("salad");
	}

	void getOnions()
	{
		this->BigTasty->listIngredients("onions");
	}

	void getTomatoes()
	{
		this->BigTasty->listIngredients("tomatoes");
	}

	Burger* getProduct()
	{
		Burger* result = this->BigTasty;
		this->Reset();
		return result;
	}
};

class Director 
{
private:

	Builder* burger;

public:

	void set_builder(Builder* burger)
	{
		this->burger = burger;
	}

	void BuildBigMac() 
	{
		this->burger->getBread();
		this->burger->getMeat();
		this->burger->getPickles();
		this->burger->getSauce();
		this->burger->getSalad();
		this->burger->getBread();
		this->burger->getMeat();
		this->burger->getSauce();
		this->burger->getSalad();
		this->burger->getCheese();
		this->burger->getBread();
	}

	void BuildBigTasty() 
	{
		this->burger->getBread();
		this->burger->getSauce();
		this->burger->getSalad();
		this->burger->getOnions();
		this->burger->getTomatoes();
		this->burger->getMeat();
		this->burger->getCheese();
		this->burger->getBread();
	}
};

int main() 
{
	Director director;

	cout << "Burger Big Mac:" << endl;
	BigMacBuilder* BigMac = new BigMacBuilder();
	director.set_builder(BigMac);
	director.BuildBigMac();

	cout << endl;
	
	cout << "Burger Big Tasty:" << endl;
	BigTastyBuilder* BigTasty = new BigTastyBuilder();
	director.set_builder(BigTasty);
	director.BuildBigTasty();

	return 0;

	/*
	Avantaje:
	- codul de constructie al obiectelor este incapsulat si doar produsul final este disponibil pentru utilizator
	- ofera control mai usor asupra modului de contructie
	
	Dezavantaje:
	- trebuie sa existe un builder specific pentru fiecare tip de produs si acest inseamna un volum mai mare de cod
	*/
}
