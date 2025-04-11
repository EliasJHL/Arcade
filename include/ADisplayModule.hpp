/**
 * @file ADisplayModule.hpp
 * @brief Classe abstraite pour les modules d'affichage
 * @author Elias H. <elias-josue.hajjar-llauquen@epitech.eu> & Enzo C. <enzo.lobato-couthino@epitech.eu>
 *
 * Ce fichier définit la classe de base abstraite pour les modules d'affichage.
 */

#ifndef ADISPLAYMODULE_HPP_
# define ADISPLAYMODULE_HPP_

#include "./interfaces/IDisplay.hpp"

/**
 * @class ADisplayModule
 * @brief Classe abstraite pour les libraries graphiques.
 *
 * Utilisé pour l'ouverture / utilisation des libraries graphiques.
 * Elle hérite de IDisplayModule
 */
class ADisplayModule : public IDisplayModule {
    public:
        ADisplayModule(std::string name = "");
        virtual ~ADisplayModule() = default;
        void createWindow() override = 0;
        void destroyWindow() override = 0;
        void display() override = 0;
        void clear() override = 0;
        void drawText(const Text &text) override = 0;
        void drawRect(const Rect &rect) override = 0;
        std::vector<Event> getEvents() override = 0;
        std::string getName() const override;
    protected:
        std::string _name;
};

#endif /* !ADISPLAYMODULE_HPP_ */
