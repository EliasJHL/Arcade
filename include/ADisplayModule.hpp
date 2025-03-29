/*
** ADisplayModule.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/include
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 10:08:50 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sat Mar 28 19:07:57 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ADISPLAYMODULE_HPP_
# define ADISPLAYMODULE_HPP_

#include "./interfaces/IDisplay.hpp"

class ADisplayModule : public IDisplayModule {
    public:
        ADisplayModule(std::string name = "") : _name(name) {};
        virtual ~ADisplayModule() = default;
        void createWindow() override = 0;
        void destroyWindow() override = 0;
        void display() override = 0;
        void clear() override = 0;
        void drawText(const Text &text) override = 0;
        void drawRect(const Rect &rect) override = 0;
        void drawSprite(const Sprite &sprite) override = 0;
        std::vector<Event> getEvents() override = 0;
        std::string getName() const override { return _name; };
    protected:
        std::string _name;
};

#endif /* !ADISPLAYMODULE_HPP_ */
