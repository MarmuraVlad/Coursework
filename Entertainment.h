#pragma once
#include "Visitor.h"
#include<windows.h>
#include "Cinema.h"

class Entertainment :
	public Cinema,public Visitor
{

public:
	int time;
	Visitor vlad;
	Entertainment();
	Entertainment(string name, int money, float card, int q, int w, int e, int r);
	void Avengers();
	void Kung();
	void Alpha();
	void Love();
	void hockey();
	void race();
	void Ping();
	~Entertainment();
};

