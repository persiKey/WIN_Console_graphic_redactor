#include "Screen.h"

using std::cout;
using std::cin;
using std::endl;


Screen::Screen()
{
	Lay_Col = new Layout[count_L];
	for (int i = 0; i < count_L; ++i)
	{
		Lay_Col[i].Num = i;
	}
	go_to_layout(0);
}

Screen::~Screen()
{
	delete[] Lay_Col;
}

void Screen::print_Screen()
{
	system("cls");
	cout << "General Map" << endl;
	for (int i = 0; i < size_Y; ++i)
	{
		for (int j = 0; j < size_X; ++j)
			cout << general_map[i][j];

		cout << endl;;
	}
}

void Screen::clear_Screen()
{
	for (int i = 0;i < size_Y; ++i)
	{
		for (int g = 0; g < size_X; ++g)
		{
			general_map[i][g] = ' ';
		}
	}
}

void Screen::go_to_layout(int num_L)
{
	if (num_L >= 0 && num_L < count_L)
	{
		Cur.change_current_L(&Lay_Col[num_L]);
	}
	else
	{
		Cur.print_layout_and_state();
		cout << "\tNo such layout" << endl;
	}
}

void Screen::print_enable_stat()
{
	for (int i = 0; i < count_L; ++i)
	{
		cout << "Layout_" << Lay_Col[i].Num << ": " << Lay_Col[i].is_enabled << endl;
	}
}

void Screen::change_enable_layout()
{
	int num = 0;
	while (true)
	{
		system("cls");
		cout << "Which one do you want to change?" << endl;
		print_enable_stat();
		cout << "Press 'Q' to confrim" << endl;
		num = (int)_getch();
		if (num == (int)'Q' || num == (int)'q')
		{
			Cur.print_layout_and_state();
			return;
		}
		else if(isdigit(num))
			Lay_Col[num-48].is_enabled = !Lay_Col[num-48].is_enabled;
	}
	
	
}

void Screen::combine_all_layouts()
{
	clear_Screen();
	for (int i = 0; i < this->count_L; ++i)
	{
		if (Lay_Col[i].is_enabled)
		{
			for (int j = 1; j < this->size_Y - 1; ++j)
			{
				for (int g = 1; g < this->size_X - 1; ++g) 
				{
					static bool is_printed;
					is_printed = Lay_Col[i].map[j][g] == Cur.mark;
					general_map[j][g] = Lay_Col[i].map[j][g] * (is_printed) + general_map[j][g]*!(is_printed);
				}
			}
			print_Screen();
		}
	}

}

void Screen::move(int ch_X, int ch_Y)
{
	Cur.move(ch_X, ch_Y);
}

void Screen::change_mod()
{
	Cur.is_snake_mode = !Cur.is_snake_mode;
	Cur.is_rubber = false;
	Cur.print_layout_and_state();
}

void Screen::change_rubber()
{
	Cur.is_rubber = !Cur.is_rubber;
	Cur.is_snake_mode = false;
	Cur.print_layout_and_state();
}

void Screen::clear_current_layout()
{
	Cur.clear_current_layout();
}