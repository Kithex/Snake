#include <iostream>
#include <SFML/Graphics.hpp>
#include "SnakeB.h"

#include <ctime>
#include "SFMLView.h"
#include "SMFLController.h"
#include "SFMLMENU.h"
#include <windows.h>
#include <stdlib.h>
using namespace std;
int main() {
    srand(time(nullptr));
    constexpr int screen_width = 800;
    constexpr int screen_height = 600;

    sf::RenderWindow win(sf::VideoMode(screen_width, screen_height), "SNAKE");
    win.setFramerateLimit(30);


    SnakeB board(14, 18);

    SFMLView View(board);
    SMFLController play(board);
    SFMLMENU menu(board);

//    b1.play();


    while (win.isOpen()) {
        sf::Event event;

        if(board.getGameState()==START)
        {
            win.clear(sf::Color::Black);
            menu.draw(win);
            menu.handleEvent( event);
            win.display();
            while (win.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    win.close();
            }
        }

        if(board.getGameState()==RUNNING)
        {
            if (!win.pollEvent(event)) {
                Sleep(60);
                board.update();
                win.clear(sf::Color(192, 192, 192));
                View.drawOnWindow(win);
                win.display();
            }

            while (win.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    win.close();
                    continue;
                } else if (event.type == sf::Event::KeyPressed) {
                    Sleep(60);
                    play.handleEvent(event);
                    board.update();
                }

                win.clear(sf::Color(192, 192, 192));

                View.drawOnWindow(win);
                win.display();

            }
        }
        if(board.getGameState()==FINISHED_LOSS or board.IsCollision())
        {
            //  board.savePoints(board.getPoints());
            board.restartGame();
            while (win.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    win.close();
            }

        }


    }
}



