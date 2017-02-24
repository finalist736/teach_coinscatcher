#include <iostream>
#include <Windows.h>
#include "player.h"
#include <stdio.h>

//static int startTime = 0;
static bool played = false;
//static int removeTime = 0;
//static time_t now = 0;

static Point point;

HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

DWORD Events = 0;     // Event count
DWORD EventsRead = 0; // Events read from console

void StartPlayer()
{
	played = true;
	point.x = 40;
	point.y = 12;


	rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

	//DWORD Events = 0;     // Event count
	//DWORD EventsRead = 0; // Events read from console
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

	GetNumberOfConsoleInputEvents(rhnd, &Events);

	if (Events != 0){ // if something happened we will handle the events we want

		// create event buffer the size of how many Events
		INPUT_RECORD *eventBuffer = new INPUT_RECORD[Events];

		// fills the event buffer with the events and saves count in EventsRead
		ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);

		// loop through the event buffer using the saved count
		for (DWORD i = 0; i < EventsRead; ++i){

			// check if event[i] is a key event && if so is a press not a release
			if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown){

				// check if the key press was an arrow key
				switch (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode){
				case VK_LEFT:
					point.x--;
					break;
				case VK_RIGHT:
					point.x++;
					break;
				case VK_UP:
					point.y--;
					break;
				case VK_DOWN:   // if any arrow key was pressed break here
					//std::cout << "arrow key pressed.\n";
					point.y++;
					break;

				case VK_ESCAPE: // if escape key was pressed end program loop
					std::cout << "escape key pressed.\n";
					//Running = false;
					break;

				default:        // no handled cases where pressed 
					std::cout << "key not handled pressed.\n";
					break;
				}
			}

		} // end EventsRead loop
		delete[] eventBuffer;

	}

	/*point.x++;
	point.y++;*/

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
