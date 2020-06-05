#include<iostream>
#include<conio.h>
#include <string>
#include "Visitor.h"
#include "Cinema.h"
#include "Entertainment.h"
#include"Schedule.h"
#include "Bars.h"
#include <Windows.h>
using namespace std;
string n;  int m;  float c;
Cinema * a;
Visitor * v;
Bars * b;
Schedule * s;
Entertainment * e;

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

//#include "stdafx.h"

// from HKEY_USERS\.DEFAULT\Keyboard Layout\Preload
#define ENG_KEYBOARD_LAYOUT "00000409"
#define UKR_KEYBOARD_LAYOUT "00000422"
#define RUS_KEYBOARD_LAYOUT "00000419"

#include "stdio.h"
#include "conio.h"
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>

//#define DISABLE_DEFAULT_ACTION

#define MAX_MENU_SPACE 1000
#define MAX_LENGTH_MENU_NAME 100
#define MAX_MENU_ITEMS_COUNT 100

void goToXY(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void clearGoToXY(int x, int y) {
	COORD topLeft = { x, y };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written

	);
	SetConsoleCursorPosition(console, topLeft);
}

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_BACKSPACE 8
#define KEY_ESCAPE 27

unsigned int runSpaceOp(int x, int y, int kolommen, char spaceOp[MAX_MENU_SPACE][MAX_MENU_SPACE], int rijen = MAX_MENU_SPACE)
{
	int index = 0, indey = 0, keuze, lol = MAX_MENU_SPACE;
	do {
		goToXY(index + x, indey + y);
		keuze = 0;
		keuze = _getch();
		if (keuze == 0 || keuze == 0xE0 || keuze == 224)
		{
			keuze = _getch();
			goToXY(index + x, indey + y);
			switch (keuze)
			{
			case KEY_UP:indey--;
				break;
			case KEY_LEFT: index--;
				break;
			case KEY_DOWN:indey++;
				break;
			case KEY_RIGHT: index++;
				break;
			}
			indey = (indey <= 0) ? 0 : (indey > kolommen) ? kolommen : indey;
			index = (index <= 0) ? 0 : (index > rijen) ? rijen : index;
		}
		if (keuze == 32 || (keuze >= 46 && keuze <= 57) || (keuze <= 64 && keuze >= 126))
		{
			spaceOp[index][indey] = (char)keuze;
			printf("%c", spaceOp[index][indey]);
			index++;
			index = (index <= 0) ? 0 : (index > rijen) ? rijen : index;
		}
		if (keuze == KEY_ENTER)
		{
			return indey;
		}
	} while (keuze != KEY_ESCAPE);

	return -1; //
}

void runTextOp(int x, int y, int kolommen, char spaceOp[MAX_MENU_SPACE][MAX_MENU_SPACE], int rijen = MAX_MENU_SPACE)
{
	int index = 0, indey = 0, keuze, lol = MAX_MENU_SPACE;
	do {
		goToXY(index + x, indey + y);
		keuze = 0;
		keuze = _getch();
		if (keuze == 0 || keuze == 0xE0 || keuze == 224)
		{
			keuze = _getch();
			goToXY(index + x, indey + y);
			switch (keuze)
			{
			case KEY_UP:indey--;
				break;
			case KEY_LEFT: index--;
				break;
			case KEY_DOWN:indey++;
				break;
			case KEY_RIGHT: index++;
				break;
			}
			indey = (indey <= 0) ? 0 : (indey > kolommen) ? kolommen : indey;
			index = (index <= 0) ? 0 : (index > rijen) ? rijen : index;
		}
		if (keuze == 32 || (keuze >= 46 && keuze <= 57) || (keuze <= 64 && keuze >= 126))
		{
			spaceOp[index][indey] = (char)keuze;
			printf("%c", spaceOp[index][indey]);
			index++;
			index = (index <= 0) ? 0 : (index > rijen) ? rijen : index;
		}
		if (keuze == KEY_BACKSPACE)
		{
			index = index--;
			goToXY(index + x, indey + y);
			printf(" ");
			index = (index <= 0) ? 0 : (index > rijen) ? rijen : index;
		}
		if (keuze == KEY_ENTER)
		{
			index = 0;
			indey++;
			indey = (indey >= kolommen) ? kolommen : indey++;
		}
	} while (keuze != KEY_ESCAPE);
}

