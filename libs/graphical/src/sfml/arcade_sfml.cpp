/*
** arcade_sfml.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/sfml
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:40:12 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 19:47:05 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_sfml.hpp"

Sfml::Sfml()
{
    
}

void Sfml::createWindow()
{
    sf::VideoMode mode (800, 600, 32);
    mWindow.create(mode, "Aracade", sf::Style::Close);
}

void Sfml::destroyWindow()
{
    if (&mWindow != nullptr) {
        if (mWindow.isOpen())
            mWindow.close();
        delete &mWindow;
    }
}

void Sfml::display()
{
    mWindow.display();
}

void Sfml::clear()
{
    mWindow.clear(sf::Color::Black);
}

void Sfml::drawText(const Text &text)
{
    if (&mWindow == nullptr || !mWindow.isOpen())
        return;
    
    sf::Text message;
    sf::Font font;

    font.loadFromFile("../../../../include/fonts/" + text.getText() + ".ttf");

    message.setFont(font);
    message.setString(text.getText());
    message.setPosition(text.getX(), text.getY());
    message.setFillColor(sf::Color(text.getColor().getR(), text.getColor().getG(), text.getColor().getB(), text.getColor().getA()));

    mWindow.draw(message);
}

void Sfml::drawRect(const Rect &rect)
{
    if (&mWindow == nullptr || !mWindow.isOpen())
        return;
    sf::RectangleShape shape(sf::Vector2f(rect.getWidth(), rect.getHeight()));
    shape.setPosition(rect.getX(), rect.getY());
    shape.setFillColor(sf::Color(rect.getColor().getR(), rect.getColor().getG(), rect.getColor().getB() ,rect.getColor().getA()));

    mWindow.draw(shape);
}

std::vector<Event> Sfml::getEvents()
{
    
}

std::string Sfml::getName() const
{
    return mName;
}

extern "C" {
    ADisplayModule* createDisplay() {
        return new Sfml();
    }
}
