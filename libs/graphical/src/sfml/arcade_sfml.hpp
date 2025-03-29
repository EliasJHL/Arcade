/*
** arcade_sfml.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/sfml
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:39:09 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sat Mar 28 11:06:27 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ARCADE_SFML_HPP_
# define ARCADE_SFML_HPP_

#include "ADisplayModule.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Sfml : public ADisplayModule {
    public:
        Sfml();
        ~Sfml();
        void createWindow() override;
        void destroyWindow() override;
        void display() override;
        void clear() override;
        void drawText(const Text &text) override;
        void drawRect(const Rect &rect) override;
        void drawSprite(const Sprite &sprite) override;
        std::vector<Event> getEvents() override;
        std::string getName() const override;
    private:
        std::string mName;
        sf::RenderWindow mWindow;
        sf::Font mFont;
        sf::Text mMessage;
};

#endif /* !ARCADE_SFML_HPP_ */
