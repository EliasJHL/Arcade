/*
** lib-sfml.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/src
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Thu Mar 20 14:47:24 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 15:36:12 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_ncurses.hpp"

Ncurses::Ncurses()
{
    mName = "ncurses";
}

Ncurses::~Ncurses()
{
    destroyWindow();
}

void Ncurses::createWindow()
{
    initscr();
    curs_set(0);
    start_color();
    timeout(100);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
}

void Ncurses::destroyWindow()
{
    endwin();
}

void Ncurses::display()
{
    refresh();
}

void Ncurses::clear()
{
    ::clear();
}

void Ncurses::drawText(const Text &text)
{
    init_color(8, text.getColor().getR(), text.getColor().getG(), text.getColor().getB());
    init_pair(1, 8, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvprintw(text.getY() / 2, text.getX(), text.getText().c_str());
    attroff(COLOR_PAIR(1));
}

void Ncurses::drawRect(const Rect &rect)
{
    init_color(8, rect.getColor().getR(), rect.getColor().getG(), rect.getColor().getB());
    init_pair(1, 8, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    int x1 = rect.getX() / 10;
    int x2 = rect.getX() / 10 + rect.getWidth() / 10;
    int y1 = rect.getY() / 20;
    int y2 = rect.getY() / 20 + rect.getHeight() / 20;

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            mvaddch(y, x, ACS_BLOCK);
        }
    }
    
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    attroff(COLOR_PAIR(1));
}

std::vector<Event> Ncurses::getEvents()
{
    std::vector<Event> events;
    int ch = getch();

    switch (ch) {
        case 't':
        case 'T':
            events.push_back(Event::NEXT_LIB);
            break;
        case KEY_UP:
            events.push_back(Event::K_UP);
            break;
        case KEY_DOWN:
            events.push_back(Event::K_DOWN);
            break;
        case KEY_LEFT:
            events.push_back(Event::K_LEFT);
            break;
        case KEY_RIGHT:
            events.push_back(Event::K_RIGHT);
            break;
    }
    return events;
}

std::string Ncurses::getName() const
{
    return mName;
}

extern "C" {
    ADisplayModule *createDisplay() {
        return new Ncurses();
    }
}