/*
** arcade_Xlib.cpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/graphical/src/Xlib
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Wed Mar 26 18:40:12 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Mon Mar 30 21:15:51 2025 Elias Josué HAJJAR LLAUQUEN
*/

#include "arcade_xlib.hpp"
#include "Text.hpp"
#include "Color.hpp"
#include <cstring>

Xlib::Xlib()
{
    mName = "Xlib";
}

Xlib::~Xlib()
{
    destroyWindow();
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
    mFont = XLoadQueryFont(mDisplay, "-misc-fixed-medium-r-normal--9-90-75-75-c-60-iso10646-1");
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
    XDestroyWindow(mDisplay, mWindow);
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
    XDrawString(mDisplay, mWindow, mGC, 15, 20, text.getText().c_str(), text.getText().length());
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
                if (keysym == XK_t || keysym == XK_T)
                    events.push_back(Event::NEXT_LIB);
                if (keysym == XK_Up)
                    events.push_back(Event::K_UP);
                if (keysym == XK_Down)
                    events.push_back(Event::K_DOWN);
                if (keysym == XK_Left)
                    events.push_back(Event::K_LEFT);
                if (keysym == XK_Right)
                    events.push_back(Event::K_RIGHT);
            }
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
