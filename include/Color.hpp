/*
** Color.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 10:02:14 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Apr 5 15:33:15 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef COLOR_HPP_
# define COLOR_HPP_

class Color {
    public:
        Color(int r, int g, int b, int a);
        Color();
        ~Color();

        int getR() const;
        int getG() const;
        int getB() const;
        int getA() const;

    private:
        int _r;
        int _g;
        int _b;
        int _a;
};

#endif /* !COLOR_HPP_ */
