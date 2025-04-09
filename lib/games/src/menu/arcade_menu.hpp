/*
** arcade_menu.hpp for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games/src/menu
**
** Made by Elias Josué HAJJAR LLAUQUEN
** Login   <elias-josue.hajjar-llauquen@epitech.eu>
**
** Started on  Sat Mar 29 00:29:54 2025 Elias Josué HAJJAR LLAUQUEN
** Last update Sun Mar 29 01:18:43 2025 Elias Josué HAJJAR LLAUQUEN
*/

#ifndef ARCADE_MENU_HPP_
# define ARCADE_MENU_HPP_

#include "AGameModule.hpp"

class Menu : public AGameModule {
    public:
        Menu(std::string name = "menu");
        ~Menu();
        
        std::string getName() const override;
        std::vector<Rect> getRects() const override;
        std::vector<Text> getTexts() const override;
        
        void update() override;
        void init() override;
        void stop() override;

        Event handleEvent(Event event) override;
    private:
        std::vector<std::string> mGames;
        std::vector<std::string> mGraphic;
        std::string selected_game;
        std::string selected_graph;
        bool isGameSelected;
};

#endif /* !ARCADE_MENU_HPP_ */