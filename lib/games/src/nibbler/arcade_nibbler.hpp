/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
** File description:
** arcade_nibbler
*/

#ifndef ARCADE_Nibbler_HPP_
# define ARCADE_Nibbler_HPP_

#include "AGameModule.hpp"
#include <thread>
#include <fstream>

/**
 * @enum Move
 * @brief Represents the possible movement directions for the snake.
 */
enum Move {
    NONE = -1,
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

/**
 * @enum Type
 * @brief Represents the types of elements in the game map.
 */
enum Type {
    VOID = 0,
    HEAD = 1,
    BODY = 2,
    APPLE = 3,
    WALL = 4
};

/**
 * @class Nibbler
 * @brief Represents the Nibbler game module.
 */
class Nibbler : public AGameModule {
    public:
        /**
         * @brief Constructor for the Nibbler class.
         * @param name The name of the game module (default: "nibbler").
         */
        Nibbler(std::string name = "nibbler");

        /**
         * @brief Destructor for the Nibbler class.
         */
        ~Nibbler();
        
        /**
         * @brief Get the name of the game module.
         * @return The name of the game module.
         */
        std::string getName() const override;

        /**
         * @brief Get the rectangles to be displayed.
         * @return A vector of Rect objects.
         */
        std::vector<Rect> getRects() const override;

        /**
         * @brief Get the texts to be displayed.
         * @return A vector of Text objects.
         */
        std::vector<Text> getTexts() const override;

        /**
         * @brief Update the game state.
         */
        void update() override;

        /**
         * @brief Initialize the game.
         */
        void init() override;

        /**
         * @brief Stop the game.
         */
        void stop() override;

        /**
         * @brief Handle an event.
         * @param event The event to handle.
         * @return The resulting event.
         */
        Event handleEvent(Event event) override;

    protected:
        /**
         * @brief Handle the snake's movement.
         */
        void HandleMovement();

        /**
         * @brief Handle actions based on the snake's position.
         * @param x The x-coordinate of the action.
         * @param y The y-coordinate of the action.
         */
        void HandleActions(int x, int y);

        /**
         * @brief Generate a new apple on the map.
         */
        void generateApple();

        /**
         * @brief Update the snake's body positions.
         */
        void updateBody();

        /**
         * @brief Reset the game state.
         */
        void Reset();

        /**
         * @brief Display the game map.
         */
        void DisplayMap();

        /**
         * @brief Display the snake.
         */
        void DisplayNibbler();

        /**
         * @brief Display game information.
         */
        void DisplayInfos();

        /**
         * @brief Load a specific map.
         * @param nb The map number to load.
         */
        void Map(int nb);

        /**
         * @brief Parse a map file and load its contents.
         * @param filename The name of the map file.
         */
        void parseMap(const std::string &filename);

        /**
         * @brief Check for intersections and handle them.
         * @param x The x-coordinate to check.
         * @param y The y-coordinate to check.
         */
        void checkIntersection(int x, int y);

        /**
         * @brief Check the current level and handle level transitions.
         */
        void checkLVL();

        int _x; ///< The x-coordinate of the snake's head.
        int _y; ///< The y-coordinate of the snake's head.
        Move _Direction; ///< The current direction of the snake.
        bool _GameOver; ///< Whether the game is over.
        bool _GameOverScreen; ///< Whether the game over screen is displayed.
        int score; ///< The current score.
        int _NumMap; ///< The current map number.
        std::vector<std::tuple<int, int, int, int>> _Nibblerbody; ///< The snake's body segments.
        std::vector<std::vector<Type>> _map; ///< The game map.
};

#endif /* !ARCADE_Nibbler_HPP_ */