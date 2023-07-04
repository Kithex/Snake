
#ifndef SNAKE_SFMLMENU_H
#define SNAKE_SFMLMENU_H
#include"SFMLView.h"
#include"SnakeB.h"
#include <SFML/Graphics.hpp>
class SFMLMENU  {
    SnakeB & board;
    sf::Font font;
    sf::Text text[4];

public:

    explicit  SFMLMENU(SnakeB & b);
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);
};


#endif //SNAKE_SFMLMENU_H
