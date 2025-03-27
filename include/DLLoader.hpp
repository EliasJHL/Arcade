/*
** DLLoader.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 15:19:23 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 21:15:46 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef DLLOADER_HPP_
# define DLLOADER_HPP_

#include <dlfcn.h>
#include <exception>
#include <filesystem>
#include <functional>
#include <iostream>

template <typename T>
class DLLoader {
    public:
        DLLoader(const std::string &path);
        ~DLLoader();
        T *getInstance (const std::string &symbol) const;
    private:
        void *handler;
};
#endif /* !DLLOADER_HPP_ */
