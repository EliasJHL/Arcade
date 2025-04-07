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
                switch (sdlEvent.key.keysym.sym) {
                    case SDLK_UP:
                        events.push_back(Event::K_UP);
                        break;
                    case SDLK_DOWN:
                        events.push_back(Event::K_DOWN);
                        break;
                    case SDLK_LEFT:
                        events.push_back(Event::K_LEFT);
                        break;
                    case SDLK_RIGHT:
                        events.push_back(Event::K_RIGHT);
                        break;
                    case SDLK_ESCAPE:
                        events.push_back(Event::K_ESCAPE);
                        break;
                    case SDLK_RETURN:
                        events.push_back(Event::K_RETURN);
                        break;
                    case SDLK_SPACE:
                        events.push_back(Event::K_SPACE);
                        break;
                    case SDLK_a:
                        events.push_back(Event::KEY_A);
                        break;
                    case SDLK_b:
                        events.push_back(Event::KEY_B);
                        break;
                    case SDLK_c:
                        events.push_back(Event::KEY_C);
                        break;
                    case SDLK_d:
                        events.push_back(Event::KEY_D);
                        break;
                    case SDLK_e:
                        events.push_back(Event::KEY_E);
                        break;
                    case SDLK_f:
                        events.push_back(Event::KEY_F);
                        break;
                    case SDLK_g:
                        events.push_back(Event::KEY_G);
                        break;
                    case SDLK_h:
                        events.push_back(Event::KEY_H);
                        break;
                    case SDLK_i:
                        events.push_back(Event::KEY_I);
                        break;
                    case SDLK_j:
                        events.push_back(Event::KEY_J);
                        break;
                    case SDLK_k:
                        events.push_back(Event::KEY_K);
                        break;
                    case SDLK_l:
                        events.push_back(Event::KEY_L);
                        break;
                    case SDLK_m:
                        events.push_back(Event::KEY_M);
                        break;
                    case SDLK_n:
                        events.push_back(Event::KEY_N);
                        break;
                    case SDLK_o:
                        events.push_back(Event::KEY_O);
                        break;
                    case SDLK_p:
                        events.push_back(Event::KEY_P);
                        break;
                    case SDLK_q:
                        events.push_back(Event::KEY_Q);
                        break;
                    case SDLK_r:
                        events.push_back(Event::KEY_R);
                        break;
                    case SDLK_s:
                        events.push_back(Event::KEY_S);
                        break;
                    case SDLK_t:
                        events.push_back(Event::NEXT_LIB);
                        break;
                    case SDLK_u:
                        events.push_back(Event::KEY_U);
                        break;
                    case SDLK_v:
                        events.push_back(Event::KEY_V);
                        break;
                    case SDLK_w:
                        events.push_back(Event::KEY_W);
                        break;
                    case SDLK_x:
                        events.push_back(Event::KEY_X);
                        break;
                    case SDLK_y:
                        events.push_back(Event::KEY_Y);
                        break;
                    case SDLK_z:
                        events.push_back(Event::KEY_Z);
                        break;
                    case SDLK_1:
                        events.push_back(Event::KEY_1);
                        break;
                    case SDLK_2:
                        events.push_back(Event::KEY_2);
                        break;
                    case SDLK_3:
                        events.push_back(Event::KEY_3);
                        break;
                    case SDLK_4:
                        events.push_back(Event::KEY_4);
                        break;
                    case SDLK_5:
                        events.push_back(Event::KEY_5);
                        break;
                    case SDLK_6:
                        events.push_back(Event::KEY_6);
                        break;
                    case SDLK_7:
                        events.push_back(Event::KEY_7);
                        break;
                    case SDLK_8:
                        events.push_back(Event::KEY_8);
                        break;
                    case SDLK_9:
                        events.push_back(Event::KEY_9);
                        break;
                    case SDLK_0:
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

std::string Sdl2::getName() const {
    return mName;
}

extern "C" {
    ADisplayModule *createDisplay() {
        return new Sdl2();
    }
}

