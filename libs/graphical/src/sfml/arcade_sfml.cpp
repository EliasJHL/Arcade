/*
** arcade_sfml.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/sfml
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:40:12 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 15:36:00 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_sfml.hpp"
#include "Text.hpp"
#include "Color.hpp"

Sfml::Sfml()
{
    mName = "sfml";
}

Sfml::~Sfml()
{
    destroyWindow();
}

void Sfml::createWindow()
{
    sf::VideoMode mode (800, 600, 32);
    mWindow.create(mode, "Aracade", sf::Style::Close);
    mFont.loadFromFile("./include/fonts/basic.ttf");
}

void Sfml::destroyWindow()
{
    if (mWindow.isOpen())
        mWindow.close();
}

void Sfml::display()
{
    mWindow.display();
}

void Sfml::clear()
{
    if (mWindow.isOpen())
        mWindow.clear(sf::Color::Black);
}

void Sfml::drawText(const Text &text)
{
    if (!mWindow.isOpen())
        return;

    //mFont.loadFromFile("./include/fonts/" + text.getFont() + ".ttf");
    
    mMessage.setFont(mFont);
    mMessage.setString(text.getText());
    mMessage.setPosition(text.getX(), text.getY());
    mMessage.setFillColor(sf::Color(text.getColor().getR(), text.getColor().getG(), text.getColor().getB(), text.getColor().getA()));
    mWindow.draw(mMessage);
}

void Sfml::drawRect(const Rect &rect)
{
    if (!mWindow.isOpen())
        return;
    sf::RectangleShape shape(sf::Vector2f(rect.getWidth(), rect.getHeight()));
    shape.setPosition(rect.getX(), rect.getY());
    shape.setFillColor(sf::Color(rect.getColor().getR(), rect.getColor().getG(), rect.getColor().getB() ,rect.getColor().getA()));

    mWindow.draw(shape);
}

std::vector<Event> Sfml::getEvents()
{
    std::vector<Event> events;

    if (!mWindow.isOpen())
        return events;
    
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
            events.push_back(Event::NEXT_LIB);
    }
    return events;
}

std::string Sfml::getName() const
{
    return mName;
}

extern "C" {
    ADisplayModule *createDisplay() {
        return new Sfml();
    }
}
