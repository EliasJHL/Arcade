/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
** File description:
** Core
*/

#include "Core.hpp"
#include "DLLoader.hpp"
#include "../src/DLLoader.cpp"
#include <dirent.h>
#include <sys/types.h>
#include <iostream>
#include <regex>
#include <string>
#include <algorithm>
#include <set>

Core::Core()
{
}

Core::~Core()
{
}

void Core::ChangeDisplayModule(const std::string &name)
{
    if (mActiveGraphic) {
        mActiveGraphic->destroyWindow();
        mActiveGraphic.reset();
    }
    mActiveGraphic = std::unique_ptr<ADisplayModule>(mGraphicLoader.at(name)->getInstance("createDisplay"));
    mActiveGraphic->createWindow();
}

void Core::ChangeGameModule(const std::string &name)
{
    if (mActiveGame) {
        mActiveGame->stop();
        mActiveGame.reset();
    }
    mActiveGame = std::unique_ptr<AGameModule>(mGamesLoader.at(name)->getInstance("createGame"));
    mActiveGame->init();
}

std::string Core::NextGraphicalModule()
{
    std::string act = mActiveGraphic->getName();

    if (mAvailablesGraphics.size() <= 1) {
        std::cout << "[!] Only 1 Graphical library available" << std::endl;
        return act;
    }

    for (int i = 0; i < mAvailablesGraphics.size(); i++) {
        if (act == mAvailablesGraphics[i]) {
            if (i == mAvailablesGraphics.size() - 1) {
                return mAvailablesGraphics.front();
            } else {
                return mAvailablesGraphics[i + 1];
            }
        }
    }
    return mAvailablesGraphics.front();
}

std::string Core::NextGameModule()
{
    std::string act = mActiveGame->getName();

    if (mAvailablesGames.size() <= 1) {
        std::cout << "[!] Only 1 Game library available" << std::endl;
        return act;
    }

    for (int i = 0; i < mAvailablesGames.size(); i++) {
        if (act == mAvailablesGames[i]) {
            if (i == mAvailablesGames.size() - 1) {
                return mAvailablesGames.front();
            } else {
                return mAvailablesGames[i + 1];
            }
        }
    }
    return mAvailablesGames.front();
}

void Core::HandleEvents()
{
    std::vector<Event> events;
    
    events = mActiveGraphic->getEvents();

    for (int i = 0; i < events.size(); i++) {
        mActiveGame->handleEvent(events.at(i));
        if (events.at(i) == Event::NEXT_LIB) {
            ChangeDisplayModule(NextGraphicalModule());
            std::cout << "[i] Display engine changed to '" << mActiveGraphic->getName() << "'" << std::endl;
        }
        if (events.at(i) == Event::NEXT_GAME) {
            ChangeGameModule(NextGameModule());
            std::cout << "[+] Game changed to '" << mActiveGame->getName() << "'" << std::endl;
        }
        if (events.at(i) == Event::QUIT) {
            mActiveGraphic->destroyWindow();
            exit(0);
        }
    }
}

void Core::DrawElements()
{
    std::vector<Rect> rects = mActiveGame->getRects();
    std::vector<Text> texts = mActiveGame->getTexts();

    drawInteractiveMenu(&rects, &texts);
    
    if (!rects.empty()) {
        for (int i = 0; i < rects.size(); i++)
            mActiveGraphic->drawRect(rects[i]);
    }
    if (!texts.empty()) {
        for (int i = 0; i < texts.size(); i++)
            mActiveGraphic->drawText(texts[i]);
    }
}

void Core::drawInteractiveMenu(std::vector<Rect> *rects, std::vector<Text> *texts)
{
    return;
    return;
}

void Core::RunCore()
{
    mActiveGraphic->createWindow();
    mActiveGame->init();

    while(true) {
        HandleEvents();
        mActiveGame->update();
        mActiveGraphic->clear();
        DrawElements();
        mActiveGraphic->display();
    }
}

void Core::LoadFirstLibrary(const std::string &input) 
{
    std::regex const e{"arcade_([A-Za-z0-9\\+]+)\\.so"};
    std::smatch m;
    
    try {
        if (std::regex_search(input, m, e)) {
            mAvailablesGraphics.push_back(m[1]);
            mGraphicLoader.emplace(m[1], std::make_unique<DLLoader<ADisplayModule>>(input));
            mActiveGraphic = std::unique_ptr<ADisplayModule>(mGraphicLoader.at(m[1])->getInstance("createDisplay"));
            mLoadedLibraries.insert(m[1]);
            std::cout << "[+] OK : " << m[1] << " as graphical library loaded" << std::endl;
        }
    } catch (std::runtime_error &e) {
        throw std::runtime_error("[!] Error loading : " + std::string(e.what()));
    }
}

void Core::LoadAllLibraries(const std::string &input)
{
    const std::filesystem::path libraries{"lib"};
    std::regex const e{"arcade_([A-Za-z0-9\\+]+)\\.so"};
    std::smatch m;

    try {
        for (auto const& dir : std::filesystem::directory_iterator{libraries}) {
            bool isGame, isGraphic = false;
            std::string dirPath = std::string(dir.path());
            if (std::regex_search(dirPath, m, e)) {
                if (std::find(mAvailablesGraphics.begin(), mAvailablesGraphics.end(), m[1]) != mAvailablesGraphics.end())
                    continue;
                try {
                    if (std::make_unique<DLLoader<ADisplayModule>>(dirPath)->getInstance("createDisplay") != nullptr) {
                        mAvailablesGraphics.push_back(m[1]);
                        mGraphicLoader.emplace(m[1], std::make_unique<DLLoader<ADisplayModule>>("./" + dirPath));
                        std::cout << "[GRAPH] " << dirPath << " is loaded" << std::endl;
                    }
                } catch (const std::exception &ex) {
                    if (std::make_unique<DLLoader<AGameModule>>(dirPath)->getInstance("createGame") != nullptr) {
                        mAvailablesGames.push_back(m[1]);
                        mGamesLoader.emplace(m[1], std::make_unique<DLLoader<AGameModule>>("./" + dirPath));
                        std::cout << "[GAMES] " << dirPath << " is loaded" << std::endl;
                    } else {
                        std::cout << "[UNKNW] " << dirPath << " is an invalid library" << std::endl;
                    }
                }
            }
        }
    } catch (std::runtime_error &e) {
        throw std::runtime_error("[!] Error loading : " + std::string(e.what()));
    }
}

void Core::LoadLibraries(int ac, char **av)
{
    std::cout << "[+] Loading libraries..." << std::endl;
    if (ac != 2)
        throw std::runtime_error("Usage : ./arcade <path to graphic>");

    std::string input(av[1]);
    
    LoadFirstLibrary(input);
    LoadAllLibraries(input);

    if (!mAvailablesGames.empty()) {
        mActiveGame = std::unique_ptr<AGameModule>(mGamesLoader.find("menu")->second->getInstance("createGame"));
        mActiveGame->setGameSwitchCallback([this](const std::string &gameName) {
            this->ChangeGameModule(gameName);
        });
        mActiveGame->setGraphicSwitchCallback([this](const std::string &graphicName) {
            this->ChangeDisplayModule(graphicName);
        });
        std::cout << "[+] First Game loaded" << std::endl;
    }
    std::cout << "[+] All libraries are loaded" << std::endl;
}
