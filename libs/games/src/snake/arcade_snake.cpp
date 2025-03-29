/*
** arcade_snake.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games/src/snake
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Thu Mar 27 03:15:44 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Mar 29 19:26:23 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_snake.hpp"

Snake::Snake(std::string name)
{
    _Direction = Move::NONE;
}

Snake::~Snake()
{
}

std::string Snake::getName() const
{
    return _name;
}

std::vector<Rect> Snake::getRects() const
{
    return _rects;
}

std::vector<Text> Snake::getTexts() const
{
    return _texts;
}

std::vector<Sprite> Snake::getSprites() const
{
    return _sprites;
}

void Snake::init()
{
    srand(time(0));
    _map.resize(30, std::vector<Type>(40, Type::VOID));
    for (int y = 0; y < 30; y++) {
        for (int x = 0; x < 40; x++) {
            _map[y][x] = Type::VOID;
        }
    }
    _x = 10;
    _y = 15;
    _map[_y][_x] = Type::HEAD;
    _map[25][35] = Type::APPLE;
    _GameOver = false;
    _GameOverScreen = false;
    score = 0;
}

void Snake::Reset()
{
    _GameOver = false;
    _map.clear();
    _snakebody.clear();
    _rects.clear();
    init();
}

void Snake::generateApple()
{
    int x =  rand() % 39;
    int y = 2 + (rand() % 25);
        
    while (_map[y][x] != Type::VOID) {
        x =  rand() % 39;
        y = 2 + (rand() % 25);
    }
    _map[y][x] = Type::APPLE;
}

void Snake::updateBody()
{
    int prev_x, prev_y, temp_x, temp_y = 0;
    
    if (_snakebody.empty())
        return;
        
    for (int i = 0; i < _snakebody.size(); i++) {
        _map[std::get<3>(_snakebody.at(i))][std::get<2>(_snakebody.at(i))] = Type::VOID;
    }
    for (int k = 0; k < _snakebody.size(); k++) {
    
        prev_x = std::get<2>(_snakebody.at(k));
        prev_y = std::get<3>(_snakebody.at(k));

        if (k == 0) {
            std::get<2>(_snakebody.at(k)) = std::get<0>(_snakebody.at(k));;
            std::get<3>(_snakebody.at(k)) = std::get<1>(_snakebody.at(k));;
            std::get<0>(_snakebody.at(k)) = _x;
            std::get<1>(_snakebody.at(k)) = _y;
        } else {
            temp_x = std::get<0>(_snakebody.at(k));
            temp_y = std::get<1>(_snakebody.at(k));
            
            std::get<0>(_snakebody.at(k)) = std::get<2>(_snakebody.at(k - 1));
            std::get<1>(_snakebody.at(k)) = std::get<3>(_snakebody.at(k - 1));
            std::get<2>(_snakebody.at(k)) = temp_x;
            std::get<3>(_snakebody.at(k)) = temp_y;
        }
        _map[std::get<1>(_snakebody.at(k))][std::get<0>(_snakebody.at(k))] = Type::BODY;
    }
}

void Snake::HandleActions(int new_x, int new_y)
{
    if (_map[new_y][new_x] == Type::APPLE) {
        _snakebody.push_back({0, 0, _x, _y});
        generateApple();
        score++;
    }
    if (_map[new_y][new_x] == Type::BODY)
        _GameOver = true;
    if (_y <= 2 && _Direction == Move::UP)
        new_y = 28;
    if (_y >= 28 && _Direction == Move::DOWN)
        new_y = 3;
    if (_x <= 0 && _Direction == Move::LEFT)
        new_x = 39;
    if (_x >= 39 && _Direction == Move::RIGHT)
        new_x = 0;
    _map[_y][_x] =  Type::VOID;
    updateBody();
    _y = new_y;
    _x = new_x;
    _map[_y][_x] =  Type::HEAD;
}

void Snake::HandleMovement() 
{
    if (_Direction == Move::UP) {
        HandleActions(_x, _y - 1);
    } else if (_Direction == Move::DOWN) {
        HandleActions(_x, _y + 1);
    } else if (_Direction == Move::LEFT) {
        HandleActions(_x - 1, _y);
    } else if (_Direction == Move::RIGHT) {
        HandleActions(_x + 1, _y);
    }
}

void Snake::DisplayMap()
{
    for (int y = 0; y < 30; y++) {
        for (int x = 0; x < 40; x++) {
            if (_map[y][x] == Type::APPLE) {
                _rects.push_back(Rect{x * 20, y * 20, 20, 20, Color{255, 0, 0, 255}});
            } else if (_map[y][x] == Type::HEAD) {
                _rects.push_back(Rect{x * 20, y * 20, 20, 20, Color{0, 255, 0, 255}});
            }
        }
    }
}

void Snake::DisplaySnake()
{
    for (int i = 0; i < _snakebody.size(); i++)
            _rects.push_back(Rect{std::get<0>(_snakebody.at(i)) * 20, std::get<1>(_snakebody.at(i)) * 20, 20, 20, Color{0, 200, 0, 255}});
}

void Snake::DisplayInfos()
{
    // Universel
    _rects.push_back(Rect{0, 0, 800, 40, Color{50, 50, 50, 255}});
    _rects.push_back(Rect{0, 580, 800, 20, Color{50, 50, 50, 255}});
    _texts.push_back(Text{320, 0, 50, "snake", "Snake Game", Color{0, 102, 51, 255}});
    _texts.push_back(Text{0, 580, 25, "basic", std::string("Score : " + std::to_string(score)), Color{255, 255, 255, 255}});
    _texts.push_back(Text{730, 580, 25, "basic", "Arcade", Color{255, 255, 255, 255}});
}

void Snake::update()
{
    _rects.clear();
    _texts.clear();
    if (!_GameOver) {
        HandleMovement();
        DisplayMap();
        DisplaySnake();
        DisplayInfos();
    } else {
        _texts.push_back(Text{300, 250, 50, "basic", "GAME OVER", Color{255,0,0,255}});
        _texts.push_back(Text{250, 300, 30, "basic", "Press any key to restart", Color{255,255,255,255}});
    }
}

void Snake::stop()
{
    _rects.clear();
    _sprites.clear();
}

Event Snake::handleEvent(Event event)
{
    bool ResetKeys = (event != Event::K_DOWN && event != Event::K_UP && event != Event::K_LEFT && event != Event::K_RIGHT);
    if (event != Event::NONE && ResetKeys && _GameOver)
        Reset();
    if (event == Event::K_UP && _Direction != Move::DOWN)
        _Direction = Move::UP;
    if (event == Event::K_DOWN && _Direction != Move::UP)
        _Direction = Move::DOWN;
    if (event == Event::K_LEFT && _Direction != Move::RIGHT)
        _Direction = Move::LEFT;
    if (event == Event::K_RIGHT && _Direction != Move::LEFT)
        _Direction = Move::RIGHT;
    return Event::NONE;
}

extern "C" {
    AGameModule *createGame() {
        return new Snake();
    }
}
