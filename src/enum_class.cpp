#include <iostream>

enum class Direction
{
    North,
    South,
    East,
    West
};

int main()
{
    Direction d = Direction::East;
    std::cout << (int)d << std::endl;
    printf("%d\n", d);
}