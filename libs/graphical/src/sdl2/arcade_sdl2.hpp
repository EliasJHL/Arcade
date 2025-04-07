/*
** arcade_sdl2.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/sdl2
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:37:22 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Apr 5 15:41:49 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ARCADE_SDL2_HPP_
# define ARCADE_SDL2_HPP_

#include "ADisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

class Sdl2 : public ADisplayModule{
    public:
        Sdl2();
        ~Sdl2();
        void createWindow() override;
        void destroyWindow() override;
        void display() override;
        void clear() override;
        void drawText(const Text &text) override;
        void drawRect(const Rect &rect) override;
        std::vector<Event> getEvents() override;
        std::string getName() const override;
    private:
        std::string mName;
        SDL_Window *mWindow;
        TTF_Font *mFont;
        SDL_Surface *mWindowSurface;
        SDL_Renderer *mWindowRender;
};;

#endif /* !ARCADE_SDL2_HPP_ */
