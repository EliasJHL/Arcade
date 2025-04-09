/*
** Core.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 16:31:39 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Mon Mar 30 19:17:49 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef CORE_HPP_
# define CORE_HPP_

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include "interfaces/IDisplay.hpp"
#include "interfaces/ICore.hpp"
#include "interfaces/IGame.hpp"
#include "ADisplayModule.hpp"
#include "AGameModule.hpp"
#include "DLLoader.hpp"
#include <set>

class Core : public ICore{
    public:
        Core();
        ~Core();
        void RunCore() override;
        void LoadLibraries(int ac, char **av) override;
    protected:
        void ChangeDisplayModule(const std::string &name) override;
        void ChangeGameModule(const std::string &name) override;
        
        void HandleEvents() override;
        void DrawElements() override;
        std::string NextGraphicalModule() override;
        std::string NextGameModule() override;

        void drawInteractiveMenu(std::vector<Rect> *rects, std::vector<Text> *texts) override;

        void LoadFirstLibrary(const std::string &input) override;
        void LoadAllLibraries(const std::string &input) override;
    private:
        std::vector<std::string> mAvailablesGames;
        std::vector<std::string> mAvailablesGraphics;
        std::set<std::string> mLoadedLibraries;
        std::map<std::string, std::unique_ptr<DLLoader<ADisplayModule>>> mGraphicLoader;
        std::map<std::string, std::unique_ptr<DLLoader<AGameModule>>> mGamesLoader;
        std::unique_ptr<ADisplayModule> mActiveGraphic;
        std::unique_ptr<AGameModule> mActiveGame;
};

#endif /* !CORE_HPP_ */
