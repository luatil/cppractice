#include <iostream>

template<typename T, size_t N>
class Array
{
private:
    T m_Array[N];
public:
    constexpr int get_size() const
    {
        return N;
    }

    T& operator[](size_t index) { return m_Array[index]; }
    const T& operator[](size_t index) const { return m_Array[index]; }
};

int main()
{
    Array<int, 50> my_arr;
    static_assert(my_arr.get_size() < 500, "Size is too large!");
    std::cout << my_arr.get_size() << std::endl;
    return 0;
}
