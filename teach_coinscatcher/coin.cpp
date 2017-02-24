#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "coin.h"

static int startTime = 0;
static int removeTime = 0;
static time_t now = 0;

static Point coinPoint;
static int CoinLifeTime = 5;

void ShowCoin();
void RemoveCoin();

void SetCoinLifeTime(int value){
	CoinLifeTime = value;
}

void StartCoin(){
	startTime = time(NULL) + 1;
}

void UpdateCoin() {
	ShowCoin();
	RemoveCoin();
}

const Point& CoinPosition() {
	return coinPoint;
}

inline void GetRandomPoint() {
	coinPoint.x = rand() % 80;
	coinPoint.y = rand() % 24 + 1;
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
	removeTime = now + CoinLifeTime;
}

void CaptureCoin() {
	coinPoint.x = 40;
	coinPoint.y = 0;
	removeTime = 0;
	startTime = time(NULL) + 1;
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
	clrscr(coinPoint, 1, 1);
}
