/*
** Core.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 16:31:39 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Thu Mar 26 19:44:44 2025 Elias Josué HAJJAR LLAUQUEN
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

class Core : public ICore{
    public:
        Core();
        ~Core();
        void ChangeDisplayModule(const std::string &name) override;
        void ChangeGameModule(const std::string &name) override;
        
        void RunCore() override {};
        void LoadLibraries(int ac, char **av) override;
    private:
        // std::unique_ptr<IDisplayModule> mDisplayModule;
        // std::unique_ptr<IGameModule> mGameModule;
        std::vector<std::string> mAvailablesGames;
        std::vector<std::string> mAvailablesGraphics;
        std::map<std::string, DLLoader<ADisplayModule>> mGraphicLoader;
        std::map<std::string, DLLoader<ADisplayModule>> mGamesLoader;
        ADisplayModule *mActiveGraphic;
        AGameModule *mActiveGame;
};

#endif /* !CORE_HPP_ */
