#pragma once

#include "Layout.h"
#include "Cursor.h"

class Screen
{
	static const int count_L = 10;
	static const int size_X = 100;
	static const int size_Y = 20;
	char general_map[size_Y][size_X];
	
	Layout *Lay_Col;
	Cursor Cur;

	void print_Screen();
	void clear_Screen();
	void print_enable_stat();
public:
	Screen();
	~Screen();
	void go_to_layout(int number);
	void combine_all_layouts();
	void change_enable_layout();
	void move(int ch_X = 0, int ch_Y = 0);
	void change_mod();
	void change_rubber();
	void clear_current_layout();
};

