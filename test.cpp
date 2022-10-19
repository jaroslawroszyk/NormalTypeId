#include "typeIdNormal.hpp"
#include <iostream>
#include <vector>

struct Foo{
    std::string a;
};

int main()
{
    std::vector<Foo> vec;
    std::cout << specialTypeid(vec).name();
}