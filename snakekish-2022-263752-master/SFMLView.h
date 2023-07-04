
#ifndef SNAKE_SFMLVIEW_H
#define SNAKE_SFMLVIEW_H
#include "SnakeB.h"

#include<SFML/Graphics.hpp>
class SFMLView {
    SnakeB & board;

    sf::RectangleShape field;
    sf::RectangleShape snake;
    sf::RectangleShape fruit;



    sf::Font font;
    sf::Text text;
    sf::Text score;

public:
    explicit  SFMLView(SnakeB & b);
    void drawOnWindow(sf::RenderWindow & win);
};


#endif //SNAKE_SFMLVIEW_H
