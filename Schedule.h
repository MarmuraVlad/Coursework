#pragma once
#include "Cinema.h"
#include "Visitor.h"
#include<vector>
class Schedule :
	public Cinema,public Visitor
{
protected:
	
public:
Schedule();
void Informationa();
void Informationb();
void Informationc();
void Informationd();
void Buyticket0();
void Buyticket1();
void Buyticket2();
void Buyticket3();
~Schedule();
};

