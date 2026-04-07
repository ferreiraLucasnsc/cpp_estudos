#include <iostream>

int main() {
    std::cout << "Insira um número inteiro: ";

    int num {};
    std::cin >> num;

    std::cout << "O dobro desse número é: " << num * 2 << '\n';

    return 0;
}