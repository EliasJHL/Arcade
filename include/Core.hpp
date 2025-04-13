/**
 * @file DLLoader.hpp
 * @brief Template pour le DLLoader
 * @author Elias H. <elias-josue.hajjar-llauquen@epitech.eu> & Enzo C. <enzo.lobato-couthino@epitech.eu>
 *
 * Ce fichier définit le template pour le DLLoader.
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

        /**
        * @brief Lance la boucle entre le jeu et le graphique
        */ 
        void RunCore() override;

        /**
        * @brief Load les libraries
        */ 
        void LoadLibraries(int ac, char **av) override;
    protected:
        /**
        * @brief Charge une nouvelle lib graphique
        * @param name nom du module graphique
        */ 
        void ChangeDisplayModule(const std::string &name) override;

        /**
        * @brief Charge un nouveau jeu
        * @param name nom du jeu
        */
        void ChangeGameModule(const std::string &name) override;
        
        /**
        * @brief Géstion des events
        */
        void HandleEvents() override;

        /**
        * @brief Appelle l'affichage de tout au graphique
        */
        void DrawElements() override;

        /**
        * @brief renvoie le module graphique suivant
        * @return renvoie le nom du prochain module graphique
        */
        std::string NextGraphicalModule() override;

        /**
        * @brief renvoie le module jeu
        * @return renvoie le nom du prochain jeu
        */
        std::string NextGameModule() override;

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
