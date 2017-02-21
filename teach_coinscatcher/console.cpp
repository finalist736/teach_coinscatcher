#include <windows.h>
#include <string>
#include <iostream>
#include "console.h"

using namespace std;


namespace
{
	typedef WORD Attr;

	HANDLE GetConsoleHandle()
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}

	// Глобальные объекты - это очень плохо.
	// Но в данном случае это самый простой способ.
	// Эти переменные хранят текущие цвета текста
	// и фона соответственно.
	Color g_currentTextColor = WHITE_COLOR;
	Color g_currentBkColor = BLACK_COLOR;

} // namespace

void clrscr(const Point &p, unsigned width, unsigned height, Color bkgnColor)
{
	clrscr(p.x, p.y, width, height, bkgnColor);
}

void clrscr(Coord x, Coord y, unsigned width, unsigned height, Color bkgnColor)
{
	const Color prev = setbkcolor(bkgnColor);
	const string str(width, ' ');
	for (unsigned i = 0; i < height; ++i, ++y)
	{
		gotoxy(x, y);
		cout << str;
	}
	setbkcolor(prev);
}

void gotoxy(const Point& p)
{
	gotoxy(p.x, p.y);
}

void gotoxy(Coord x, Coord y)
{
	COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(GetConsoleHandle(), coord);
}

Color gettextcolor()
{
	return g_currentTextColor;
}

Color settextcolor(Color c)
{
	const Color prev = gettextcolor();
	Attr attr = static_cast<Attr>(getbkcolor());
	attr <<= 4;
	attr |= static_cast<Attr>(c);
	if (SetConsoleTextAttribute(GetConsoleHandle(), attr))
		g_currentTextColor = c;
	return prev;
}

Color getbkcolor()
{
	return g_currentBkColor;
}

Color setbkcolor(Color c)
{
	const Color prev = getbkcolor();
	Attr attr = static_cast<Attr>(c);
	attr <<= 4;
	attr |= static_cast<Attr>(gettextcolor());
	if (SetConsoleTextAttribute(GetConsoleHandle(), attr))
		g_currentBkColor = c;
	return prev;
}