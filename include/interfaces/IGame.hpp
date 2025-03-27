/*
** IGame.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 14:38:09 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 01:04:44 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef IGAME_HPP_
# define IGAME_HPP_

#include <iostream>
#include "IDisplay.hpp"
#include "../Rect.hpp"
#include "../Text.hpp"
#include <vector>
#include <functional>

class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual std::string getName() const = 0;
        virtual void update() = 0;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual std::vector<Rect> getRects() const = 0;
        virtual std::vector<Text> getTexts() const = 0;
        virtual Event handleEvent(Event event) = 0;
        virtual void setGameSwitchCallback(std::function<void(std::string)> callback) = 0;
        virtual void setLibSwitchCallback(std::function<void()> callback) = 0;
        virtual Event handleEventGeneric(Event event) = 0;
};

#endif /* !IGAME_HPP_ */
