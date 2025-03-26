/*
** Color.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 19:52:19 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 19:55:42 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "Color.hpp"

Color::Color(int r, int g, int b, int a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

Color::Color()
{
    _r = 255;
    _g = 255;
    _b = 255;
    _a = 255;
}

Color::~Color()
{
}

int Color::getR() const 
{
    return _r;
}

int Color::getG() const
{
    return _g;
}

int Color::getB() const
{
    return _b;
}

int Color::getA() const
{
    return _a;
}