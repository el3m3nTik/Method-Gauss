#include <iostream>
#include <stdlib.h>
#include "matrix.hpp"
#include "gauss.hpp"

using namespace AS;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m;
    std::cout << "Введите кол-во ур-ний: ";
    std::cin >> n;
    std::cout << "Введите кол-во неизвестных: ";
    std::cin >> m;
    Gauss a(n, m);
    a.GaussIn();
    a.GaussOut();
    return 0;
}