/*
** main.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/src
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Thu Mar 20 15:41:14 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 19:51:43 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    Core arcade_core;

    try {
        arcade_core.LoadLibraries(ac, av);
        arcade_core.ChangeDisplayModule(std::string("sfml"));
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}