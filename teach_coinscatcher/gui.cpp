#include <time.h>
#include <stdio.h>
#include "console.h"
#include "gui.h"

bool started = false;
time_t timeToEnd = 0;
int framesIgnored = 0;


void updateTimer();
void updateCoins();
void StartGUI()
{
	started = true;
	timeToEnd = 59;
	framesIgnored = 9;
}

void StopGUI(){
	started = false;
}

void AddCoin(){

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

}
