/*
** arcade_Xlib.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/Xlib
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:40:12 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Wed Apr 1 16:21:26 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_xlib.hpp"
#include "Text.hpp"
#include "Color.hpp"
#include <cstring>

Xlib::Xlib()
{
    mName = "xlib";
    mEvents = {
        {XK_Up, Event::K_UP},
        {XK_Down, Event::K_DOWN},
        {XK_Left, Event::K_LEFT},
        {XK_Right, Event::K_RIGHT},
        {XK_t, Event::NEXT_LIB},
        {XK_y, Event::NEXT_GAME},
        {XK_Escape, Event::K_ESCAPE},
        {XK_Return, Event::K_RETURN},
        {XK_space, Event::K_SPACE},
        {XK_a, Event::KEY_A},
        {XK_b, Event::KEY_B},
        {XK_c, Event::KEY_C},
        {XK_d, Event::KEY_D},
        {XK_e, Event::KEY_E},
        {XK_f, Event::KEY_F},
        {XK_g, Event::KEY_G},
        {XK_h, Event::KEY_H},
        {XK_i, Event::KEY_I},
        {XK_j, Event::KEY_J},
        {XK_k, Event::KEY_K},
        {XK_l, Event::KEY_L},
        {XK_m, Event::KEY_M},
        {XK_n, Event::KEY_N},
        {XK_o, Event::KEY_O},
        {XK_p, Event::KEY_P},
        {XK_q, Event::KEY_Q},
        {XK_r, Event::KEY_R},
        {XK_s, Event::KEY_S},
        {XK_u, Event::KEY_U},
        {XK_v, Event::KEY_V},
        {XK_w, Event::KEY_W},
        {XK_x, Event::KEY_X},
        {XK_z, Event::KEY_Z},
        {XK_1, Event::KEY_1},
        {XK_2, Event::KEY_2},
        {XK_3, Event::KEY_3},
        {XK_4, Event::KEY_4},
        {XK_5, Event::KEY_5},
        {XK_6, Event::KEY_6},
        {XK_7, Event::KEY_7},
        {XK_8, Event::KEY_8},
        {XK_9, Event::KEY_9},
        {XK_0, Event::KEY_0}
    };
}

Xlib::~Xlib()
{
}

void Xlib::createWindow()
{
    mDisplay = XOpenDisplay(getenv("DISPLAY")); // Ouverture d'un display
    mScreen = DefaultScreen(mDisplay);
    if (mDisplay) {
        mWindow = XCreateSimpleWindow(mDisplay, RootWindow(mDisplay, mScreen), 0, 0, 800, 600, 5, BlackPixel(mDisplay, mScreen), BlackPixel(mDisplay, mScreen));
    }
    XSelectInput(mDisplay, mWindow, KeyPressMask | ButtonPressMask);
    XMapWindow(mDisplay, mWindow);
    mGC = XCreateGC(mDisplay, mWindow, 0, 0);
    XSetFillStyle(mDisplay, mGC, FillSolid);
    XSync(mDisplay, False);
    XSetForeground(mDisplay, mGC, BlackPixel(mDisplay, mScreen));
    XSetBackground(mDisplay, mGC, BlackPixel(mDisplay, mScreen));
    mFont = XLoadQueryFont(mDisplay, "-misc-fixed-medium-r-normal--20-200-75-75-c-100-iso10646-1");
    XSetFont(mDisplay, mGC, mFont->fid);
    XSizeHints *size_hints = XAllocSizeHints();
    size_hints->flags = PMinSize | PMaxSize;
    size_hints->min_width = size_hints->max_width = 800;
    size_hints->min_height = size_hints->max_height = 600;
    XSetWMNormalHints(mDisplay, mWindow, size_hints);
    XFree(size_hints);
}

void Xlib::destroyWindow()
{
    XCloseDisplay(mDisplay);
}

void Xlib::display()
{
    XMapWindow(mDisplay, mWindow);
    XFlush(mDisplay);
    usleep(128000);
}

void Xlib::clear()
{
    XClearWindow(mDisplay, mWindow);
    XSetForeground(mDisplay, mGC, BlackPixel(mDisplay, mScreen));
    XSetBackground(mDisplay, mGC, BlackPixel(mDisplay, mScreen));
}

void Xlib::drawText(const Text &text)
{
    XSetForeground(mDisplay, mGC, RGB(text.getColor().getR(), text.getColor().getG(), text.getColor().getB()));
    XDrawString(mDisplay, mWindow, mGC, text.getX(), text.getY() + 15, text.getText().c_str(), text.getText().length());
}

void Xlib::drawRect(const Rect &rect)
{
    XSetForeground(mDisplay, mGC, RGB(rect.getColor().getR(), rect.getColor().getG(), rect.getColor().getB()));
    XFillRectangle(mDisplay, mWindow, mGC, rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
}

std::vector<Event> Xlib::getEvents()
{
    std::vector<Event> events;
    char buffer[32];
    KeySym keysym;
    
    while (XPending(mDisplay)) {
        XNextEvent(mDisplay, &mEvent);
        
        switch (mEvent.type) {
            case Expose:
                XFlush(mDisplay);
                break;
            case KeyPress: {
                XLookupString(&mEvent.xkey, NULL, 0, &keysym, nullptr);
                if (mEvents.find(keysym) != mEvents.end())
                    events.push_back(mEvents[keysym]);
                break;
            }
            default:
                break;
        }
    }
    return events;
}

std::string Xlib::getName() const
{
    return mName;
}

unsigned long Xlib::RGB(int r, int g, int b) 
{
    return b + (g<<8) + (r<<16);
}

extern "C" {
    ADisplayModule *createDisplay() {
        return new Xlib();
    }
}