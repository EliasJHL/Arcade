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
    SfText.setFillColor({text.getColor().getR(), text.getColor().getG(), text.getColor().getB(), text.getColor().getA()});
    SfText.setPosition({text.getX(), text.getY() - 7});
    mWindow.draw(SfText);
}

void Sfml::drawRect(const Rect &rect) { 
    sf::RectangleShape rec;
    
    rec.setSize({rect.getWidth(), rect.getHeight()});
    rec.setPosition({rect.getX(), rect.getY()});

    rec.setFillColor({rect.getColor().getR(), rect.getColor().getG(), rect.getColor().getB(), rect.getColor().getA()});
    
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
                switch (sfEvent.key.code) {
                    case sf::Keyboard::Up:
                        events.push_back(Event::K_UP);
                        break;
                    case sf::Keyboard::Down:
                        events.push_back(Event::K_DOWN);
                        break;
                    case sf::Keyboard::Left:
                        events.push_back(Event::K_LEFT);
                        break;
                    case sf::Keyboard::Right:
                        events.push_back(Event::K_RIGHT);
                        break;
                    case sf::Keyboard::Escape:
                        events.push_back(Event::K_ESCAPE);
                        break;
                    case sf::Keyboard::Enter:
                        events.push_back(Event::K_RETURN);
                        break;
                    case sf::Keyboard::Space:
                        events.push_back(Event::K_SPACE);
                        break;
                    case sf::Keyboard::A:
                        events.push_back(Event::KEY_A);
                        break;
                    case sf::Keyboard::B:
                        events.push_back(Event::KEY_B);
                        break;
                    case sf::Keyboard::C:
                        events.push_back(Event::KEY_C);
                        break;
                    case sf::Keyboard::D:
                        events.push_back(Event::KEY_D);
                        break;
                    case sf::Keyboard::E:
                        events.push_back(Event::KEY_E);
                        break;
                    case sf::Keyboard::F:
                        events.push_back(Event::KEY_F);
                        break;
                    case sf::Keyboard::G:
                        events.push_back(Event::KEY_G);
                        break;
                    case sf::Keyboard::H:
                        events.push_back(Event::KEY_H);
                        break;
                    case sf::Keyboard::I:
                        events.push_back(Event::KEY_I);
                        break;
                    case sf::Keyboard::J:
                        events.push_back(Event::KEY_J);
                        break;
                    case sf::Keyboard::K:
                        events.push_back(Event::KEY_K);
                        break;
                    case sf::Keyboard::L:
                        events.push_back(Event::KEY_L);
                        break;
                    case sf::Keyboard::M:
                        events.push_back(Event::KEY_M);
                        break;
                    case sf::Keyboard::N:
                        events.push_back(Event::KEY_N);
                        break;
                    case sf::Keyboard::O:
                        events.push_back(Event::KEY_O);
                        break;
                    case sf::Keyboard::P:
                        events.push_back(Event::KEY_P);
                        break;
                    case sf::Keyboard::Q:
                        events.push_back(Event::KEY_Q);
                        break;
                    case sf::Keyboard::R:
                        events.push_back(Event::KEY_R);
                        break;
                    case sf::Keyboard::S:
                        events.push_back(Event::KEY_S);
                        break;
                    case sf::Keyboard::T:
                        events.push_back(Event::NEXT_LIB);
                        break;
                    case sf::Keyboard::U:
                        events.push_back(Event::KEY_U);
                        break;
                    case sf::Keyboard::V:
                        events.push_back(Event::KEY_V);
                        break;
                    case sf::Keyboard::W:
                        events.push_back(Event::KEY_W);
                        break;
                    case sf::Keyboard::X:
                        events.push_back(Event::KEY_X);
                        break;
                    case sf::Keyboard::Y:
                        events.push_back(Event::NEXT_GAME);
                        break;
                    case sf::Keyboard::Z:
                        events.push_back(Event::KEY_Z);
                        break;
                    case sf::Keyboard::Num1:
                        events.push_back(Event::KEY_1);
                        break;
                    case sf::Keyboard::Num2:
                        events.push_back(Event::KEY_2);
                        break;
                    case sf::Keyboard::Num3:
                        events.push_back(Event::KEY_3);
                        break;
                    case sf::Keyboard::Num4:
                        events.push_back(Event::KEY_4);
                        break;
                    case sf::Keyboard::Num5:
                        events.push_back(Event::KEY_5);
                        break;
                    case sf::Keyboard::Num6:
                        events.push_back(Event::KEY_6);
                        break;
                    case sf::Keyboard::Num7:
                        events.push_back(Event::KEY_7);
                        break;
                    case sf::Keyboard::Num8:
                        events.push_back(Event::KEY_8);
                        break;
                    case sf::Keyboard::Num9:
                        events.push_back(Event::KEY_9);
                        break;
                    case sf::Keyboard::Num0:
                        events.push_back(Event::KEY_0);
                        break;
                    default:
                        break;
                }
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
