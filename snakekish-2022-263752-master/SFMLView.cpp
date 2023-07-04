
#include "SFMLView.h"

#include<windows.h>
#include <sstream>
using namespace std;
SFMLView::SFMLView(SnakeB &b) : board(b) {
    if (!font.loadFromFile("../pliki/arial.ttf"))
        abort();
    sf::Color snakeish(130, 232, 102);
    text.setFont(font);
    text.setFillColor(sf::Color::Green);
    score.setFont(font);
    sf::Color kolor(161, 131, 242);
    score.setFillColor(kolor);
    score.setPosition(50,50);

    field = sf::RectangleShape(sf::Vector2f(30, 30));
    field.setFillColor(kolor);
    field.setOutlineThickness(1);
    field.setOutlineColor(sf::Color::Black);

    snake = sf::RectangleShape(sf::Vector2f(30, 30));
    snake.setFillColor(snakeish);

    fruit = sf::RectangleShape(sf::Vector2f(30, 30));
    fruit.setFillColor(sf::Color::Red);

}
void SFMLView::drawOnWindow(sf::RenderWindow &win) {
    constexpr int screen_width = 800;
    constexpr int screen_height = 600;
    char i;

    for (int row = 0; row < board.GetBoardHeight(); row++) {
        for (int col = 0; col < board.GetBoardWidth(); col++) {
            float y;
            float x;
            y = (screen_height / board.GetBoardHeight() * row / 1.4) + 90;
            x = (screen_width / (board.GetBoardWidth()) * col / 1.5) + 120;
            i = board.GetFieldInfo(col, row);

            if (i == '.') {
                field.setPosition(x, y);
                win.draw(field);
            } else if (i == 'G') {
                snake.setPosition(x, y);
                win.draw(snake);
            } else if (i == 'o') {
                snake.setPosition(x, y);
                win.draw(snake);
            } else if (i == 'A') {
                fruit.setPosition(x, y);
                win.draw(fruit);
            }


        }
    }

    std::stringstream ss;
    ss << board.getPoints();

    score.setString(ss.str().c_str()); //znalezione na -> https://en.sfml-dev.org/forums/index.php?topic=8368.0
    score.setPosition(50,50);

    win.draw(score);


    if (board.getGameState() == FINISHED_LOSS) {

        win.clear(sf::Color::Red);
        text.setString("GAMEOVER!");
        text.setCharacterSize(50);
        text.setPosition(250, 100);
        win.draw(text);
        Sleep(150);


    }
}
