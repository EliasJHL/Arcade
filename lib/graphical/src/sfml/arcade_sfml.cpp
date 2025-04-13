/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
** File description:
** arcade_sfml
*/

#include "arcade_sfml.hpp"

Sfml::Sfml()
{
    mName = "sfml";
    mEvents = {
        {sf::Keyboard::Up, Event::K_UP}, {sf::Keyboard::Down, Event::K_DOWN}, {sf::Keyboard::Left, Event::K_LEFT},
        {sf::Keyboard::Right, Event::K_RIGHT}, {sf::Keyboard::Escape, Event::K_ESCAPE}, {sf::Keyboard::Return, Event::K_RETURN},
        {sf::Keyboard::Space, Event::K_SPACE}, {sf::Keyboard::F1, Event::K_F1}, {sf::Keyboard::A, Event::KEY_A},
        {sf::Keyboard::B, Event::KEY_B}, {sf::Keyboard::C, Event::KEY_C}, {sf::Keyboard::D, Event::KEY_D},
        {sf::Keyboard::E, Event::KEY_E}, {sf::Keyboard::F, Event::KEY_F}, {sf::Keyboard::G, Event::KEY_G},
        {sf::Keyboard::H, Event::KEY_H}, {sf::Keyboard::I, Event::KEY_I}, {sf::Keyboard::J, Event::KEY_J},
        {sf::Keyboard::K, Event::KEY_K}, {sf::Keyboard::L, Event::KEY_L}, {sf::Keyboard::M, Event::KEY_M},
        {sf::Keyboard::N, Event::KEY_N}, {sf::Keyboard::O, Event::KEY_O}, {sf::Keyboard::P, Event::KEY_P},
        {sf::Keyboard::Q, Event::KEY_Q}, {sf::Keyboard::R, Event::KEY_R}, {sf::Keyboard::S, Event::KEY_S},
        {sf::Keyboard::T, Event::NEXT_LIB}, {sf::Keyboard::U, Event::KEY_U}, {sf::Keyboard::V, Event::KEY_V},
        {sf::Keyboard::W, Event::KEY_W}, {sf::Keyboard::X, Event::KEY_X}, {sf::Keyboard::Y, Event::NEXT_GAME},
        {sf::Keyboard::Z, Event::KEY_Z}, {sf::Keyboard::Num1, Event::KEY_1}, {sf::Keyboard::Num2, Event::KEY_2},
        {sf::Keyboard::Num3, Event::KEY_3}, {sf::Keyboard::Num4, Event::KEY_4}, {sf::Keyboard::Num5, Event::KEY_5},
        {sf::Keyboard::Num6, Event::KEY_6}, {sf::Keyboard::Num7, Event::KEY_7}, {sf::Keyboard::Num8, Event::KEY_8},
        {sf::Keyboard::Num9, Event::KEY_9}, {sf::Keyboard::Num0, Event::KEY_0}
    };
}

Sfml::~Sfml()
{
    destroyWindow();
}

void Sfml::createWindow()
{
    mWindow.create(sf::VideoMode(800, 600), "Arcade");
    mWindow.setFramerateLimit(10);
}

void Sfml::destroyWindow()
{
}

void Sfml::display()
{
    mWindow.display();
}

void Sfml::clear()
{
    mWindow.clear(sf::Color::Black);
}

void Sfml::drawText(const Text &text)
{   
    sf::Text SfText;
    try {
        mFont.loadFromFile(text.getFont());
    } catch (const std::exception &e) {
        mFont.loadFromFile("./assets/basic.ttf");
    }
    SfText.setFont(mFont);
    SfText.setString(text.getText());
    SfText.setCharacterSize(text.getSize() - 1);
    SfText.setFillColor({(sf::Uint8)text.getColor().getR(), (sf::Uint8)text.getColor().getG(), (sf::Uint8)text.getColor().getB(), (sf::Uint8)text.getColor().getA()});
    SfText.setPosition({(float)text.getX(), (float)text.getY() - 7});
    mWindow.draw(SfText);
}

void Sfml::drawRect(const Rect &rect) { 
    sf::RectangleShape rec;
    
    rec.setSize({(float)rect.getWidth(), (float)rect.getHeight()});
    rec.setPosition({(float)rect.getX(), (float)rect.getY()});

    rec.setFillColor({(sf::Uint8)rect.getColor().getR(), (sf::Uint8)rect.getColor().getG(), (sf::Uint8)rect.getColor().getB(), (sf::Uint8)rect.getColor().getA()});
    
    mWindow.draw(rec);
}

std::vector<Event> Sfml::getEvents() {
    std::vector<Event> events;
    sf::Event sfEvent;

    while (mWindow.pollEvent(sfEvent)) {
        switch (sfEvent.type) {
            case sf::Event::Closed:
                events.push_back(Event::QUIT);
                return events;
            case sf::Event::KeyPressed:
                if (mEvents.find(sfEvent.key.code) != mEvents.end())
                    events.push_back(mEvents[sfEvent.key.code]);
                break;
            default:
                break;
        }
    }

    return events;
}

std::string Sfml::getName() const {
    return mName;
}

extern "C" {
    ADisplayModule *createDisplay() {
        return new Sfml();
    }
}
