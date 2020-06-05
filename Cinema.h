#pragma once
#include<iostream>
#include <string>
#include <vector>
#include<iomanip>
#include<fstream>

using namespace std;

class Cinema
{
protected:
	string Hallname1;
	string Hallname2;
	string Hallname3;
	string Cinemaname;
	string WiFi;
	int places1;
	int places2;
	int places3;
public:
		string GetCinemaname();
		Cinema();
		void CinemaInformation();
		string GetWiFipass();
		void ChangeWiFipass(string n);
		Cinema(string Cinemaname, string Hallname1, string Hallname2, string Hallname3, int places1, int places2, int places3);
		~Cinema();
};

