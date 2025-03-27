/*
** arcade_ncurses.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/ncurses
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 15:04:30 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 02:24:53 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ARCADE_NCURSES_HPP_
# define ARCADE_NCURSES_HPP_

#include "ADisplayModule.hpp"
#include <ncurses.h>

class Ncurses : public ADisplayModule{
    public:
        Ncurses();
        ~Ncurses();
        void createWindow() override;
        void destroyWindow() override;
        void display() override;
        void clear() override;
        void drawText(const Text &text) override;
        void drawRect(const Rect &rect) override;
        std::vector<Event> getEvents() override;
        std::string getName() const override;
    private:
        std::string mName;
        WINDOW *mWindow;
};

#endif /* !ARCADE_NCURSES_HPP_ */
