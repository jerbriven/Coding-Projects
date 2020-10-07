#include <iostream>
#include <vector>

void testfunc(int x) const
{

}

int main() 
{
    using intVector = std::vector<int>;
    intVector vec1{0, 3, 5, 1};

    decltype(auto) intVal = 3;
    std::cout << "intVal: " << intVal << std::endl;
    std::cout << "vec1[0]: " << vec1[0]; 
}