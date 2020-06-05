#include "Cinema.h"

using namespace std;



Cinema::Cinema()
{
	Cinemaname = "Alpha";
	WiFi = "YOULOVEMYCINEMA";
	Hallname1 = "Paradise";
	Hallname2 = "Space";
	Hallname3 = "Philip"; 
	places1=100;
	places2=30;
	places3=270;
}



void Cinema::CinemaInformation()
{
	
	string path = "myFile.txt";
	fstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "File is not open!" << endl;
	}
	else
	{
		fout << "It is information about Cinema. Visitor we are happy to welcome you to our cinema!" << endl;
		fout << "3-room movie complex:" << Hallname1 << "," << Hallname2 << "," << Hallname3 << ",located on the first floor of the shopping center Podolyany. " << endl;
		fout << "Currently, it is the only movie theater in the city, where you can view topical world cinema premieres." << endl;
		fout << "We have a lot of guests, and all of them will suffice," << endl;
		fout << "because the cinema halls can simultaneously accommodate 400 spectators." << endl;
		fout << "All cinema halls are equipped with modern digital equipment. Two of them support 3D technology." << endl;
		fout << "High-quality surround sound is provided by the Dolby Digital Surround EX system." << endl;

		fout << "It's easy to get into a soft armchair with beverage and popcorn stands" << endl;
		fout << "and be ready to plunge into a new, exciting reality. " << endl;
		fout << "And on romantics in the last row of each room waiting for wide armchairs LoveSeats." << endl;
		fout << "Bars" << endl;

		fout << "We want you to have a rest in the cinema and get only pleasant emotions here. Therefore, we have 3 bars in total:" << endl;

		fout << "a cocktail bar with armchairs and sofas, where you will find fragrant coffee," << endl;
		fout << "ice cream, sweets, beer, alcoholic drinks and cocktails;" << endl;
		fout << "Fresh bar, where juice-frees, milk cocktails and strips are prepared;" << endl;
		fout << "Concierge Bar with popcorn and classic cinema snacks." << endl;
		fout << "We do everything to become your favorite movie theater. Relax, relax and come back." << endl;
	}
	fout.close();
	ifstream fin;
	fin.open(path);
	string str;
	while(!fin.eof())
	{
		str = " ";
		getline(fin, str);
		cout << str << endl;
	}
	
	fin.close();

}

string Cinema::GetWiFipass()
{
	return WiFi;
}

void Cinema::ChangeWiFipass(string n)
{
	
		this->WiFi = n;
	
}

Cinema::Cinema(string Cinemaname,  string Hallname1, string Hallname2, string Hallname3, int places1, int places2, int places3)
{
	WiFi = "YOULOVEMYCINEMA";
	this->Cinemaname = Cinemaname;
	this->Hallname1 =  Hallname1;
	this->Hallname2 =  Hallname2;
	this->Hallname3 =  Hallname3;
	this->places1 =  places1;
	this->places2 =  places2;
	this->places3 =  places3;
}
string Cinema::GetCinemaname()
{
	return Cinemaname;
}

Cinema::~Cinema()
{
}

