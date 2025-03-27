/*
** Text.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 10:02:41 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 20:47:13 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef TEXT_HPP_
# define TEXT_HPP_

#include "Color.hpp"
#include <string>

class Text {
    public:
        Text(int, int, int, const std::string &, const std::string &, Color color);
        ~Text();

        int getX() const;
        int getY() const;
        int getSize() const;
        std::string getFont() const;
        std::string getText() const;
        Color getColor() const;

    private:
        int _x;
        int _y;
        int _size;
        std::string _font;
        std::string _text;
        Color _color;
};

#endif /* !TEXT_HPP_ */
