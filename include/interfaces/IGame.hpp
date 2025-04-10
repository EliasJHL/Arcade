/**
 * @file IGame.hpp
 * @brief Interface pour la classe abstraite AGameModule
 * @author Elias H. <elias-josue.hajjar-llauquen@epitech.eu> & Enzo C. <enzo.lobato-couthino@epitech.eu>
 *
 * Ce fichier définit l'interface utilisé dans la classe abstraite AGameModule
 *
 */

#ifndef IGAME_HPP_
# define IGAME_HPP_

#include <iostream>
#include "IDisplay.hpp"
#include "../Rect.hpp"
#include "../Text.hpp"
#include <vector>
#include <functional>
#include <cstdlib>

/**
 * @class IGameModule
 * @brief Interface pour AGameModule
 *
 * Utilisé pour l'ouverture / gestion / utilisation des Jeux.
 */
class IGameModule {
    public:
        virtual ~IGameModule() = default;

        /**
        * @brief Permet de récupérer le nom du jeu
        */ 
        virtual std::string getName() const = 0;

        /**
        * @brief Permet d'appeller l'action suivante après l'affichage
        */ 
        virtual void update() = 0;

        /**
        * @brief Permet d'initialiser tous les éléments nécessaires au jeu
        */ 
        virtual void init() = 0;

        /**
        * @brief Arrête le jeu
        */ 
        virtual void stop() = 0;

        /**
        * @brief Permet de récupérer tous les rectangles que le jeu veut render
        * @return Un vector contenant tous les formes à afficher
        */ 
        virtual std::vector<Rect> getRects() const = 0;

        /**
        * @brief Permet de récupérer tous les textes que le jeu veut render
        * @return Un vector contenant tous les textes à afficher
        */ 
        virtual std::vector<Text> getTexts() const = 0;

        /**
        * @brief Permet de gérer les events capturés par la librarie graphique et d'appliquer une action sur le jeu
        * @param L'event qui s'est déroulé dans la librarie graphique
        */ 
        virtual Event handleEvent(Event event) = 0;

        /**
        * @brief Permet de selectionner un jeu précis dans le menu
        * @param Un callback sur la fonction du Core qui permet de changer de jeu
        * Uniquement utilisé dans le Menu
        */ 
        virtual void setGameSwitchCallback(std::function<void(std::string)> callback) = 0;

        /**
        * @brief Permet de selectionner une librarie graphique précise dans le menu
        * @param Un callback sur la fonction du Core qui permet de changer de librarie graphique
        * Uniquement utilisé dans le Menu
        */ 
        virtual void setGraphicSwitchCallback(std::function<void(std::string)> callback) = 0;

         /**
        * @brief Permet de selectionner . . .
        * @param Un callback sur la fonction du Core qui permet de . . .
        * Non Utilisé
        */ 
        virtual void setLibSwitchCallback(std::function<void()> callback) = 0;

        /**
        * @brief Permet de gérer les events génériques comme le changement de jeu
        * @param L'event déroulé dans la librarie graphique
        * Non Utilisé
        */ 
        virtual Event handleEventGeneric(Event event) = 0;
};

#endif /* !IGAME_HPP_ */
