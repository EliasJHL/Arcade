/*
** Sprite.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 28 10:46:04 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Mon Mar 30 21:16:52 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef SPRITE_HPP_
# define SPRITE_HPP_
#include <string>

class Sprite {
    public:
        Sprite(int x, int y, const std::string &path) : _x(x), _y(y), _path(path), _rotation(0) {};
        ~Sprite() {};
        float getRotation() const {return _rotation;}
        int getX() const {return _x;};
        int getY() const {return _y;};
        std::string getPath() const {return _path;};
    private:
        int _x;
        int _y;
        float _rotation;
        std::string _path;
};

#endif /* !SPRITE_HPP_ */
