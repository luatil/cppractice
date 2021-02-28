#include<iostream>

class Entity
{
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

// Instance of Entity
class Player : public Entity
{
public: 
    const char* Name;

    // This is the constructor
    Player() 
    {
    }

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
    
};


int main()
{
    Player P;
    P.Name = "her";
    P.PrintName();

    return 0;
}