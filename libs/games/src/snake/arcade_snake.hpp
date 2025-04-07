/*
** arcade_snake.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games/src/snake
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Thu Mar 27 03:16:09 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Apr 5 16:03:27 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ARCADE_SNAKE_HPP_
# define ARCADE_SNAKE_HPP_

#include "AGameModule.hpp"
#include <thread>

enum Move {
    NONE = -1,
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

enum Type {
    VOID = 0,
    HEAD = 1,
    BODY = 2,
    APPLE = 3
};

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
        void HandleMovement();
        void HandleActions(int x, int y);
        void generateApple();
        void updateBody();
        void Reset();
        void GameOver();
        void DisplayMap();
        void DisplaySnake();
        void DisplayInfos();
        int _x;
        int _y;
        Move _Direction;
        bool _GameOver;
        bool _GameOverScreen;
        int score;
        // x, y, prev_x, prev_y
        std::vector<std::tuple<int, int, int, int>> _snakebody;
        std::vector<std::vector<Type>> _map;
};


#endif /* !ARCADE_SNAKE_HPP_ */
