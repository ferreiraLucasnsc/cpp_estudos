#include <iostream>

int main()
{
    std::cout << "Insira dois números: ";

    int x {};
    std::cin >> x;

    int y {};
    std::cin >> y;

    std::cout << "Você inseriu " << x << " e " << y << '\n';

    return 0;
}