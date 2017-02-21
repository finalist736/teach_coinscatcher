#ifndef _CONSOLE_GUI_H_
#define _CONSOLE_GUI_H_

typedef unsigned Coord;

struct Point
{
	Coord x;
	Coord y;

	explicit Point(Coord x_ = 0, Coord y_ = 0)
		: x(x_)
		, y(y_)
	{
	}
};

enum Color
{
	RED_COLOR = 0x0C,
	GREEN_COLOR = 0x0A,
	BLUE_COLOR = 0x09,
	WHITE_COLOR = 0x0F,
	GRAY_COLOR = 0x07,
	BLACK_COLOR = 0x00
};

void gotoxy(Coord x, Coord y);
void gotoxy(const Point& p);
void clrscr(Coord x, Coord y, unsigned width, unsigned height, Color bkgnColor = BLACK_COLOR);
Color gettextcolor();
Color settextcolor(Color color);
Color getbkcolor();
Color setbkcolor(Color color);

#endif