#include <iostream>
#include <Windows.h>
#include "coin.h"
#include "player.h"
#include "gui.h"


using namespace std;

inline bool ComparePositions(const Point &a, const Point &b) {
	return a.x == b.x && a.y == b.y;
}

int main() {

	SetCoinLifeTime(10);// skolko vremeni zhivet moneta
	SetTimeOut(10);

	StartCoin();
	StartPlayer();
	StartGUI();
	
	while (true) {
		UpdateCoin();
		UpdatePlayer();
		UpdateGUI();

		const Point &a = CoinPosition();
		const Point &b = PlayerPosition();
		if (ComparePositions(a, b))
		{
			AddCoin();
			CaptureCoin();
		}

		if (GameOver()) {
			break;
		}
		gotoxy(79, 24); // move cursor to bottom right, чтоб не мешало
		Sleep(100); // 100 millisecs = 10 fps
	}
	system("cls");
	//gotoxy(79, 24);
	//cout << '1';


}
