
#ifndef SNAKE_SMFLCONTROLLER_H
#define SNAKE_SMFLCONTROLLER_H
#include "SnakeB.h"

namespace sf
{
    class Event;
}



class SMFLController {

    SnakeB & board;
public:
    explicit SMFLController(SnakeB & b);
    void handleEvent(sf::Event & event);
};


#endif //SNAKE_SMFLCONTROLLER_H
