/**
 * @file AGameModule.hpp
 * @brief Classe abstraite pour les modules des jeux
 * @author Elias H. <elias-josue.hajjar-llauquen@epitech.eu> & Enzo C. <enzo.lobato-couthino@epitech.eu>
 *
 * Ce fichier définit la classe de base abstraite pour les modules des jeux.
 */

#ifndef AGAMEMODULE_HPP_
# define AGAMEMODULE_HPP_

#include "./interfaces/IGame.hpp"

/**
 * @class AGameModule
 * @brief Classe abstraite pour les libraries de jeux.
 *
 * Utilisé pour l'ouverture / utilisation des Jeux.
 * Elle hérite de IGameModule
 */
class AGameModule : public IGameModule {
    public:
        AGameModule(std::string name = "");
        virtual ~AGameModule() = default;
        std::string getName() const override;
        void update() override = 0;
        void init() override = 0;
        void stop() override = 0;
        std::vector<Rect> getRects() const override;
        std::vector<Text> getTexts() const override;
        Event handleEvent(Event event) override = 0;

        void setGameSwitchCallback(std::function<void(std::string)> callback) override;
        void setGraphicSwitchCallback(std::function<void(std::string)> callback) override;
        void setLibSwitchCallback(std::function<void()> callback) override;

        Event handleEventGeneric(Event event) override;

    protected:
        std::string _name;
        std::vector<Rect> _rects;
        std::vector<Text> _texts;
        std::function<void(std::string)> _gameSwitchCallback;
        std::function<void()> _libSwitchCallback;
        std::function<void(std::string)> _graphicSwitchCallback;

        void switchToNextGame(const std::string &gameName = "");
        void switchToNextLib();
};

#endif /* !AGAMEMODULE_HPP_ */
