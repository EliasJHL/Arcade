/*
** Core.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 12:07:27 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 19:56:01 2025 Elias Josué HAJJAR LLAUQUEN
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
    //delete mActiveGraphic;
    mActiveGraphic = mGraphicLoader.at(name).getInstance("createDisplay");
    std::cout << "[+] Display engine changed" << std::endl;
}

void Core::ChangeGameModule(const std::string &name)
{
    // mActiveGame = 
    std::cout << "[+] Game changed to /'" << name << "/'" << std::endl;
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
            mGraphicLoader.emplace(m[1], DLLoader<ADisplayModule>(input));
            mActiveGraphic = mGraphicLoader.at(m[1]).getInstance("createDisplay");
            loadedLibraries.insert(m[1]);
            // mActiveGame menu
            std::cout << "[!] OK : " << m[1] << " as graphical library loaded" << std::endl;
        } else {
            throw std::runtime_error("Error: \'" + input + "\' not a graphical library");
        }
    } else {
        throw std::runtime_error("Error: \'" + input + "\' not a graphical library");
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
                    mGraphicLoader.emplace(m[1], DLLoader<ADisplayModule>("./libs/" + file));
                    std::cout << "  -> " << m[1] << " loaded" << std::endl;
                } else if (std::find(games_list.begin(), games_list.end(), m[1]) != games_list.end()) {
                    mAvailablesGames.push_back(m[1]);
                    mGamesLoader.emplace(m[1], DLLoader<ADisplayModule>("./libs/" + file));
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