/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
** File description:
** AGameModule
*/

#include "AGameModule.hpp"

AGameModule::AGameModule(std::string name) : _name(name)
{
};

void AGameModule::setGameSwitchCallback(std::function<void(std::string)> callback)
{
    _gameSwitchCallback = callback;
}

void AGameModule::setGraphicSwitchCallback(std::function<void(std::string)> callback)
{
    _graphicSwitchCallback = callback;
}

void AGameModule::setLibSwitchCallback(std::function<void()> callback)
{
    _libSwitchCallback = callback;
}

std::string AGameModule::getName() const
{
    return _name;
}

std::vector<Rect> AGameModule::getRects() const
{
    return _rects;
}

std::vector<Text> AGameModule::getTexts() const
{
    return _texts;
}

Event AGameModule::handleEventGeneric(Event event)
{
    if (event == Event::K_ESCAPE || event == Event::QUIT)
        return Event::QUIT;
    if (event == Event::NEXT_LIB) {
        switchToNextLib();
    }
    if (event == Event::NEXT_GAME) {
        switchToNextGame();
    }
    return Event::NONE;
}

void AGameModule::switchToNextGame(const std::string &gameName)
{
    if (_gameSwitchCallback) {
        _gameSwitchCallback(gameName);
    }
}

void AGameModule::switchToNextLib()
{
    if (_libSwitchCallback) {
        _libSwitchCallback();
    }
}