void defaultAction() {
#ifndef DISABLE_DEFAULT_ACTION
	clearGoToXY(0, 0);
	printf("default action");
	getchar();
#endif
}

	void ChangeWiFipass() {

	clearGoToXY(0, 0);
	//Cinema a;
	a = new Cinema();
	string n; long d;
	cout << "Admin Enter a parol" << endl;
	cin >> d;
	if (d == 322)
	{
		cout << "Enter a new pass" << endl;
		cin >> n;
		if (!a) {
			return;
		}
		a->ChangeWiFipass(n);
		getchar();
	}
	else
	{
		cout << "You can`t change a pass " << endl;
	}
}
void WiFipass() {

	clearGoToXY(0, 0);
	//a = new Cinema();
	if (!a) {
		return;
	}
	cout << a->GetWiFipass() << endl;
	getchar();

	//delete a;
}
void Checkcard() {
	//Visitor b;
	clearGoToXY(0, 0);
	cout << v->Getcard() << endl;
	getchar();
}
void Checkmoney() {
	//Visitor v;
	clearGoToXY(0, 0);
	cout << v->Getmoney() << endl;
	getchar();
}
void Buy1() {
	//Visitor b;
	clearGoToXY(0, 0);
	////v = new Visitor(n, m, c);
	v->Buyticket(120, 0);

	cout << "You buy ticket on the Avengers : The End" << endl;
	getchar();
}
void Buy2() {
	//Visitor b;
	clearGoToXY(0, 0);
	//v = new Visitor(n, m, c);
	cout << "You buy ticket on the Kung-fu Panda 4" << endl;
	v->Buyticket(110, 1);
	
	
	getchar();
}
void Buy3() {
	//Visitor b;
	clearGoToXY(0, 0);
	//v = new Visitor(n, m, c);
	cout << "You buy ticket on the Alpha" << endl;
	v->Buyticket(100, 2);
	
	getchar();
}
void Buy4() {
	//Visitor b;
	clearGoToXY(0, 0);
	cout << "You buy ticket on the Love in big city" << endl;
	//v = new Visitor(n, m, c);
	
	v->Buyticket(90, 3);
	getchar();
}
void InfaboutCinema() {

	clearGoToXY(0, 0);
	Bars a;
	a.CinemaInformation();
	getchar();

}
void WITHDRAW() {
	clearGoToXY(0, 0);
	//b = new Bars;
	double x;
	cout << "How much money you want to withdraw?:" ; 
	cin >> x;
	cout << endl;
	v->Withdrawmoney(x);
	getchar();
}
void CocaCola()
{
	clearGoToXY(0, 0);
	b->CocaCola();
	v->Withdraw(15);
	getchar();
}
void Pepsi()
{
	clearGoToXY(0, 0);
	b->Pepsi();
	v->Withdraw(15);
	getchar();
}
void Fanta()
{
	clearGoToXY(0, 0);
	b->Fanta();
	v->Withdraw(15);
	getchar();
}
void Shweeeepsss()
{
	clearGoToXY(0, 0);
	b->Shweeeepsss();	v->Withdraw(25);
	getchar();
}
void Orange()
{
	clearGoToXY(0, 0);
	b->Orange();
	v->Withdraw(20);
	getchar();
}
void Mineral()
{
	clearGoToXY(0, 0);
	b->Mineral();
	v->Withdraw(10);
	getchar();
}
void Bear()
{
	clearGoToXY(0, 0);
	b->Bear();
	v->Withdraw(25);
	getchar();
}
void Chips()
{
	clearGoToXY(0, 0);
	b->Chips();
	v->Withdraw(40);
	getchar();
}
void Popcorn()
{
	clearGoToXY(0, 0);
	b->Popcorn();
	v->Withdraw(40);
	getchar();
}
void Cotton()
{
	clearGoToXY(0, 0);
	b->Cotton();
	v->Withdraw(50);
	getchar();
}
void Apple()
{
	clearGoToXY(0, 0);
	b->Apple();
	v->Withdraw(5);
	getchar();
}
void Banana()
{
	clearGoToXY(0, 0);
	b->Banana();
	v->Withdraw(10);
	getchar();
}
void Icecream()
{
	clearGoToXY(0, 0);
	b->Icecream();
	v->Withdraw(15);
	getchar();
}
void IAvengers()
{
	clearGoToXY(0, 0);
	cout << "Information about Avengers" << endl;
	s->Informationa();
	getchar();
}
void IAlpha()
{
	clearGoToXY(0, 0);
	cout << "Information about Alpha" << endl;
	s->Informationc();
	getchar();
}
void IKung()
{
	clearGoToXY(0, 0);
	cout << "Information about Kung-Fu Panda" << endl;
	s->Informationb();
	getchar();
}
void ILove()
{
	clearGoToXY(0, 0);
	cout << "Information about Love in big city" << endl;
	s->Informationd();
	getchar();
}
void WLove()
{
	clearGoToXY(0, 0);
	if (v->tickets[3] > 0)
	{
		e->Love();
	}
	else
	{
		cout << "Buy ticket" << endl;
	}

	getchar();
}
void WAlpha()
{
	clearGoToXY(0, 0);
	if (v->tickets[2] > 0)
	{
		e->Alpha();
	}
	else
	{
		cout << "Buy ticket" << endl;
	}

	getchar();
}
void WKung()
{
	clearGoToXY(0, 0);
	if (v->tickets[1] > 0)
	{
		e->Kung();
	}
	else
	{
		cout << "Buy ticket" << endl;
	}

	
		getchar();
}
void WAvengers()
{
	clearGoToXY(0, 0);
	if (v->tickets[0] > 0)
	{
		e->Avengers();
	}
	else
	{
		cout << "Buy ticket" << endl;
	}

	
	getchar();
}
void Hockey()
{
	clearGoToXY(0, 0);
	e->hockey();
	getchar();
}
void Race()
{
	clearGoToXY(0, 0);
	e->race();
	getchar();
}
void Ping()
{
	clearGoToXY(0, 0);
	e->Ping();
	getchar();
}

