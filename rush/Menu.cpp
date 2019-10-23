#include "Menu.hpp"
#include <iostream>
Menu::Menu() {
	this->_n_choices = sizeof(this->_choices) / sizeof(char *);

	for (int i = 0; i < N_CHOICES; i++)

	this->_choices[0] = "Start/Restart game";
	this->_choices[1] = "Quit";
}

Menu::~Menu() {
	erase();
}

Menu::Menu(Menu const &src) {
    *this = src;
}

Menu &Menu::operator=(Menu const &rhs) {
    if (this != &rhs)
	{
		this->_startX = rhs._startX;
		this->_startY = rhs._startY;
		this->_highlight = rhs._highlight;;
		this->_choice = rhs._choice;;
		this->_c = rhs._c;
		this->_n_choices = rhs._n_choices;
		this-> _menu_win = rhs._menu_win;
		this->_choices[0] = rhs._choices[0];
		this->_choices[1] = rhs._choices[1];
	}
	return *this;
}

int	Menu::getStartX(void) const
{
	return(this->_startX);
}

void Menu::setStartX(int x)
{
	this->_startX = x;
}

int Menu::getStartY(void) const
{
	return(this->_startY);
}

void Menu::setStartY(int y)
{
	this->_startY = y;
}

WINDOW		*Menu::getMenuWin(void) const
{
	return this->_menu_win;
}

void Menu::setMenu(int ymax, int xmax)
{
	this->_highlight = 1;
	this->_choice = 0;
	this->_startX = (xmax - WIDTH) / 2;
	this->_startY = (ymax - HEIGHT) / 2;

	this->_menu_win = newwin(HEIGHT, WIDTH, this->_startY, this->_startX);

	keypad(this->_menu_win, TRUE);
	print_menu(this->_menu_win, this->_highlight);
	while(1)
	{	
		this->_c = wgetch(this->_menu_win);
		switch(_c)
		{	
			case KEY_UP:
				if (this->_highlight == 1)
					this->_highlight = this->_n_choices;
				else
					--this->_highlight;
				break;
			case KEY_DOWN:
				if(this->_highlight == this->_n_choices)
					this->_highlight = 1;
				else
					++this->_highlight;
				break;
			case 10: // enter
				this->_choice = this->_highlight;
				break;
			default:
				refresh();
				break;
		}
        if(this->_choice == 2) {
            endwin();
            exit(0);
        }
		print_menu(this->_menu_win, this->_highlight);
		if(this->_choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}
}

void Menu::print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < this->_n_choices; ++i)
	{	
		if(highlight == i + 1) /* High light the present choice */
		{	
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", this->_choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", this->_choices[i]);
		++y;
	}
	wrefresh(menu_win);
}
