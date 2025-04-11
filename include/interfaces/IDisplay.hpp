/**
 * @file IDisplay.hpp
 * @brief Interface pour la classe abstraite ADisplayModule
 * @author Elias H. <elias-josue.hajjar-llauquen@epitech.eu> & Enzo C. <enzo.lobato-couthino@epitech.eu>
 *
 * Ce fichier définit l'interface utilisé dans la class abstraite ADisplayModule
 *
 */

#ifndef IDISPLAY_HPP_
# define IDISPLAY_HPP_

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Rect.hpp"
#include "Text.hpp"
#include "../EventEnum.hpp"

/**
 * @class IDisplayModule
 * @brief Interface pour ADisplayModule
 *
 * Utilisé pour l'ouverture / gestion / utilisation des libraries graphiques.
 */
class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        /**
        * @brief Appelle la création de la fenêtre de la librarie graphique
        */ 
        virtual void createWindow() = 0;

        /**
        * @brief Appelle la destruction de la fenêtre de la librarie graphique
        */ 
        virtual void destroyWindow() = 0;

        /**
        * @brief Permet de récupérer le nom de la librarie graphique
        */ 
        virtual std::string getName() const = 0;

        /**
        * @brief Appelle l'affichage de tous les éléments dessinés auparavant
        */ 
        virtual void display() = 0;

        /**
        * @brief Appelle le clear de la librarie graphique en question
        */ 
        virtual void clear() = 0;

        /**
        * @brief Permet de dessiner un texte sur le librarie graphique pour l'afficher
        * @param text Class Text contenant tous les éléments nécessaire à l'affichage d'un texte
        */ 
        virtual void drawText(const Text &text) = 0;

        /**
        * @brief Permet de dessiner un rectangle sur le librarie graphique pour l'afficher
        * @param text Class Rect contenant tous les éléments nécessaire à l'affichage d'un rectangle
        */ 
        virtual void drawRect(const Rect &rect) = 0;

        /**
        * @brief Permet de récupérer tous les events
        * @return Renvoie un vector contenant toutes les actions que la librarie graphique a capturé
        */ 
        virtual std::vector<Event> getEvents() = 0;
};
#endif /* !IDISPLAY_HPP_ */
