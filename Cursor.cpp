#include "Cursor.h"

using std::cout;
using std::cin;
using std::endl;

Cursor::Cursor(Layout* l) : cur_Lay(l)
{ }

Cursor::Cursor() : cur_Lay(nullptr)
{ }
Cursor::~Cursor()
{ }

void Cursor::move(int &ch_X, int &ch_Y)
{
	
	if (is_rubber)
		cur_Lay->map[cur_Y][cur_X] = cur_Lay->space;
	else
		cur_Lay->map[cur_Y][cur_X] = old_fill;

	if(is_snake_mode)
		cur_Lay->map[cur_Y][cur_X] = mark;
	
	if ((cur_X + ch_X) < cur_Lay->size_X - 1 && (cur_X + ch_X) > 0)
		cur_X += ch_X;
	if ((cur_Y + ch_Y) < cur_Lay->size_Y - 1 && (cur_Y + ch_Y) > 0)
		cur_Y += ch_Y;

	old_fill = cur_Lay->map[cur_Y][cur_X];

	cur_Lay->map[cur_Y][cur_X] = icon;
	print_layout_and_state();

}

void Cursor::print_layout_and_state()
{
	cur_Lay->print_layout();
	cout << "Snake mode: " << is_snake_mode << endl;
	cout << "Rubber mode: " << is_rubber << endl;
}

void Cursor::change_current_L(Layout* ch_L)
{
	is_snake_mode = false;
	is_rubber = false;
	if(cur_Lay != nullptr)
		cur_Lay->map[cur_Y][cur_X] = old_fill;
	if (ch_L != nullptr)
		cur_Lay = ch_L;
	old_fill = cur_Lay->map[cur_Y][cur_X];
	cur_Lay->map[cur_Y][cur_X] = icon;
	print_layout_and_state();
}

void Cursor::clear_current_layout()
{
	is_snake_mode = false;
	is_rubber = false;
	cur_Lay->fill_layout();
	old_fill = cur_Lay->space;
	cur_Lay->map[cur_Y][cur_X] = icon;
	print_layout_and_state();
}