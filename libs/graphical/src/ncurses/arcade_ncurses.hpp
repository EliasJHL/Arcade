/*
** arcade_ncurses.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/ncurses
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 15:04:30 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Mar 29 00:28:03 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ARCADE_NCURSES_HPP_
# define ARCADE_NCURSES_HPP_

#include "ADisplayModule.hpp"
#include <ncurses.h>
#include <curses.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <map>

struct SpriteCache {
    int size_x;
    int size_y;
    int center_x;
    int center_y;
    std::vector<char> pixels;
};

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
        void drawSprite(const Sprite &sprite) override {};
        std::vector<Event> getEvents() override;
        std::string getName() const override;
    private:
        void LoadNewSprite(const std::string &path);
        std::string mName;
        WINDOW *mWindow;
        std::map<std::string, SpriteCache> mSpriteCache;
};

#endif /* !ARCADE_NCURSES_HPP_ */
