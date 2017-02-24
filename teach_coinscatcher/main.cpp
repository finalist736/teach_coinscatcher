#include <iostream>
#include <Windows.h>
#include "coin.h"
#include "player.h"
#include "gui.h"


using namespace std;

int main() {

	StartCoin();
	StartPlayer();
	StartGUI();
	
	while (true) {
		UpdateCoin();
		UpdatePlayer();
		UpdateGUI();

		if (GameOver()) {
			// lol1
		}
		gotoxy(79, 24); // move cursor to bottom right, чтоб не мешало
		Sleep(100); // 100 millisecs = 10 fps
	}

	//gotoxy(79, 24);
	//cout << '1';


}
