#include "Schedule.h"



Schedule::Schedule()
{
	
}

void Schedule::Informationa()
{
	ifstream fin;
	fin.open("Avengers.txt");
	string str;
	while (!fin.eof())
	{
		str = " ";
		getline(fin, str);
		cout << str << endl;
	}
	fin.close();
}

void Schedule::Informationb()
{
	ifstream fin;
	fin.open("Kung.txt");
	string str;
	while (!fin.eof())
	{
		str = " ";
		getline(fin, str);
		cout << str << endl;
	}
	fin.close();
}

void Schedule::Informationc()
{
	ifstream fin;
	fin.open("Alpha.txt");
	string str;
	while (!fin.eof())
	{
		str = " ";
		getline(fin, str);
		cout << str << endl;
	}
	fin.close();
}

void Schedule::Informationd()
{
	ifstream fin;
	fin.open("Love.txt");
	string str;
	while (!fin.eof())
	{
		str = " ";
		getline(fin, str);
		cout << str << endl;
	}
	fin.close();
}




Schedule::~Schedule()
{
}
