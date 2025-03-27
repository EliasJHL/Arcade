/*
** arcade_snake.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games/src/snake
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Thu Mar 27 03:15:44 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 03:35:09 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_snake.hpp"

Snake::Snake(std::string name) : _name(name)
{   
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
    Color color {120, 120, 120, 255};
    Rect player {400, 300, 50, 50, color};
    _rects.push_back(player);
}

void Snake::update()
{
    
}

void Snake::stop()
{
    
}

Event Snake::handleEvent(Event event)
{
    if (event == Event::K_UP)
        _rects[0]._x += 10;
    return event;
}