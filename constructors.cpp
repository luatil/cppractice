#include <iostream>

class Entity
{
public:
    float X, Y;

    // This is a constructor
    Entity()
    {
        X = 0, Y = 0;
    }

    Entity(float x, float y)
    {
        X = x, Y = y;
    }

    Entity(char c)
    {
        X = 13, Y = 13;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

int main() 
{
    Entity e('c');
    e.Print();
    return 0;
}

