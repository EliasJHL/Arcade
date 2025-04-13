/**
 * @file Text.hpp
 * @brief Fichier d'en-tête pour la classe Text
 * @author Elias H.
 *
 * Ce fichier définit la classe Text, qui représente un élément de texte avec
 * des propriétés telles que la position, la taille, la police, le contenu,
 * l'alignement et la couleur.
 */

#ifndef TEXT_HPP_
# define TEXT_HPP_

#include "Color.hpp"
#include <string>

class Text {
    public:
        Text(int x, int y, int size, const std::string &font, const std::string &text, bool centeredX, bool centeredY, Color color);
        ~Text();

        int getX() const;
        int getY() const;
        int getSize() const;
        std::string getFont() const;
        std::string getText() const;
        Color getColor() const;
        bool isCenteredX() const;
        bool isCenteredY() const;

    private:
        int _x;
        int _y;
        bool _centeredX;
        bool _centeredY;
        int _size;
        std::string _font;
        std::string _text;
        Color _color;
};

#endif /* !TEXT_HPP_ */