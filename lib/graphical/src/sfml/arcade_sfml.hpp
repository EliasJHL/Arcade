/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
** File description:
** arcade_sfml
*/

#ifndef ARCADE_SFML_HPP_
#define ARCADE_SFML_HPP_

#include "ADisplayModule.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Sfml : public ADisplayModule{
    public:
        Sfml();
        ~Sfml();
        void createWindow() override;
        void destroyWindow() override;
        void display() override;
        void clear() override;
        void drawText(const Text &text) override;
        void drawRect(const Rect &rect) override;
        std::vector<Event> getEvents() override;
        std::string getName() const override;
    private:
        std::string mName;
        sf::RenderWindow mWindow;
        sf::Font mFont;
};

#endif /* !ARCADE_SFML_HPP_ */
