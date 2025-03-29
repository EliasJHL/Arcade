/*
** arcade_menu.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games/src/menu
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Sat Mar 29 00:29:47 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Mar 29 01:21:35 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_menu.hpp"

Menu::Menu(std::string name)
{
    _name = name;
}

Menu::~Menu()
{
}

std::string Menu::getName() const
{
    return _name;
}

std::vector<Rect> Menu::getRects() const
{
    return _rects;
}

std::vector<Text> Menu::getTexts() const
{
    return _texts;
}

std::vector<Sprite> Menu::getSprites() const
{
    return _sprites;
}

void Menu::init()
{
    // a voir
}

void Menu::update()
{
    _rects.clear();
    _texts.clear();
    _sprites.clear();
    
    _rects.push_back(Rect{800, 100, 0, 0, Color{50, 50, 50, 255}});
    _texts.push_back(Text{305, 40, 70, "basic", "ARCADE", Color{255, 255, 255, 255}});

    _rects.push_back(Rect{260, 0, 270, 600, Color{70, 70, 70, 255}});
    
    _texts.push_back(Text{350, 225, 40, "basic", "SNAKE", Color{200, 200, 200, 255}});
    _texts.push_back(Text{340, 325, 40, "basic", "PACMAN", Color{200, 200, 200, 255}});
    _texts.push_back(Text{360, 425, 40, "basic", "EXIT", Color{200, 200, 200, 255}});
}

void Menu::stop()
{
    _rects.clear();
    _sprites.clear();
}

Event Menu::handleEvent(Event event)
{
}

extern "C" {
    AGameModule *createGame() {
        return new Menu();
    }
}