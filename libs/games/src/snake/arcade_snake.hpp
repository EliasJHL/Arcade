/*
** arcade_snake.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games/src/snake
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Thu Mar 27 03:16:09 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 10:49:49 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ARCADE_SNAKE_HPP_
# define ARCADE_SNAKE_HPP_

#include "AGameModule.hpp"

class Snake : public AGameModule {
    public:
        Snake(std::string name = "snake");
        ~Snake();
        
        std::string getName() const override;
        std::vector<Rect> getRects() const override;
        std::vector<Text> getTexts() const override;
        
        void update() override;
        void init() override;
        void stop() override;

        Event handleEvent(Event event) override;
    protected:
        std::string _name;
        std::vector<Rect> _rects;
        std::vector<Text> _texts;
        Rect _Player;
};


#endif /* !ARCADE_SNAKE_HPP_ */
