#include "Visitor.h"

	Visitor::Visitor()
	{
		name = "You";
		money = 0;
		card = 0.0;
		cout << "Welcome In Cinema Alpha" << endl;
	}
	void Visitor::Withdrawmoney(int x)
	{
		if (this->card >= x)
		{
			this->card -= x;
			this->money += x;
			cout << "You have " << money << "UAH" << endl;
			cout << "On your bank card remains: " << card << "UAH" << endl;
		}
		else
		{
			cout << "You do not have enough money on card" << endl;
		}
		getchar();
	}

	int Visitor::Getmoney()
	{
		return money;
	}

	float Visitor::Getcard()
	{
		return card;
	}
	

	void Visitor::Buyticket(int cost, int index)
	{
		if (this->money > cost)
		{
			this->money -= cost;
			tickets[index] += 1;
			cout << "You have " << tickets[index] << " tickets on this film" << endl;
		}
		else
		{

			cout << "You do not have enough money." << endl;
			cout << " You can withdraw your money in our Bar!" << endl;
		}
	}

	Visitor::Visitor(string name, int money, float card,int q,int w,int e,int r)
	{
		this->tickets[0] = q;
		this->tickets[1] = w;
		this->tickets[2] = e;
		this->tickets[3] = r;
		this->name = name;
		this->card = card;
		this->money = money;
		
		getchar();
	}

	void Visitor::Withdraw(int x)
	{
		if (this->money > x)
		{		this->money -= x;
		cout << "You buy it! Thank you for buy" << endl;
	}
		else
		{
			cout << "You do not have enough money." << endl;
			cout << " You can withdraw your money in our Bar!" << endl;
		}
	}


	

	Visitor::~Visitor()
	{
	}
