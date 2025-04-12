/**
 * @file EventEnum.hpp
 * @brief Enumération des événements pour le système d'entrée
 * @author Elias H.
 *
 * Ce fichier définit une énumération des différents événements pouvant être utilisés
 * dans le système d'entrée de l'Arcade.
 */

#ifndef EVENTENUM_HPP_
# define EVENTENUM_HPP_

/**
 * @enum Event
 * @brief Enumération des événements pour le système d'entrée
 *
 * Cette énumération définit les différents types d'événements qui peuvent être
 * capturés et traités par le système d'entrée de l'Arcade.
 */
enum class Event {
    NONE,
    QUIT,
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_RETURN,
    K_SPACE,
    K_F1,
    KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M,
    KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,
    KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
    NEXT_GAME, NEXT_LIB
};

#endif /* !EVENTENUM_HPP_ */
