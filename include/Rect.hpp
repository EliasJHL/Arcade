/*
** Rect.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 10:03:01 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Apr 5 16:04:33 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef RECT_HPP_
# define RECT_HPP_

#include "Color.hpp"
#include <string>

class Rect {
    public:
        Rect(int x, int y, int width, int height, Color color, std::string path);
        ~Rect();

        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        Color getColor() const;
        const std::string &getSpritePath() const;
    private:
        int _x;
        int _y;
        int _width;
        int _height;
        Color _color;
        std::string _spritePath;
};

#endif /* !RECT_HPP_ */
