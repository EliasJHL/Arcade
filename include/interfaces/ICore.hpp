/*
** ICore.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 16:25:22 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Apr 5 15:32:13 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ICORE_HPP_
# define ICORE_HPP_

#include <iostream>

class ICore {
    public:
        ~ICore() = default;
        virtual void LoadLibraries(int ac, char **av) = 0;  
        virtual void RunCore() = 0;
    protected:
        virtual void ChangeDisplayModule(const std::string &name) = 0;
        virtual void ChangeGameModule(const std::string &name) = 0;
        
        virtual void HandleEvents() = 0;
        virtual void DrawElements() = 0;
        virtual std::string NextGraphicalModule() = 0;
        virtual std::string NextGameModule() = 0;

        virtual void drawInteractiveMenu(std::vector<Rect> *rects, std::vector<Text> *texts) = 0;

        virtual void LoadFirstLibrary(const std::string &input) = 0;
        virtual void LoadAllLibraries(const std::string &input) = 0;
};

#endif /* !ICORE_HPP_ */
