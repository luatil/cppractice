#include <iostream>


class Entity
{
public:
    float X, Y;

    // This is a constructor
    Entity()
    {
        X = 0, Y = 0;
        std::cout << "Constructed Entity" << std::endl;
    }

    // This is a destructor, notice the tilde
    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

void Fun()
{
    Entity e;
    e.Print();
}

int main() 
{
    Fun();
    return 0;
}