#include <iostream>
#include <string>

// void Print(int value)
// {
//     std::cout << value << std::endl;
// }

// void Print(std::string value)
// {
//     std::cout << value << std::endl;
// }

// void Print(float value)
// {
//     std::cout << value << std::endl;
// }

//template<class T>
template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    int GetSize() const { return N; }
};

int main()
{
    Print<int>(5);
    Print("hello");
    Print<float>(5.4);

    Array<float, 5> array;
    Print(array.GetSize());

    return 0;
}