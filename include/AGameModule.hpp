/*
** AGameModule.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 10:05:12 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Mar 29 01:19:00 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef AGAMEMODULE_HPP_
# define AGAMEMODULE_HPP_

#include "./interfaces/IGame.hpp"

class AGameModule : public IGameModule {
    public:
        AGameModule(std::string name = "") : _name(name) {};
        virtual ~AGameModule() = default;
        std::string getName() const override { return _name; };
        void update() override = 0;
        void init() override = 0;
        void stop() override = 0;
        std::vector<Rect> getRects() const override { return _rects; };
        std::vector<Text> getTexts() const override { return _texts; };
        std::vector<Sprite> getSprites() const override {return _sprites;};
        Event handleEvent(Event event) override = 0;
        
        void setGameSwitchCallback(std::function<void(std::string)> callback) override {
            _gameSwitchCallback = callback;
        };
        void setLibSwitchCallback(std::function<void()> callback) override {
            _libSwitchCallback = callback;
        };

        Event handleEventGeneric(Event event) override {
            if (event == Event::K_ESCAPE || event == Event::QUIT)
                return Event::QUIT;
            if (event == Event::NEXT_LIB) {
                switchToNextLib();
            }
            if (event == Event::NEXT_GAME) {
                switchToNextGame();
            }
            return Event::NONE;
        }

    protected:
        std::string _name;
        std::vector<Rect> _rects;
        std::vector<Text> _texts;
        std::vector<Sprite> _sprites;
        std::function<void(std::string)> _gameSwitchCallback;
        std::function<void()> _libSwitchCallback;

        void switchToNextGame(const std::string& gameName = "") {
            if (_gameSwitchCallback) {
                _gameSwitchCallback(gameName);
            }
        }
        void switchToNextLib() {
            if (_libSwitchCallback) {
                _libSwitchCallback();
            }
        }
};

#endif /* !AGAMEMODULE_HPP_ */
