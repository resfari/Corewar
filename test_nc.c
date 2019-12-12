
#include <ncurses.h>

int main()
{
    initscr();                 // Инициализация ncurses
    curs_set(0);               // Делаем курсор невидимым
    printw("Hello, World!");   // Вывод строки Hello, World!
    refresh();                 // Отображение строки на реальном экране
    getch();                   // Ожидание пользовательского ввода
    endwin();                  // Завершение работы с ncurses
	return (0);
}