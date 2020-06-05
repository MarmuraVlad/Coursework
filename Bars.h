#pragma once
#include "Cinema.h"
#include "Visitor.h"
using namespace std;

class Bars :
	public Cinema, public Visitor
{
public:
	Bars();
	void CocaCola();
	void Pepsi();
	void Fanta();
	void Shweeeepsss();
	void Orange();
	void Mineral();
	void Bear();
	void Icecream();
	void Banana();
	void Apple();
	void Chips();
	void Cotton();
	void Popcorn();
	
	~Bars();
};

