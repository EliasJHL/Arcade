/*
** arcade_Xlib.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/Xlib
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:40:12 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Mar 29 22:33:51 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_xlib.hpp"
#include "Text.hpp"
#include "Color.hpp"

Xlib::Xlib()
{
    mName = "Xlib";
}

Xlib::~Xlib()
{
    destroyWindow();
}

void Xlib::createWindow()
{
    mDisplay = XOpenDisplay(0); // Ouverture d'un display
    if (mDisplay) {
        mWindow = XCreateWindow(mDisplay, DefaultRootWindow(mDisplay), 0, 0, 800, 600, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0);
    }
}

void Xlib::destroyWindow()
{
    mWindow.close();
}

void Xlib::display()
{
    if (mWindow.isOpen())
        mWindow.display();
}

void Xlib::clear()
{
    cleanup();
}

void Xlib::drawText(const Text &text)
{
    sf::Font font;
    //sf::Text message;
    if (!mWindow.isOpen())
        return;

    font.loadFromFile("./include/fonts/" + text.getFont() + ".ttf");
    
    sf::Text message(text.getText(), font);
    //message.setPosition(text.getX(), text.getY());
    //message.setFillColor(sf::Color(text.getColor().getR(), text.getColor().getG(), text.getColor().getB(), text.getColor().getA()));
    //mWindow.draw(message);
}

void Xlib::drawRect(const Rect &rect)
{
    // if (!mWindow.isOpen())
    //     return;
    // sf::RectangleShape shape(sf::Vector2f(rect.getWidth(), rect.getHeight()));
    // shape.setPosition(rect.getX(), rect.getY());
    // shape.setFillColor(sf::Color(rect.getColor().getR(), rect.getColor().getG(), rect.getColor().getB() ,rect.getColor().getA()));

    // mWindow.draw(shape);
}

std::vector<Event> Xlib::getEvents()
{
    std::vector<Event> events;

    if (!mWindow.isOpen())
        return events;
    
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
            events.push_back(Event::NEXT_LIB);
        if (event.type == sf::Event::Closed)
            events.push_back(Event::QUIT);
    }
    return events;
}

std::string Xlib::getName() const
{
    return mName;
}

extern "C" {
    ADisplayModule *createDisplay() {
        return new Xlib();
    }
}
