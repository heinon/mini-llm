#include <iostream>
#include "tensor.hpp"

int main()
{
    Tensor ten({4,3});
    std::vector<int> v = {2,2};
    ten.print();
    ten.fill_({0,1,2,3,4,5,6,7,99,9,10,11});
    std::cout << ten.get(v) << std::endl;
    std::cout << ten.offset(v) << std::endl;
    return 0;
}