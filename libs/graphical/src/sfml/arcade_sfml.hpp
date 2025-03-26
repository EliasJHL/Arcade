/*
** arcade_sfml.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/sfml
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:39:09 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 19:26:31 2025 Elias Josué HAJJAR LLAUQUEN
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
};

#endif /* !ARCADE_SFML_HPP_ */
