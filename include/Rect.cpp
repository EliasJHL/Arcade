/*
** Rect.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 19:11:53 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Apr 5 15:31:35 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "Rect.hpp"

Rect::Rect(int x, int y, int width, int height, Color color, std::string path)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _color = color;
    _spritePath = path;
}

Rect::~Rect()
{
}

int Rect::getX() const
{
    return _x;
}

int Rect::getY() const
{
    return _y;
}

int Rect::getWidth() const
{
    return _width;
}

int Rect::getHeight() const
{
    return _height;
}

Color Rect::getColor() const
{
    return _color;
}

const std::string &Rect::getSpritePath() const
{
    return _spritePath;
}