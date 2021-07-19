#include "CGR.h"

#include "Layout.h"
#include "Cursor.h"
#include "Screen.h"

inline void start_info()
{
	std::cout << "made by pesiKey\n\nUse 'WASD' to move\n'L' to draw\n'M' to erase the drawing\n'R' to clear the whole layout\n'Q' to exit\n";
	_getch();
}

void Console_redactor()
{
	start_info();

	Screen Main;
	while (true)
	{
		static int key;
		switch (key = _getch()) // char type is used here to simplyfy understanding 
		{
		case 'W':
		case 'w': Main.move(0, -1); break; //Up
		case 'S':
		case 's': Main.move(0, 1); break; //Down
		case 'D':
		case 'd': Main.move(1, 0); break; //Left
		case 'A':
		case 'a': Main.move(-1, 0); break; //Right

		case 'L':
		case 'l': Main.change_mod(); break;
		case 'M':
		case 'm': Main.change_rubber(); break;

		case 'E':
		case 'e': Main.change_enable_layout(); break; 

		case 'C':
		case 'c': Main.combine_all_layouts(); break;
		case 'R':
		case 'r': Main.clear_current_layout(); break;

		case 'q':
		case 'Q': return; break;

		//swithching between layouts
		default:
			if (isdigit(key))
				Main.go_to_layout(key - 48); // (int)'0' == 48 
		}
	}
}