void Exit()
{
	exit(0);
}

struct MenuElement {
	char menuName[1000];
	struct MenuElement * SubMenuSet;
	void(*action)();
};

extern struct MenuElement menuA[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuB[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuC[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuC1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuD[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuE[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuF[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuG[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuH[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuK[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuV[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuQ[MAX_MENU_ITEMS_COUNT]; 
extern struct MenuElement menuW[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuD1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuE1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuF1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuG1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuH1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuK1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuV1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuA1[MAX_MENU_ITEMS_COUNT];
extern struct MenuElement menuB1[MAX_MENU_ITEMS_COUNT];

struct MenuElement
	baseMenu[MAX_MENU_ITEMS_COUNT] = {
	{ "Visitor", menuQ, (void(*)())NULL },
		{ "Admin", menuW, (void(*)())NULL },
		{ "Exit", (struct MenuElement *)NULL, Exit },
		{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuW[MAX_MENU_ITEMS_COUNT] = {
		{ "Schedule", menuA, (void(*)())NULL },
		{ "information about cinema", menuB, (void(*)())NULL },
		{ "WiFi pass", menuC, (void(*)())NULL },
		{ "FoodDrink", menuE, (void(*)())NULL },
		{ "Exit", (struct MenuElement *)NULL, Exit },
		{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}

,menuQ[MAX_MENU_ITEMS_COUNT] = { 
		{ "Schedule", menuA, (void(*)())NULL },
		{ "information about cinema", menuB, (void(*)())NULL },
		{ "WiFi pass", menuC1, (void(*)())NULL },
		{ "Ententainment", menuD, (void(*)())NULL },
		{ "FoodDrink", menuE, (void(*)())NULL },
		{ "Exit", (struct MenuElement *)NULL, Exit },
		{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuA[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuQ, (void(*)())NULL },
	{ "Choose and buy ticket", menuH,(void(*)())NULL },
	{ "Information about films	", menuK,(void(*)())NULL},
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuB[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuQ, (void(*)())NULL },
	{ "Get information about cinema", (struct MenuElement *)NULL, InfaboutCinema },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}, menuA1[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuW, (void(*)())NULL },
	{ "Choose and buy ticket", menuH1,(void(*)())NULL },
	{ "Information about films	", menuK1,(void(*)())NULL},
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuB1[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuQ, (void(*)())NULL },
	{ "Get information about cinema", (struct MenuElement *)NULL, InfaboutCinema },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuC[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuW, (void(*)())NULL },
	{ "Get WiFi password", (struct MenuElement *)NULL, WiFipass },
	{ "Change WiFi password", (struct MenuElement *)NULL, ChangeWiFipass },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuC1[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuQ, (void(*)())NULL },
	{ "Get WiFi password", (struct MenuElement *)NULL, WiFipass },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuD[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuQ, (void(*)())NULL },
	{ "Watch film", menuV, (void(*)())NULL},
	{ "Play Air-hockey", (struct MenuElement *)NULL, Hockey },
	{ "Play Need for speed", (struct MenuElement *)NULL, Race },
	{ "Play Ping-pong", (struct MenuElement *)NULL, Ping },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}, menuE[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuQ, (void(*)())NULL },
	{ "Wirhdraw money",(struct MenuElement *)NULL,WITHDRAW   },
	{ "Check money on card",(struct MenuElement *)NULL,Checkcard },
	{ "Check money",(struct MenuElement *)NULL,Checkmoney   },
	{ "Buy Food",  menuG, (void(*)())NULL },
	{ "Buy Drink",   menuF, (void(*)())NULL},
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }

	}, menuF[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuE, (void(*)())NULL },
	{ "Coca-Cola (15 UA)", (struct MenuElement *)NULL, CocaCola  },
	{ "Pepsi(15 UA)", (struct MenuElement *)NULL, Pepsi  },
	{ "Shweeeepsss(25 UA)", (struct MenuElement *)NULL, Shweeeepsss },
	{ "Orange juice(20 UA)", (struct MenuElement *)NULL, Orange },
	{ "Mineral water(10 UA)", (struct MenuElement *)NULL, Mineral },
	{ "Fanta(15 UA)", (struct MenuElement *)NULL, Fanta },
	{ "Bear(25 UA)", (struct MenuElement *)NULL, Bear },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}, 
	menuG[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuE, (void(*)())NULL },
	{ "Potato Chips Lays(40 UA) ", (struct MenuElement *)NULL, Chips},
	{ "Popcorn(40 UA)",(struct MenuElement *)NULL, Popcorn},
	{ "Cotton candy(50 UA)", (struct MenuElement *)NULL, Cotton },
	{ "Apples(5 UA)", (struct MenuElement *)NULL, Apple },
	{ "Bananas(10 UA)", (struct MenuElement *)NULL, Banana },
	{ "Ice cream(15 UA)", (struct MenuElement *)NULL, Icecream },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuH[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuA, (void(*)())NULL },
	{ "Avengers : The End(120 UA)", (struct MenuElement *)NULL, Buy1 },
	{ "Kung-fu Panda 4(110 UA)", (struct MenuElement *)NULL, Buy2 },
	{ "Alpha(100 UA)", (struct MenuElement *)NULL, Buy3 },
	{ "Love in big city(90 UA)", (struct MenuElement *)NULL, Buy4 },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuV[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuD, (void(*)())NULL },
	{ "Avengers : The End", (struct MenuElement *)NULL, WAvengers },
	{ "Kung-fu Panda 4", (struct MenuElement *)NULL, WKung },
	{ "Alpha", (struct MenuElement *)NULL, WAlpha },
	{ "Love in big city", (struct MenuElement *)NULL, WLove },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuK[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuA, (void(*)())NULL },
	{ "Avengers : The End", (struct MenuElement *)NULL, IAvengers },
	{ "Kung-fu Panda 4", (struct MenuElement *)NULL, IKung },
	{ "Alpha", (struct MenuElement *)NULL, IAlpha },
	{ "Love in big city", (struct MenuElement *)NULL, ILove },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
},menuD1[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuW, (void(*)())NULL },
	{ "Watch film", menuV1, (void(*)())NULL},
	{ "Play Air-hockey", (struct MenuElement *)NULL, Hockey },
	{ "Play Need for speed", (struct MenuElement *)NULL, Race },
	{ "Play Ping-pong", (struct MenuElement *)NULL, Ping },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}, menuE1[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuW, (void(*)())NULL },
	{ "Wirhdraw money",(struct MenuElement *)NULL,WITHDRAW   },
	{ "Check money on card",(struct MenuElement *)NULL,Checkcard },
	{ "Check money",(struct MenuElement *)NULL,Checkmoney   },
	{ "Buy Food",  menuG1, (void(*)())NULL },
	{ "Buy Drink",   menuF1, (void(*)())NULL},
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }

}, menuF1[MAX_MENU_ITEMS_COUNT] = {
{ "Back to previous", menuE1, (void(*)())NULL },
{ "Coca-Cola (15 UA)", (struct MenuElement *)NULL, CocaCola  },
{ "Pepsi(15 UA)", (struct MenuElement *)NULL, Pepsi  },
{ "Shweeeepsss(25 UA)", (struct MenuElement *)NULL, Shweeeepsss },
{ "Orange juice(20 UA)", (struct MenuElement *)NULL, Orange },
{ "Mineral water(10 UA)", (struct MenuElement *)NULL, Mineral },
{ "Fanta(15 UA)", (struct MenuElement *)NULL, Fanta },
{ "Bear(25 UA)", (struct MenuElement *)NULL, Bear },
{ "", (struct MenuElement *)NULL, (void(*)())NULL }
},
menuG1[MAX_MENU_ITEMS_COUNT] = {
{ "Back to previous", menuE1, (void(*)())NULL },
{ "Potato Chips Lays(40 UA) ", (struct MenuElement *)NULL, Chips},
{ "Popcorn(40 UA)",(struct MenuElement *)NULL, Popcorn},
{ "Cotton candy(50 UA)", (struct MenuElement *)NULL, Cotton },
{ "Apples(5 UA)", (struct MenuElement *)NULL, Apple },
{ "Bananas(10 UA)", (struct MenuElement *)NULL, Banana },
{ "Ice cream(15 UA)", (struct MenuElement *)NULL, Icecream },
{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuH1[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuA1, (void(*)())NULL },
	{ "Avengers : The End(120 UA)", (struct MenuElement *)NULL, Buy1 },
	{ "Kung-fu Panda 4(110 UA)", (struct MenuElement *)NULL, Buy2 },
	{ "Alpha(100 UA)", (struct MenuElement *)NULL, Buy3 },
	{ "Love in big city(90 UA)", (struct MenuElement *)NULL, Buy4 },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuV1[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuD1, (void(*)())NULL },
	{ "Avengers : The End", (struct MenuElement *)NULL, WAvengers },
	{ "Kung-fu Panda 4", (struct MenuElement *)NULL, WKung },
	{ "Alpha", (struct MenuElement *)NULL, WAlpha },
	{ "Love in big city", (struct MenuElement *)NULL, WLove },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
}
, menuK1[MAX_MENU_ITEMS_COUNT] = {
	{ "Back to previous", menuA1, (void(*)())NULL },
	{ "Avengers : The End", (struct MenuElement *)NULL, IAvengers },
	{ "Kung-fu Panda 4", (struct MenuElement *)NULL, IKung },
	{ "Alpha", (struct MenuElement *)NULL, IAlpha },
	{ "Love in big city", (struct MenuElement *)NULL, ILove },
	{ "", (struct MenuElement *)NULL, (void(*)())NULL }
};
 

unsigned int render(struct MenuElement * menu) {
	unsigned int index = 0;

	clearGoToXY(0, 0);

	if (menu) {
		for (; menu[index].menuName[0]; ++index) {
			printf(menu[index].menuName);
			clearGoToXY(31, index);
			printf("[ ]\r\n");
		}
	}

	return --index;
}

int main() {
	a = NULL;
	string n;  int m;  float c; int q, w, e1, r;
	cout << "Enter Name : ";
	cin >> n; cout << endl;
	cout << "Enter money : ";
	cin >> m; cout << endl;
	cout << "Enter money on card : ";
	cin >> c; cout << endl;
	cout << "How much tickets you have on to Avengers?";
	cin >> q; cout << endl;
	cout << "How much tickets you have on to Kung-Fu Panda?";
	cin >> w; cout << endl;
	cout << "How much tickets you have on to Alpha?";
	cin >> e1; cout << endl;
	cout << "How much tickets you have on to Love in big city?";
	cin >> r; cout << endl;
	v = new Visitor(n, m, c,q,w,e1,r);
	a = new Cinema();
	e = new Entertainment(n, m, c, q, w, e1, r);
	getchar();

	/*Cinema CCinema("Miracle", "CCinemathebest", "Paradise", "Alpha", "Space", 100, 30, 270);

	string a; int b; int c; int choose; int choose1; int choose2; int choose3;

	cout << "Hello my friend! What is your name?:";
	cin >> a;
	cout << "How much money do you have?:";
	cin >> b;
	cout << "How much money do you have on your card?:";
	cin >> c;

	*/
	struct MenuElement * menu = baseMenu;
	char spaceOp[MAX_MENU_SPACE][MAX_MENU_SPACE];

	PostMessage(
		GetForegroundWindow(),
		WM_INPUTLANGCHANGEREQUEST,
		2,
		(UINT)LoadKeyboardLayoutA(ENG_KEYBOARD_LAYOUT, KLF_ACTIVATE)
	);


	while (true) {

		unsigned int lastIndex = render(menu);
		if ((int)lastIndex == -1) {
			_getch();
			return 0;
		}

		unsigned int selectedIndex = runSpaceOp(32, 0, lastIndex, spaceOp, 0);
		if ((int)selectedIndex == -1) {
			_getch();
			return 0;
		}

		if (menu[selectedIndex].action != NULL) {
			menu[selectedIndex].action();
		}

		if (menu[selectedIndex].SubMenuSet != NULL) {
			menu = menu[selectedIndex].SubMenuSet;
		}

	}
	_getch();
	return 0;
}