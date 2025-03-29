/*
** arcade_Xlib.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/Xlib
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:39:09 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Mar 29 22:30:32 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ARCADE_Xlib_HPP_
# define ARCADE_Xlib_HPP_

#include "ADisplayModule.hpp"
#include <X11/Xlib.h>

class Xlib : public ADisplayModule {
    public:
        Xlib();
        ~Xlib();
        void createWindow() override;
        void destroyWindow() override;
        void display() override;
        void clear() override;
        void drawText(const Text &text) override;
        void drawRect(const Rect &rect) override;
        void drawSprite(const Sprite &sprite) override {};
        std::vector<Event> getEvents() override;
        std::string getName() const override;
    private:
        std::string mName;
        Display *mDisplay;
        Window mWindow;
};

#endif /* !ARCADE_Xlib_HPP_ */
