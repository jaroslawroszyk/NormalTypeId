#include "typeIdNormal.hpp"
#include <iostream>
#include <vector>
#include <set>

struct Foo{
    std::string a;
};

int main()
{
    std::vector<Foo> vec;
    std::cout << specialTypeid(vec).name();
}