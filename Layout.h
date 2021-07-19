#pragma once
#include <iostream>
#include <conio.h>

class Layout
{
	friend class Cursor;
	friend class Screen;
	static const int size_X = 100;
	static const int size_Y = 20;
	char border = '+';
	char space = ' ';
	char **map;
	bool is_enabled;
	int Num = 0;
public:
	Layout();
	~Layout();
	void fill_layout();
	void print_layout();
};

