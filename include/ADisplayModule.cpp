/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
** File description:
** ADisplayModule
*/

#include "ADisplayModule.hpp"

ADisplayModule::ADisplayModule(std::string name) : _name(name)
{
}

std::string ADisplayModule::getName() const
{
    return _name;
}