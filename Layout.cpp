#include "Layout.h"

using std::cout;
using std::cin;
using std::endl;

Layout::Layout()
{
	map = new char* [size_Y];
	for (int i = 0; i < size_Y; ++i)
	{
		map[i] = new char[size_X];
	}
	is_enabled = false;
	fill_layout();
}

void Layout::fill_layout()
{
	for (int i = 1; i < (size_Y - 1); ++i)
	{
		map[i][0] = border;
		map[i][size_X - 1] = border;
		for (int j = 1; j < (size_X - 1); ++j)
			map[i][j] = space;
	}
	for (int j = 0; j < size_X; ++j)
	{
		map[0][j] = border;
		map[size_Y - 1][j] = border;
	}
}

void Layout::print_layout()
{
	system("cls");
	cout << "Layout_" << Num << endl;
	for (int i = 0; i < size_Y; ++i)
	{
		for (int j = 0; j < size_X; ++j)
			cout << map[i][j];

		cout << endl;;
	}
}

Layout::~Layout()
{
	for (int i = 0; i < size_Y; ++i)
	{
		delete [] map[i];
	}
	delete[] map;
}
