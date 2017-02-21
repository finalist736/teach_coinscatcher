#include <iostream>
#include <Windows.h>
#include "coin.h"
#include "player.h"


using namespace std;

int main() {

	StartCoin();
	StartPlayer();
	while (true) {
		UpdateCoin();
		UpdatePlayer();
		gotoxy(79, 24);
		Sleep(100);
	}

	//gotoxy(79, 24);
	//cout << '1';


}
