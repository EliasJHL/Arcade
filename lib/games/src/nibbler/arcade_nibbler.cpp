/*
** arcade_Nibbler.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games/src/Nibbler
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Thu Mar 27 03:15:44 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Apr 5 21:11:38 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_nibbler.hpp"

Nibbler::Nibbler(std::string name)
{
    _name = name;
    _Direction = Move::NONE;
    _NumMap = 1;
}

Nibbler::~Nibbler()
{
}

std::string Nibbler::getName() const
{
    return _name;
}

std::vector<Rect> Nibbler::getRects() const
{
    return _rects;
}

std::vector<Text> Nibbler::getTexts() const
{
    return _texts;
}

void Nibbler::addWall(int sX, int eX, int sY, int eY)
{
    for (int y = sY; y < eY; y++) {
        for (int x = sX; x < eX; x++) {
            _map[y][x] = Type::WALL;
        }
    }
}

void Nibbler::parseMap(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    for (int y = 0; y < 15 && y + 7 < 30; y++) {
        for (int x = 0; x < 15 && x + 12 < 40; x++) {
            if (lines[y][x] == '#') {
                _map[y + 7][x + 12] = Type::WALL;
            }
        }
    }
}

void Nibbler::Map(int nb)
{
    if (nb == 1) {
        parseMap("lib/games/src/nibbler/map_1");
    }
}

void Nibbler::init()
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
    _Nibblerbody.push_back({_x - 1, _y, _x - 1, _y});
    _Nibblerbody.push_back({_x - 2, _y, _x - 2, _y});
    _Nibblerbody.push_back({_x - 3, _y, _x - 3, _y});
    _map[_y][_x - 1] = Type::BODY;
    _map[_y][_x - 2] = Type::BODY;
    _map[_y][_x - 3] = Type::BODY;

    _map[25][35] = Type::APPLE;
    Map(_NumMap);
    _GameOver = false;
    _GameOverScreen = false;
    score = 0;
}

// std::string Nibbler::saveState()
// {
    
// }

void Nibbler::Reset()
{
    _GameOver = false;
    _Direction = NONE;
    _map.clear();
    _Nibblerbody.clear();
    _rects.clear();
    init();
}

void Nibbler::generateApple()
{
    int x =  rand() % 39;
    int y = 2 + (rand() % 25);
        
    while (_map[y][x] != Type::VOID) {
        x =  rand() % 39;
        y = 2 + (rand() % 25);
    }
    _map[y][x] = Type::APPLE;
}

void Nibbler::updateBody()
{
    int prev_x, prev_y, temp_x, temp_y = 0;
    
    if (_Nibblerbody.empty())
        return;
        
    for (int i = 0; i < _Nibblerbody.size(); i++) {
        _map[std::get<3>(_Nibblerbody.at(i))][std::get<2>(_Nibblerbody.at(i))] = Type::VOID;
    }
    for (int k = 0; k < _Nibblerbody.size(); k++) {
    
        prev_x = std::get<2>(_Nibblerbody.at(k));
        prev_y = std::get<3>(_Nibblerbody.at(k));

        if (k == 0) {
            std::get<2>(_Nibblerbody.at(k)) = std::get<0>(_Nibblerbody.at(k));;
            std::get<3>(_Nibblerbody.at(k)) = std::get<1>(_Nibblerbody.at(k));;
            std::get<0>(_Nibblerbody.at(k)) = _x;
            std::get<1>(_Nibblerbody.at(k)) = _y;
        } else {
            temp_x = std::get<0>(_Nibblerbody.at(k));
            temp_y = std::get<1>(_Nibblerbody.at(k));
            
            std::get<0>(_Nibblerbody.at(k)) = std::get<2>(_Nibblerbody.at(k - 1));
            std::get<1>(_Nibblerbody.at(k)) = std::get<3>(_Nibblerbody.at(k - 1));
            std::get<2>(_Nibblerbody.at(k)) = temp_x;
            std::get<3>(_Nibblerbody.at(k)) = temp_y;
        }
        _map[std::get<1>(_Nibblerbody.at(k))][std::get<0>(_Nibblerbody.at(k))] = Type::BODY;
    }
}

void Nibbler::HandleActions(int new_x, int new_y)
{
    if (_map[new_y][new_x] == Type::APPLE) {
        _Nibblerbody.push_back({0, 0, _x, _y});
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

void Nibbler::HandleMovement() 
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

void Nibbler::DisplayMap()
{
    for (int y = 0; y < 30; y++) {
        for (int x = 0; x < 40; x++) {
            if (_map[y][x] == Type::APPLE) {
                _rects.push_back(Rect{x * 20, y * 20, 20, 20, Color{255, 255, 255, 255}, ""});
            } else if (_map[y][x] == Type::HEAD) {
                _rects.push_back(Rect{x * 20, y * 20, 20, 20, Color{255, 0, 0, 255}, ""});
            } else if (_map[y][x] == Type::WALL) {
                _rects.push_back(Rect{x * 20, y * 20, 20, 20, Color{255, 255, 255, 255}, ""});
            }
        }
    }
}

void Nibbler::DisplayNibbler()
{
    for (int i = 0; i < _Nibblerbody.size(); i++)
        _rects.push_back(Rect{std::get<0>(_Nibblerbody.at(i)) * 20, std::get<1>(_Nibblerbody.at(i)) * 20, 20, 20, Color{200, 0, 0, 255}, ""});
}

void Nibbler::DisplayInfos()
{
    // Universel
    _rects.push_back(Rect{0, 0, 800, 40, Color{50, 50, 50, 255}, ""});
    _rects.push_back(Rect{0, 580, 800, 20, Color{50, 50, 50, 255}, ""});
    _texts.push_back(Text{320, 0, 50, "assets/basic.ttf", "Nibbler Game", Color{0, 102, 51, 255}});
    _texts.push_back(Text{0, 580, 25, "assets/basic.ttf", std::string("Score : " + std::to_string(score)), Color{255, 255, 255, 255}});
    _texts.push_back(Text{730, 580, 25, "assets/basic.ttf", "Arcade", Color{255, 255, 255, 255}});
}

void Nibbler::update()
{
    _rects.clear();
    _texts.clear();
    if (!_GameOver) {
        HandleMovement();
        DisplayMap();
        DisplayNibbler();
        DisplayInfos();
    } else {
        _texts.push_back(Text{300, 250, 50, "assets/basic.ttf", "GAME OVER", Color{255,0,0,255}});
        _texts.push_back(Text{250, 300, 30, "assets/basic.ttf", "Press any key to restart", Color{255,255,255,255}});
    }
}

void Nibbler::stop()
{
    _rects.clear();
}

Event Nibbler::handleEvent(Event event)
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
        return new Nibbler();
    }
}
