#include <iostream>
#include <array>

class Entity
{
public:
    static const int exampleSize = 5;
    int example[exampleSize];
    // this is a constructor

    std::array<int, 5> another;

    Entity()
    {
        for (int i = 0; i < exampleSize; i++)
            example[i] = 2;
        for (int i = 0; i < another.size(); i++)
            another[i] = 2;
    }

};


int main() 
{
    int example[6];
    int* ptr = example;

    *(ptr + 2) = 5;
    *(int*)((char*) ptr + 10) = 6;

    for(auto el : example) 
    {
        std::cout << el << std::endl;
    }

    // new keeps until delete it creates it on the heap
    int* another = new int[5];
    delete[] another;

    // 


    std::cout << example << std::endl;

}
