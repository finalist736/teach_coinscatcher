#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "console.h"
#include "gui.h"

bool started = false;
time_t timeToEnd = 0;

int TimeOut = 59;

int coinsCount = 0;
int lastCoinsCount = -1;

int framesIgnored = 0;

char coinsText[20] = { 0 };

void updateTimer();
void updateCoins();

int CurrentCoinsCount()
{
	return coinsCount;
}

void SetCoinsCount(int c)
{
	coinsCount = c;
}

int CurrentTimer()
{
	return timeToEnd;
}

void SetTimer(int t)
{
	timeToEnd = t;
	started = true;
	framesIgnored = 9;
}

void SetTimeOut(int v)
{
	TimeOut = v;
}

void StartGUI()
{
	started = true;
	timeToEnd = TimeOut;
	framesIgnored = 9;
}

void StopGUI(){
	started = false;
}

void AddCoin(){
	coinsCount++;
}

void UpdateGUI(){
	if (!started)
	{
		return;
	}
	
	updateTimer();
	updateCoins();

}

void updateTimer() {
	framesIgnored++;
	if (framesIgnored < 9)
	{
		return;
	}
	framesIgnored = 0;
	if (timeToEnd == 0)
	{
		return;
	}
	gotoxy(0, 0);
	settextcolor(WHITE_COLOR);
	printf("%d seconds", timeToEnd);
	timeToEnd--;
}

bool GameOver() {
	return timeToEnd == 0;
}

void updateCoins(){
	if (lastCoinsCount == coinsCount)
	{
		return;
	}
	memset(coinsText, 0, 20);
	sprintf(coinsText, "coins: %d", coinsCount);
	int len = strlen(coinsText);
	gotoxy(80 - len, 0);
	settextcolor(WHITE_COLOR);
	printf(coinsText);
	lastCoinsCount = coinsCount;

}
