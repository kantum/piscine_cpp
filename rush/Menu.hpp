#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>

#define WIDTH 42
#define HEIGHT 10
#define N_CHOICES 2

class Menu {

	private:
		int _startX;
		int _startY;
		int _highlight;
		int _choice;
		int _c;
		int _n_choices;
		WINDOW *_menu_win;

		const char *_choices[2];

	public:
		virtual ~Menu();

		Menu();
		Menu(Menu const &src);
		Menu    &operator=(Menu const &rhs);
		WINDOW		*getMenuWin(void) const;
		int			getStartX(void) const;
		void		setStartX(int x);
		int			getStartY(void) const;
		void		setStartY(int x);
		void		setMenu(int ymax, int xmax);
		void		print_menu(WINDOW *menu_win, int highlight);
};


#endif
