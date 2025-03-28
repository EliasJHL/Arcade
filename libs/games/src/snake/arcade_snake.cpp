/*
** arcade_snake.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games/src/snake
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Thu Mar 27 03:15:44 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 15:36:24 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_snake.hpp"

Snake::Snake(std::string name) : _Player(Rect{100, 100, 50, 50, Color{255, 255, 255, 255}})
{
    _rects.push_back(_Player);
}

Snake::~Snake()
{
}

std::string Snake::getName() const
{
    return _name;
}

std::vector<Rect> Snake::getRects() const
{
    return _rects;
}

std::vector<Text> Snake::getTexts() const
{
    return _texts;
}

void Snake::init()
{
    // a voir
}

void Snake::update()
{
    _rects.clear();
    _rects.push_back(_Player);
}

void Snake::stop()
{
    _rects.clear();
}

Event Snake::handleEvent(Event event)
{
    if (event == Event::K_UP)
        _Player._y -= 10;
    if (event == Event::K_DOWN)
        _Player._y += 10;
    if (event == Event::K_LEFT)
        _Player._x -= 10;
    if (event == Event::K_RIGHT)
        _Player._x += 10;
    return Event::NONE;
}


extern "C" {
    AGameModule *createGame() {
        return new Snake();
    }
}
