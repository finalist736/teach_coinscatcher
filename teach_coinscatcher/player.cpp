#include <iostream>

#include "player.h"
#include <stdio.h>

//static int startTime = 0;
static bool played = false;
//static int removeTime = 0;
//static time_t now = 0;

static Point point;
static unsigned short currentKey = 0;


void StartPlayer()
{
	played = true;
}

void DefaultPlayerPosition()
{
	point.x = 40;
	point.y = 12;
	played = true;
}

void SetCurrentKey(unsigned short k)
{
	currentKey = k;
}

//int elasped = 0;

void UpdatePlayer()
{
	/*elasped++;
	if (elasped <= 10)
	{
		return;
	}
	elasped = 0;*/
	if (!played)
	{
		return;
	}
	// clear previous player
	gotoxy(point);
	clrscr(point, 1, 1);

	// change point from keyboard
	//getchar();
//#define VK_LEFT           0x25
//#define VK_UP             0x26
//#define VK_RIGHT          0x27
//#define VK_DOWN           0x28
	switch (currentKey){
	case 0x25:
		point.x--;
		break;
	case 0x27:
		point.x++;
		break;
	case 0x26:
		point.y--;
		break;
	case 0x28:
		point.y++;
		break;
	}

	// check ranges
	if (point.x == 80)
	{
		point.x = 0;
	} else if (point.x == -1) {
		point.x = 79;
	}

	if (point.y == 25)
	{
		point.y = 1;
	}
	else if (point.y == 0) {
		point.y = 24;
	}

	// print player
	gotoxy(point);
	settextcolor(RED_COLOR);
	std::cout << (char)2;
}

const Point& PlayerPosition() {
	return point;
}

void SetPlayerPosition(const Point& p)
{
	point = p;
}
