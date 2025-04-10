/**
 * @file ICore.hpp
 * @brief Interface pour la classe abstraite Core
 * @author Elias H. <elias-josue.hajjar-llauquen@epitech.eu> & Enzo C. <enzo.lobato-couthino@epitech.eu>
 *
 * Ce fichier définit l'interface utilisé dans la class abstraite Core
 *
 */

#ifndef ICORE_HPP_
# define ICORE_HPP_

#include <iostream>

/**
 * @class ICore
 * @brief Interface pour le Core
 *
 * Utilisé pour la gestion des libraries, des events et de l'orchestration du Jeu et du Graphique dans le projet Arcade.
 */
class ICore {
    public:
        ~ICore() = default;

        /**
        * @brief Initialise les libraries
        * @param ac Nombre d'arguments
        * @param av Tableau des arguments
        */
        virtual void LoadLibraries(int ac, char **av) = 0;

        /**
        * @brief Lance les modules graphiques et le menu lorsque tout a été correctement initialisé
        */ 
        virtual void RunCore() = 0;
    protected:
        /**
        * @brief Initialise le module de jeu.
        * @param name Nom du module graphique souhaité
        */
        virtual void ChangeDisplayModule(const std::string &name) = 0;

        /**
        * @brief Initialise le module de jeu.
        * @param name Nom du jeu souhaité
        */
        virtual void ChangeGameModule(const std::string &name) = 0;
        
        /**
        * @brief Gestion & Envoi des events récuperés du module graphique au jeu
        */
        virtual void HandleEvents() = 0;

        /**
        * @brief Affichage des elements graphiques sur le module graphique
        */
        virtual void DrawElements() = 0;

        /**
        * @brief Permet d'ouvrir le prochain module graphique
        * @return Renvoie le nom du prochain module graphique de la liste des modules graphiques disponibles
        */
        virtual std::string NextGraphicalModule() = 0;

        /**
        * @brief Permet d'ouvrir le prochain module graphique
        * @return Renvoie le nom du prochain jeu de la liste des jeux disponibles
        */
        virtual std::string NextGameModule() = 0;

        /**
        * @brief Permet de charger la librarie graphique donnée en argument lors du lancement de l'Arcade
        */
        virtual void LoadFirstLibrary(const std::string &input) = 0;
        /**
        * @brief Permet de récuperer la liste des libraries disponibles dans le dossier ./lib/
        */
        virtual void LoadAllLibraries(const std::string &input) = 0;
};

#endif /* !ICORE_HPP_ */
