/**
 * @file Color.hpp
 * @brief Classe pour contenir une couleur
 * @author Elias H. <elias-josue.hajjar-llauquen@epitech.eu> & Enzo C. <enzo.lobato-couthino@epitech.eu>
 *
 * Classe utilisé pour créer une couleur
 *
 */

#ifndef COLOR_HPP_
# define COLOR_HPP_

/**
 * @class Color
 * @brief Informations pour créer une couleur
 *
 * Utilisé pour définir la couleur d'un rectangle ou texte
 */
class Color {
    public:
        /**
        * @brief Constructeur de la class Color
        * @param r Rouge 0-255
        * @param g Vert 0-255
        * @param b Bleu 0-255
        * @param a Alpha 0-255
        */ 
        Color(int r, int g, int b, int a);

        /**
        * @brief Constructeur de la class Color - Couleur par défaut : Blanc
        */ 
        Color();

        ~Color();

        /**
        * @brief Renvoie la quantité de rouge
        * @return renvoie rouge 0-255
        */ 
        int getR() const;

        /**
        * @brief Renvoie la quantité de vert
        * @return renvoie vert 0-255
        */ 
        int getG() const;

        /**
        * @brief Renvoie la quantité de bleu
        * @return renvoie bleu 0-255
        */ 
        int getB() const;

        /**
        * @brief Renvoie l'opacité
        * @return renvoie l'opacité 0-255
        */ 
        int getA() const;

    private:
        int _r;
        int _g;
        int _b;
        int _a;
};

#endif /* !COLOR_HPP_ */
