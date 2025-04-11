/**
 * @file Rect.hpp
 * @brief Classe pour contenir les informations d'un rectangle
 * @author Elias H. <elias-josue.hajjar-llauquen@epitech.eu> & Enzo C. <enzo.lobato-couthino@epitech.eu>
 *
 * Classe utilisé pour contenir toutes les informations nécessaires à la création d'un réctangle
 *
 */

#ifndef RECT_HPP_
# define RECT_HPP_

#include "Color.hpp"
#include <string>

/**
 * @class Rect
 * @brief Information pour créer un rectangle
 *
 * Utilisé pour la création de rectangles dans les libraries graphiques
 */
class Rect {
    public:
        /**
        * @brief Constructeur de la class Rect
        * @param x Position x sur la fenêtre de la librarie graphique
        * @param y Position y sur la fenêtre de la librarie graphique
        * @param width La longeur du rectangle
        * @param height La largeur du rectangle
        * @param color Contient la couleur & opacité souhaité
        * @param path Chemin vers un sprite - Optionnel - Par défaut : ""
        */ 
        Rect(int x, int y, int width, int height, Color color, std::string path);
        ~Rect();

        /**
        * @brief Renvoie la position X
        * @return renvoie position X
        */ 
        int getX() const;

        /**
        * @brief Renvoie la position Y
        * @return renvoie position Y
        */ 
        int getY() const;

        /**
        * @brief Renvoie la position longeur
        * @return renvoie position longeur
        */ 
        int getWidth() const;

        /**
        * @brief Renvoie la position largeur
        * @return renvoie position largeur
        */ 
        int getHeight() const;

        /**
        * @brief Renvoie la couleur
        * @return Class Color - Renvoie la couleur
        */ 
        Color getColor() const;

        /**
        * @brief Renvoie le chemin vers le sprite 
        * @return renvoie le chemin du sprite 
        * Optionnel
        */ 
        const std::string &getSpritePath() const;
    private:
        int _x;
        int _y;
        int _width;
        int _height;
        Color _color;
        std::string _spritePath;
};

#endif /* !RECT_HPP_ */
