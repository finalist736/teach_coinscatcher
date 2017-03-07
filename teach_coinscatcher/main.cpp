#include <iostream>
#include <Windows.h>
#include "coin.h"
#include "player.h"
#include "gui.h"
#include "keyboard.h"
#include "save.h"

using namespace std;

inline bool ComparePositions(const Point &a, const Point &b) {
	return a.x == b.x && a.y == b.y;
}

int main() {
	GameSave sg;
	SetCoinLifeTime(10);
	if (GameLoadAvailable() && LoadGame(&sg))
	{
		SetPlayerPosition(Point(sg.Px, sg.Py));
		SetCoinPosition(Point(sg.Cx, sg.Cy));
		SetCoinsCount(sg.Coins);
		SetTimer(sg.Timer);
		StartPlayer();
		
	}
	else
	{
		SetTimeOut(60);
		DefaultPlayerPosition();
		StartCoin();
		StartGUI();
	}

	
	
	while (true) {
		unsigned short key = KeyPressed();
		if (key == 0x1B)// escape
		{
			sg.Coins = CurrentCoinsCount();
			sg.Timer = CurrentTimer();

			const Point &a = CoinPosition();
			const Point &b = PlayerPosition();

			sg.Cx = a.x;
			sg.Cy = a.y;
			sg.Px = b.x;
			sg.Py = b.y;

			SaveGame(sg);
			break;
		}

		SetCurrentKey(key);

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

	system("pause");
}
