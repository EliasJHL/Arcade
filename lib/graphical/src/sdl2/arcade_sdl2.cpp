/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
** File description:
** arcade_sdl2
*/

#include "arcade_sdl2.hpp"

Sdl2::Sdl2() : mWindow(nullptr), mWindowRender(nullptr), mFont(nullptr)
{
    mName = "sdl2";
    mEvents = {
        {SDLK_UP, Event::K_UP},
        {SDLK_DOWN, Event::K_DOWN},
        {SDLK_LEFT, Event::K_LEFT},
        {SDLK_RIGHT, Event::K_RIGHT},
        {SDLK_ESCAPE, Event::K_ESCAPE},
        {SDLK_RETURN, Event::K_RETURN},
        {SDLK_SPACE, Event::K_SPACE},
        {SDLK_a, Event::KEY_A},
        {SDLK_b, Event::KEY_B},
        {SDLK_c, Event::KEY_C},
        {SDLK_d, Event::KEY_D},
        {SDLK_e, Event::KEY_E},
        {SDLK_f, Event::KEY_F},
        {SDLK_g, Event::KEY_G},
        {SDLK_h, Event::KEY_H},
        {SDLK_i, Event::KEY_I},
        {SDLK_j, Event::KEY_J},
        {SDLK_k, Event::KEY_K},
        {SDLK_l, Event::KEY_L},
        {SDLK_m, Event::KEY_M},
        {SDLK_n, Event::KEY_N},
        {SDLK_o, Event::KEY_O},
        {SDLK_p, Event::KEY_P},
        {SDLK_q, Event::KEY_Q},
        {SDLK_r, Event::KEY_R},
        {SDLK_s, Event::KEY_S},
        {SDLK_t, Event::NEXT_LIB},
        {SDLK_u, Event::KEY_U},
        {SDLK_v, Event::KEY_V},
        {SDLK_w, Event::KEY_W},
        {SDLK_x, Event::KEY_X},
        {SDLK_y, Event::NEXT_GAME},
        {SDLK_z, Event::KEY_Z},
        {SDLK_1, Event::KEY_1},
        {SDLK_2, Event::KEY_2},
        {SDLK_3, Event::KEY_3},
        {SDLK_4, Event::KEY_4},
        {SDLK_5, Event::KEY_5},
        {SDLK_6, Event::KEY_6},
        {SDLK_7, Event::KEY_7},
        {SDLK_8, Event::KEY_8},
        {SDLK_9, Event::KEY_9},
        {SDLK_0, Event::KEY_0}
    };
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
    if (mWindow)
       SDL_DestroyWindow(mWindow);
    if (mWindowRender)
       SDL_DestroyRenderer(mWindowRender);
    if (SDL_WasInit(0))
        SDL_Quit();
    if (TTF_WasInit())
        TTF_Quit();
}

void Sdl2::display()
{
    SDL_RenderPresent(mWindowRender);
    SDL_Delay(128);
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
    
    try {
        mFont = TTF_OpenFont(text.getFont().c_str(), text.getSize());
    } catch (const std::exception &e) {
        mFont = TTF_OpenFont("./assets/basic.ttf", text.getSize());
    }
    SDL_Color color = {(Uint8)text.getColor().getR(), (Uint8)text.getColor().getG(), (Uint8)text.getColor().getB()};
    SDL_Surface* textSurface = TTF_RenderText_Blended(mFont, text.getText().c_str(), color);
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
                if (mEvents.find(sdlEvent.key.keysym.sym) != mEvents.end()) {
                    events.push_back(mEvents[sdlEvent.key.keysym.sym]);
                }
                break;
            default:
                break;
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
