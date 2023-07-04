
#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H
#include <vector>

enum MOVE {UP, DOWN, LEFT, RIGHT};
enum TURN {TURN_LEFT, TURN_RIGHT};
enum GameState{RUNNING, START, FINISHED_LOSS};

class SnakeB {
    int height;
    int width;

    MOVE current_direction;
    bool start;
    std::vector <std::pair <int, int>> snake; // użylem pair zamiast structa (ze structem mi nie chciało zadziałać z jakiegoś powodu¿?¿?)
    std::pair<int,int> fruit;
    GameState GameStatus;
    int points;

public:
    SnakeB(int height, int width);
    void debug_display() const;
    bool check_snake_cords(int x, int y, int & idx) const;
    bool eat_fruit();
    bool update();
    GameState getGameState() const;
    bool isOutsideBoard(int x, int y) const;
    bool turn(TURN t);
    void fruit_generator (int &x, int & y) const;
    bool fruit_cords(int x, int y) const;
    bool IsCollision() const;
    int GetBoardHeight() const;
    int GetBoardWidth() const;
    char GetFieldInfo(int row, int col) const;
    MOVE GetCurrentMovement() const;
    void restartGame();
    void StartGame();
    int getPoints() const;

};


#endif
