#include <iostream>

template<typename T>
auto plusPlus(T&& param)
{
    return ++param;
}

template<typename T>
auto perfectFWD(T&& param)
{
    return plusPlus(std::forward<T>(param));
}

int main() 
{
    int test{34};
    std::cout << perfectFWD(34);
}