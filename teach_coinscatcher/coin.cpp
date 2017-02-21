#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "coin.h"

static int startTime = 0;
static int removeTime = 0;
static time_t now = 0;

static Point coinPoint;


void ShowCoin();
void RemoveCoin();

void StartCoin(){
	startTime = time(NULL) + 1;
}

void UpdateCoin() {
	ShowCoin();
	RemoveCoin();
}

inline void GetRandomPoint() {
	coinPoint.x = rand() % 80;
	coinPoint.y = rand() % 25;
}

void ShowCoin() {
	if (startTime == 0)
	{
		return;
	}
	now = time(NULL);
	if (startTime > now)
	{
		return;
	}
	GetRandomPoint();
	gotoxy(coinPoint);
	settextcolor(GREEN_COLOR);
	std::cout << '$';
	startTime = 0;
	removeTime = now + 5;
}

void RemoveCoin() {
	if (removeTime == 0)
	{
		return;
	}
	now = time(NULL);
	if (removeTime > now)
	{
		return;
	}
	startTime = now + 1;
	removeTime = 0;
	clrscr(coinPoint.x, coinPoint.y, 1, 1);
}
