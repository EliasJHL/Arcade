/*
** arcade_sdl2.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/sdl2
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Fri Mar 21 16:37:50 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Fri Mar 27 03:08:31 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_sdl2.hpp"

Sdl2::Sdl2() : mWindow(nullptr), mWindowRender(nullptr), mFont(nullptr)
{
    mName = "sdl2";
}

Sdl2::~Sdl2()
{
    destroyWindow();
}

void Sdl2::createWindow()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    mWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    mWindowRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
}

void Sdl2::destroyWindow()
{
    if (mFont)
       TTF_CloseFont(mFont);
    if (mWindow)
       SDL_DestroyWindow(mWindow);
    if (mWindowRender)
       SDL_DestroyRenderer(mWindowRender);
    if (SDL_WasInit(0)) {
        SDL_Quit();
    }
    if (TTF_WasInit()) {
        TTF_Quit();
    }
}

void Sdl2::display()
{
    SDL_RenderPresent(mWindowRender);
}

void Sdl2::clear()
{
    SDL_SetRenderDrawColor(mWindowRender, 0, 0, 0, 255);
    SDL_RenderClear(mWindowRender);
}

void Sdl2::drawText(const Text &text)
{
    if(TTF_Init() == -1) {
        printf("[ERROR] TTF_Init() Failed with: %s\n", TTF_GetError());
        return;
    }
        
    mFont = TTF_OpenFont(("./include/fonts/" + text.getFont() + ".ttf").c_str(), text.getSize());
    SDL_Color color = {(Uint8)text.getColor().getR(), (Uint8)text.getColor().getG(), (Uint8)text.getColor().getB()};
    SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, text.getText().c_str(), color);
    SDL_Texture *msg = SDL_CreateTextureFromSurface(mWindowRender, textSurface);
    
    SDL_Rect msg_rect;
    msg_rect.x = text.getX();
    msg_rect.y = text.getY();
    msg_rect.h = textSurface->h;
    msg_rect.w = textSurface->w;

    SDL_RenderCopy(mWindowRender, msg, NULL, &msg_rect);
    
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(msg);
}

void Sdl2::drawRect(const Rect &rect) { 
    SDL_Rect shape;
    
    shape.x = rect.getX();
    shape.y = rect.getY();
    shape.w = rect.getWidth();
    shape.h = rect.getHeight();
    
    SDL_SetRenderDrawColor(mWindowRender, rect.getColor().getR(), rect.getColor().getG(), rect.getColor().getB(), rect.getColor().getA());
    SDL_RenderFillRect(mWindowRender, &shape);
}

std::vector<Event> Sdl2::getEvents() {
    std::vector<Event> events;
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                events.push_back(Event::QUIT);
                break;
            case SDL_KEYDOWN:
                if (sdlEvent.key.keysym.sym == SDLK_t) {
                    events.push_back(Event::NEXT_LIB);
                    break;
                }
        }
    }

    return events;
}

std::string Sdl2::getName() const {
    return mName;
}

extern "C" {
    ADisplayModule *createDisplay() {
        return new Sdl2();
    }
}

