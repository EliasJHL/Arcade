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
    std::filesystem::path libraries{"lib"};
    std::regex const e{"arcade_([A-Za-z0-9\\+]+)\\.so"};
    std::vector<std::string> games = {"snake", "minesweeper", "nibbler", "pacman", "qix", "centipede", "solarfox"};
    std::vector<std::string> graphic = {"ndk++", "aa-lib", "libcaca", "allegro5", "xlib", "gtk+", "sfml", "irrlicht", "opengl", "vulkan", "qt5", "ncurses", "sdl2"};
    std::smatch m;

    _name = name;

    for (auto const& dir : std::filesystem::directory_iterator{libraries}) {
        std::string dirPath = std::string(dir.path());
        if (std::regex_search(dirPath, m, e)) {
            if (std::find(games.begin(), games.end(), m[1]) != games.end()) {
                mGames.push_back(m[1]);
            }
        }
    }
    for (auto const& dir : std::filesystem::directory_iterator{libraries}) {
        std::string dirPath = std::string(dir.path());
        if (std::regex_search(dirPath, m, e)) {
            if (std::find(graphic.begin(), graphic.end(), m[1]) != graphic.end()) {
                mGraphic.push_back(m[1]);
            }
        }
    }
    if (!mGames.empty())
        selected_game = mGames.at(0);
    if (!mGraphic.empty())
        selected_graph = mGraphic.at(0);
    isGameSelected = false;
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

    _texts.push_back(Text{305, 40, 70, "assets/basic.ttf", "ARCADE", false, false, Color{255, 255, 255, 255}});

    _texts.push_back(Text{10, 175, 30, "assets/basic.ttf", "Available games :", false, false, Color{255, 255, 255, 255}});
    for (int i = 0; i < mGames.size(); i++) {
        if (mGames.at(i) == selected_game)
            _texts.push_back(Text{10, y, 30, "assets/basic.ttf", std::string("*" + mGames.at(i)), false, false, Color{0, 200, 200, 255}});
        else
            _texts.push_back(Text{10, y, 30, "assets/basic.ttf", mGames.at(i), false, false, Color{200, 200, 200, 255}});
        y += 50;
    }
    y = 225;
    _texts.push_back(Text{400, 175, 30, "assets/basic.ttf", "Available graphic :", false, false, Color{255, 255, 255, 255}});
    for (int i = 0; i < mGraphic.size(); i++) {
        if (mGraphic.at(i) == selected_graph && isGameSelected)
            _texts.push_back(Text{400, y, 30, "assets/basic.ttf", std::string("*" + mGraphic.at(i)), false, false, Color{0, 200, 200, 255}});
        else    
            _texts.push_back(Text{400, y, 30, "assets/basic.ttf", mGraphic.at(i), false, false, Color{200, 200, 200, 255}});
        y += 50;
    }
    _texts.push_back(Text{10, 505, 20, "assets/basic.ttf", "Core Keybinds :", false, false, Color{255, 255, 255, 255}});
    _texts.push_back(Text{10, 535, 20, "assets/basic.ttf", "'T' Change graphical library", false, false, Color{255, 255, 255, 255}});
    _texts.push_back(Text{10, 565, 20, "assets/basic.ttf", "'Y' Change Game library", false, false, Color{255, 255, 255, 255}});
}

void Menu::stop()
{

}

Event Menu::handleEvent(Event event)
{
    if (!isGameSelected) {
        if (event == Event::K_RETURN)
            isGameSelected = true;
        if (event == Event::K_UP) {
            if (!mGames.empty()) {
                auto it = std::find(mGames.begin(), mGames.end(), selected_game);
                if (it != mGames.end() && it != mGames.begin()) {
                    selected_game = *(std::prev(it));
                } else {
                    selected_game = mGames.back();
                }
            }
        }
        if (event == Event::K_DOWN) {
            if (!mGames.empty()) {
                auto it = std::find(mGames.begin(), mGames.end(), selected_game);
                if (it != mGames.end() && std::next(it) != mGames.end()) {
                    selected_game = *(std::next(it));
                } else {
                    selected_game = mGames.front();
                }
            }
        }
    } else {
        if (event == Event::K_RETURN) {
            if (_gameSwitchCallback)
                _gameSwitchCallback(selected_game);
            if (_graphicSwitchCallback)
                _graphicSwitchCallback(selected_graph);
        }
        if (event == Event::K_UP) {
            if (!mGraphic.empty()) {
                auto it = std::find(mGraphic.begin(), mGraphic.end(), selected_graph);
                if (it != mGraphic.end() && it != mGraphic.begin()) {
                    selected_graph = *(std::prev(it));
                } else {
                    selected_graph = mGraphic.back();
                }
            }
        }
        if (event == Event::K_DOWN) {
            if (!mGraphic.empty()) {
                auto it = std::find(mGraphic.begin(), mGraphic.end(), selected_graph);
                if (it != mGraphic.end() && std::next(it) != mGraphic.end()) {
                    selected_graph = *(std::next(it));
                } else {
                    selected_graph = mGraphic.front();
                }
            }
        }
    }
    return Event::NONE;
}

extern "C" {
    AGameModule *createGame() {
        return new Menu();
    }
}