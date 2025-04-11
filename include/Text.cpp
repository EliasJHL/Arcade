/*
** Text.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 19:16:04 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Apr 5 16:09:48 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "Text.hpp"

Text::Text(int x, int y, int size, const std::string &font, const std::string &text, bool centeredX, bool centeredY, Color color = Color(255, 255, 255, 255))
{
    _x = x;
    _y = y;
    _centeredX = centeredX;
    _centeredY = centeredY;
    _size = size;
    _font = font;
    _text = text;
    _color = color;
}

Text::~Text()
{
}

int Text::getX() const 
{
    return _x;
}

int Text::getY() const
{
    return _y;
}

int Text::getSize() const
{
    return _size;
}

std::string Text::getFont() const
{
    return _font;
}

std::string Text::getText() const 
{
    return _text;
}

bool Text::isCenteredX() const
{
    return _centeredX;
}

bool Text::isCenteredY() const
{
    return _centeredY;
}

Color Text::getColor() const
{
    return _color;
}