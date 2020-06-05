#pragma once
#include<iostream>
#include <string>

using namespace std;

class Visitor
{
protected:
	string name;
	int money;
	float card;
public:
	int tickets[4];
	Visitor();
	void Withdrawmoney(int x);
	int Getmoney();
	float Getcard();
	void Buyticket(int cost, int index);
	Visitor(string name, int money, float card,int q,int w,int e,int r);
    void Withdraw(int x);
	~Visitor();
};

