/*
** IDisplay.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 14:38:19 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Mar 29 01:19:07 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef IDISPLAY_HPP_
# define IDISPLAY_HPP_

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Rect.hpp"
#include "Text.hpp"
#include "Sprite.hpp"
#include "../EventEnum.hpp"

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void createWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual std::string getName() const = 0;
        virtual void display() = 0;
        virtual void clear() = 0;
        virtual void drawText(const Text &text) = 0;
        virtual void drawRect(const Rect &rect) = 0;
        virtual void drawSprite(const Sprite &sprite) = 0;
        virtual std::vector<Event> getEvents() = 0;
};
#endif /* !IDISPLAY_HPP_ */
