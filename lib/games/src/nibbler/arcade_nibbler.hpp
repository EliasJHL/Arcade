/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
** File description:
** arcade_nibbler
*/

#ifndef ARCADE_Nibbler_HPP_
# define ARCADE_Nibbler_HPP_

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
    APPLE = 3,
    WALL = 4
};

class Nibbler : public AGameModule {
    public:
        Nibbler(std::string name = "nibbler");
        ~Nibbler();
        
        std::string getName() const override;
        std::vector<Rect> getRects() const override;
        std::vector<Text> getTexts() const override;
        
        void update() override;
        void init() override;
        void stop() override;

        // std::string saveState() override {};
        // void loadState(const std::string &state) override {};

        Event handleEvent(Event event) override;
    protected:
        void HandleMovement();
        void HandleActions(int x, int y);
        void generateApple();
        void updateBody();
        void Reset();
        void GameOver();
        void DisplayMap();
        void DisplayNibbler();
        void DisplayInfos();
        void Map(int nb);
        int _x;
        int _y;
        Move _Direction;
        bool _GameOver;
        bool _GameOverScreen;
        int score;
        int _NumMap;
        // x, y, prev_x, prev_y
        std::vector<std::tuple<int, int, int, int>> _Nibblerbody;
        std::vector<std::vector<Type>> _map;
};


#endif /* !ARCADE_Nibbler_HPP_ */
