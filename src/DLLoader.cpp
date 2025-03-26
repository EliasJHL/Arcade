/*
** DLLoader.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/src
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 15:30:02 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 19:47:26 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "DLLoader.hpp"

template <typename T>
DLLoader<T>::DLLoader(const std::string &path) {
    handler = dlopen(path.c_str(), RTLD_LAZY);
        
    if (handler == nullptr)
        throw std::runtime_error(dlerror());
}
template <typename T>
DLLoader<T>::~DLLoader() {
    if (handler)
        dlclose(handler);
}

template <typename T>
T *DLLoader<T>::getInstance(const std::string &symbol) const {
    void *ptr = dlsym(handler, symbol.c_str());

    if (ptr == nullptr)
        throw std::runtime_error(dlerror());
    std::function<T *(void)> symFcn = reinterpret_cast<T *(*)()>(ptr);
    return symFcn();
}
