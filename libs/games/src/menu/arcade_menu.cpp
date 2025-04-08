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
#include "DLLoader.hpp"
#include <iostream>
#include <filesystem>
#include <regex>
#include <dlfcn.h>

Menu::Menu(std::string name)
{
    std::filesystem::path libraries{"libs"};
    std::regex const e{"arcade_([A-Za-z0-9\\+]+)\\.so"};
    std::smatch m;
    void *handler;

    _name = name;

    for (auto const& dir : std::filesystem::directory_iterator{libraries}) {
        std::string dirPath = std::string(dir.path());
        if (std::regex_search(dirPath, m, e)) {
            if (m[1] != "menu") {
                handler = dlopen(dirPath.c_str(), RTLD_LAZY);
                if (dlsym(handler, "createGame") != nullptr) {
                    mGames.push_back(m[1]);
                }
            }
        }
    }
    for (auto const& dir : std::filesystem::directory_iterator{libraries}) {
        std::string dirPath = std::string(dir.path());
        if (std::regex_search(dirPath, m, e)) {
            if (m[1] != "menu") {
                handler = dlopen(dirPath.c_str(), RTLD_LAZY);
                if (dlsym(handler, "createDisplay") != nullptr) {
                    mGraphic.push_back(m[1]);
                }
            }
        }
    }
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

void Menu::init()
{
    // a voir
}

void Menu::update()
{
    _rects.clear();
    _texts.clear();
    int y = 225;

    _texts.push_back(Text{305, 40, 70, "assets/basic.ttf", "ARCADE", Color{255, 255, 255, 255}});

    _texts.push_back(Text{10, 175, 30, "assets/basic.ttf", "Available games :", Color{255, 255, 255, 255}});
    for (int i = 0; i < mGames.size(); i++) {
        _texts.push_back(Text{10, y, 30, "assets/basic.ttf", mGames.at(i), Color{200, 200, 200, 255}});
        y += 50;
    }
    y = 225;
    _texts.push_back(Text{400, 175, 30, "assets/basic.ttf", "Available graphic :", Color{255, 255, 255, 255}});
    for (int i = 0; i < mGames.size(); i++) {
        _texts.push_back(Text{400, y, 30, "assets/basic.ttf", mGraphic.at(i), Color{200, 200, 200, 255}});
        y += 50;
    }
    _texts.push_back(Text{300, 425, 20, "assets/basic.ttf", "Core Keybinds :", Color{255, 255, 255, 255}});
    _texts.push_back(Text{300, 475, 20, "assets/basic.ttf", "'T' Change graphical library", Color{255, 255, 255, 255}});
    _texts.push_back(Text{300, 525, 20, "assets/basic.ttf", "'Y' Change Game library", Color{255, 255, 255, 255}});
}

void Menu::stop()
{
}

Event Menu::handleEvent(Event event)
{
    return Event::NONE;
}

extern "C" {
    AGameModule *createGame() {
        return new Menu();
    }
}