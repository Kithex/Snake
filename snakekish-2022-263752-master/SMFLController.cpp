#include"SFMLView.h"
#include "SMFLController.h"
using namespace std;
SMFLController::SMFLController(SnakeB & b): board(b)
{



}

void SMFLController::handleEvent(sf::Event &event) {
    if (board.getGameState() == RUNNING)
    {
        if (event.type == sf::Event::KeyPressed)
        {

            if (event.key.code == sf::Keyboard::Down and board.GetCurrentMovement() == RIGHT){
                board.turn(TURN_RIGHT);
            } else if (event.key.code == sf::Keyboard::Up and board.GetCurrentMovement() == RIGHT) {
                board.turn(TURN_LEFT);
            } else if (event.key.code == sf::Keyboard::Left and board.GetCurrentMovement() == UP) {
                board.turn(TURN_LEFT);
            } else if (event.key.code == sf::Keyboard::Right and board.GetCurrentMovement() == UP) {
                board.turn(TURN_RIGHT);
            } else if (event.key.code == sf::Keyboard::Right and board.GetCurrentMovement() == DOWN) {
                board.turn(TURN_RIGHT);
            } else if (event.key.code == sf::Keyboard::Left and board.GetCurrentMovement() == DOWN) {
                board.turn(TURN_LEFT);
            } else if (event.key.code == sf::Keyboard::Up and board.GetCurrentMovement() == LEFT) {
                board.turn(TURN_RIGHT);
            } else if (event.key.code == sf::Keyboard::Down and board.GetCurrentMovement() == LEFT) {
                board.turn(TURN_LEFT);
            }


        }


    }



}
