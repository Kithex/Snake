
#include "SnakeB.h"
#include <iostream>
#include <cstdlib>
#include<algorithm>
using namespace std;
using namespace std;

SnakeB::SnakeB(int height, int width)
{
    start = true;
    this->height=height;
    this->width=width;
    snake.emplace_back(3,5);
    snake.emplace_back(3,6);
    snake.emplace_back(3,7);
    fruit.first=3;
    fruit.second=3;
    current_direction=UP;
    GameStatus=RUNNING;
    points = 0;


}

void SnakeB::debug_display() const
{
    int idx=0;
    for (int y = 0; y < height; ++y)
    {

        for (int x = 0; x < width; ++x)
        {
            if(check_snake_cords(x, y,idx))
            {

                if (idx == 0)
                {
                    cout << "G";

                    continue;
                }
                else
                    cout << 'o';

            }
            else if(fruit_cords(x, y))
            {
                cout<<"A";
            }
            else
                cout << ".";

        }
        cout << endl;
    }


}
bool SnakeB::check_snake_cords(int x, int y, int & idx) const {
    for(size_t i=0; i<snake.size();i++)
    {
        if (snake[i].first == x and snake[i].second == y)
        {
            idx=static_cast<int>(i);
            return true;
        }
    }

    return false;
}

bool SnakeB::eat_fruit()
{

    if(snake[0].first == fruit.first and snake[0].second == fruit.second)
    {
        int x,y;
        x=snake[snake.size()-1].first;
        y=snake[snake.size()-1].second;
        if(current_direction == UP)
        {
            snake.insert(snake.end(),{x,y+1});

        }
        if(current_direction == DOWN)
        {
            snake.insert(snake.end(),{x,y-1});

        }
        if(current_direction == LEFT)
        {
            snake.insert(snake.end(),{x+1,y});

        }
        if(current_direction == RIGHT)
        {
            snake.insert(snake.end(),{x-1,y});

        }
        fruit_generator(fruit.first, fruit.second);
        ++points;
    }


}

bool SnakeB::update()
{
    int x=snake[0].first;
    int y=snake[0].second;
    if(current_direction == UP)
    {
        y=y-1;
        snake.pop_back();
        snake.insert(snake.begin(), {x,y});

    }
    else if(current_direction == DOWN)
    {
        y=y+1;
        snake.pop_back();
        snake.insert(snake.begin(),{x,y});

    }
    else if(current_direction == LEFT)
    {
        x=x-1;
        snake.pop_back();
        snake.insert(snake.begin(),{x,y});

    }
    if(current_direction == RIGHT)
    {
        x=x+1;
        snake.pop_back();
        snake.insert(snake.begin(),{x,y});

    }
    eat_fruit();
    return false;
}

GameState SnakeB::getGameState() const
{
    if(isOutsideBoard(snake[0].first, snake[0].second) or IsCollision())
        return FINISHED_LOSS;

    else if(start)
        return START;

    else
        return RUNNING;
}

bool SnakeB::isOutsideBoard(int x, int y) const
{
    if((x<0 or x>width-1) or (y<0 or y>height-1))
        return true;
    else
        return false;
}

bool SnakeB::turn(TURN t)
{
    if(current_direction == UP and t == TURN_RIGHT)
        current_direction=RIGHT;
    else if(current_direction == UP and t == TURN_LEFT)
        current_direction=LEFT;
    else if(current_direction == DOWN and t == TURN_RIGHT)
        current_direction=RIGHT;
    else if(current_direction == DOWN and t == TURN_LEFT)
        current_direction=LEFT;
    else if(current_direction == RIGHT and t == TURN_RIGHT)
        current_direction=DOWN;
    else if(current_direction == RIGHT and t == TURN_LEFT)
        current_direction=UP;
    else if(current_direction == LEFT and t == TURN_RIGHT)
        current_direction=UP;
    else if(current_direction == LEFT and t == TURN_LEFT)
        current_direction=DOWN;
}

void SnakeB::fruit_generator (int &x, int &y) const
{
    x=rand()%width;
    y=rand()%height;

}

bool SnakeB::fruit_cords(int x, int y) const {
    if (fruit.first == x and fruit.second == y)
    {
        return true;
    }
    return false;
}

bool SnakeB::IsCollision() const {
    int headx = snake[0].first;
    int heady = snake[0].second;

    for(size_t i = 1; i<snake.size();++i)
    {
        if(snake[i].first==headx and snake[i].second==heady)
            return true;
    }
    return false;
}

int SnakeB::GetBoardHeight() const {
    return height;
}

int SnakeB::GetBoardWidth() const {
    return width;
}

char SnakeB::GetFieldInfo(int col, int row) const
{
    int idx = 0;
    if(snake[0].first==col and snake[0].second==row)
    {
        return 'G';
    }
    if(check_snake_cords(col, row, idx))
    {
        return 'o';
    }
    if(fruit.first == col and fruit.second == row)
    {
        return 'A';
    }
    else
        return'.';
}

MOVE SnakeB::GetCurrentMovement() const {
    return current_direction;
}

void SnakeB::restartGame()
{
    GameStatus=START;
    start = true;
    snake.clear();
    snake.emplace_back(3,5);
    snake.emplace_back(3,6);
    snake.emplace_back(3,7);
    current_direction=UP;
    points = 0;
}

void SnakeB::StartGame() {
    GameStatus=RUNNING;
    start = false;
}

int SnakeB::getPoints() const
{
    return points;
}





