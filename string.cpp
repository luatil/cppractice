#include <iostream>
#include <string>

// The const & part is about optimatization, you don't want to copy the whole function
void print_string(const std::string& string)
{
    std::cout << string << std::endl;
}

int main()
{
    // Strings are immutable
    const char* name = "Cherno";
    // They are null terminatted string
    char simple_str[10];
    std::string str = "Cherno";
    str += "hello !";
    std::cout << str << std::endl;

    // Or even 
    std::string test = std::string("Cherno") + " hello!";
    std::cout << test << std::endl;


    return 0;
}
