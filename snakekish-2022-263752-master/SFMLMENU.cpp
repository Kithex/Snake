
#include "SFMLMENU.h"
#include<iostream>
using namespace std;
SFMLMENU::SFMLMENU(SnakeB & b) : board(b)
{
    int constexpr screen_width = 800;
    int constexpr screen_height = 600;


    if(!font.loadFromFile("../pliki/arial.ttf"))
        abort();

    text[0].setFont(font);
    text[0].setFillColor(sf::Color::White);
    text[0].setString("Witaj w grze SNAKE");
    text[0].setPosition(sf::Vector2f(screen_width/3-25, 30));

    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Green);
    text[1].setString("GRAJ");
    text[1].setPosition(sf::Vector2f(screen_width/2-50, screen_height/3));
}



void SFMLMENU::draw(sf::RenderWindow &window)
{
    window.draw(text[0]);
    window.draw(text[1]);


}



void SFMLMENU::handleEvent(sf::Event &event)
{

    if(event.type==sf::Event::MouseButtonPressed) {

        int x = event.mouseButton.x;
        int y = event.mouseButton.y;

        if(x>354 and x<420 and y>207 and y<231 )
        {
            board.StartGame();

        }

    }


}




