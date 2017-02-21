#include <iostream>
#include "player.h"
#include <stdio.h>

//static int startTime = 0;
static bool played = false;
//static int removeTime = 0;
//static time_t now = 0;

static Point point;


void StartPlayer()
{
	played = true;
	point.x = 40;
	point.y = 12;
}

void UpdatePlayer()
{
	if (!played)
	{
		return;
	}
	// clear previous player
	gotoxy(point);
	clrscr(point, 1, 1);

	// change point from keyboard
	getchar();
	point.x++;
	point.y++;

	// check ranges
	if (point.x == 80)
	{
		point.x = 0;
	} else if (point.x == -1) {
		point.x = 79;
	}

	if (point.y == 25)
	{
		point.y = 0;
	}
	else if (point.y == -1) {
		point.y = 24;
	}

	// print player
	gotoxy(point);
	settextcolor(RED_COLOR);
	std::cout << (char)2;
}
