/*
** Rect.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 10:03:01 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 03:34:46 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef RECT_HPP_
# define RECT_HPP_

#include "Color.hpp"

class Rect {
    public:
        Rect(int x, int y, int width, int height, Color color);
        ~Rect();

        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        Color getColor() const;

        int _x;
        int _y;
        int _width;
        int _height;
        Color _color;
    private:
};

#endif /* !RECT_HPP_ */
