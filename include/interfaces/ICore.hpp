/*
** ICore.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 16:25:22 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 18:27:06 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ICORE_HPP_
# define ICORE_HPP_

#include <iostream>

class ICore {
    public:
        ~ICore() = default;
        virtual void ChangeDisplayModule(const std::string &path) = 0;
        virtual void ChangeGameModule(const std::string &path) = 0;

        virtual void RunCore() = 0;

        virtual void LoadLibraries(int ac, char **av) = 0;        
};

#endif /* !ICORE_HPP_ */
