#pragma once

#include "Layout.h"

class Cursor
{
	int cur_X = 1;
	int cur_Y = 1;
	char icon = 'O';
	char old_fill = ' ';
	Layout *cur_Lay;
public:
	bool is_snake_mode = false;
	bool is_rubber = false;
	char mark = '#';
	Cursor();
	Cursor(Layout *l);
	~Cursor();
	void move(int &ch_X , int &ch_Y);
	void change_current_L(Layout *ch_L);
	void clear_current_layout();
	void print_layout_and_state();
};

