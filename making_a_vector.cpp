#include <iostream>

template<typename T> 
class Vector
{
public:
    Vector()
    {
        // allocate some heap memory
        ReAlloc(2);
    }
    void push_back(const T& value)
    {
        if(m_Size >= m_Capacity)
        {
            m_Capacity = m_Capacity + m_Capacity / 2;
            ReAlloc(m_Capacity);
        }
        m_Data[m_Size] = value;
        m_Size++;
    }

    T& operator[](size_t index) 
    {
        // if(index >= m_size)
        return m_Data[index];
    }
    
    const T& operator[](size_t index) const 
    {
        return m_Data[index];
    }

    size_t get_size() const
    {
        return m_Size;
    }
private:
    void ReAlloc(size_t newCapacity)
    {
        // 1. allocate a new block of memory
        // 2. copy the elements  // try to move them 
        // 3. delete
        T* newBlock = new T[newCapacity];

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for(size_t i = 0; i < m_Size; i++)
            newBlock[i] = m_Data[i];

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};

template <typename T>
void PrintVector(const Vector<T>& vector)
{
    for(size_t i = 0; i < vector.get_size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }
}


int main()
{
    Vector<std::string> vector;
    vector.push_back("Cherno");
    vector.push_back("C++");
    vector.push_back("Vector");
    PrintVector(vector);
    return 0;
}