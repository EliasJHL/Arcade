/*
** Core.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 12:07:27 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 03:26:24 2025 Elias Josué HAJJAR LLAUQUEN
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
    // mActiveGame = 
    std::cout << "[+] Game changed to /'" << name << "/'" << std::endl;
}

std::string Core::NextGraphicalModule()
{
    std::string act = mActiveGraphic->getName();

    if (mAvailablesGraphics.size() <= 1) {
        std::cout << "[!] Only 1 Graphical library available" << std::endl;
        return act;
    }

    for (size_t i = 0; i < mAvailablesGraphics.size(); i++) {
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

void Core::RunCore()
{
    std::vector<Event> events;
    mActiveGraphic->createWindow();

    while(true) {
        mActiveGraphic->clear();
        Color color{255,255,255,255};
        // Text text{0, 0, 20, "basic", "hahaha", color};
        // mActiveGraphic->drawText(text);
        // Text text1{0, 50, 20, "basic", "hahaha", color};
        // mActiveGraphic->drawText(text1);
        Rect rect{100, 100, 100, 100, color};
        mActiveGraphic->drawRect(rect);
        events = mActiveGraphic->getEvents();
        if (!events.empty()) {
            for (int i = 0; i < events.size(); i++) {
                if (events.at(i) == Event::NEXT_LIB) {
                    ChangeDisplayModule(NextGraphicalModule());
                    std::cout << "[i] Display engine changed to '" << mActiveGraphic->getName() << "'" << std::endl;
                }
                if (events.at(i) == Event::QUIT) {
                    mActiveGraphic->destroyWindow();
                    exit(0);
                }
            }
        }
        mActiveGraphic->display();
    }
}

void Core::LoadLibraries(int ac, char **av)
{
    DIR *dr;
    struct dirent *en;
    std::regex const e{"arcade_([A-Za-z0-9\\+]+)\\.so"};
    std::vector<std::string> graphic_list = {"sfml", "sdl2", "ncurses"};
    std::vector<std::string> games_list = {"snake", "minesweeper", "pacman"};
    std::set<std::string> loadedLibraries;
    std::smatch m;

    if (ac < 2)
        throw std::runtime_error("Usage : ./arcade <path to graphic>");

    std::string input(av[1]);
    
    if (std::regex_search(input, m, e)) {
        if (std::find(graphic_list.begin(), graphic_list.end(), m[1]) != graphic_list.end()) {
            mAvailablesGraphics.push_back(m[1]);
            
            mGraphicLoader.emplace(m[1], std::make_unique<DLLoader<ADisplayModule>>(input));
            mActiveGraphic = std::unique_ptr<ADisplayModule>(mGraphicLoader.at(m[1])->getInstance("createDisplay"));
            
            loadedLibraries.insert(m[1]);
            // mActiveGame menu
            std::cout << "[!] OK : " << m[1] << " as graphical library loaded" << std::endl;
        } else {
            throw std::runtime_error("Error: '" + input + "' not a graphical library");
        }
    } else {
        throw std::runtime_error("Error: '" + input + "' not a graphical library");
    }

    std::cout << "[+] Loading libraries..." << std::endl;
    dr = opendir("./libs");
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            std::string file(en->d_name);
            if (std::regex_search(file, m, e)) {
                if (loadedLibraries.find(m[1]) != loadedLibraries.end()) {
                    std::cout << "  -> " << m[1] << " already loaded, skipping" << std::endl;
                    continue;
                }
                if (std::find(graphic_list.begin(), graphic_list.end(), m[1]) != graphic_list.end()) {
                    mAvailablesGraphics.push_back(m[1]);
                    mGraphicLoader.emplace(m[1], std::make_unique<DLLoader<ADisplayModule>>("./libs/" + file));
                    std::cout << "  -> " << m[1] << " loaded" << std::endl;
                } else if (std::find(games_list.begin(), games_list.end(), m[1]) != games_list.end()) {
                    mAvailablesGames.push_back(m[1]);
                    mGamesLoader.emplace(m[1], std::make_unique<DLLoader<ADisplayModule>>("./libs/" + file));
                    std::cout << "  -> " << m[1] << " loaded" << std::endl;
                } else {
                    std::cout << "Error: Unknown library: " << file << std::endl;
                }
            }
        }
        closedir(dr);
    } else {
        throw std::runtime_error("Error: Could not open directory ./libs");
    }
    std::cout << "[!] All libraries are loaded" << std::endl;
}