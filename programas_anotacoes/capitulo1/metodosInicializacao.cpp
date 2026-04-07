#include <iostream>

int main()
{
    //      === FORMAS DE INICIALIZAÇÃO ===

    // Nenhuma inicialização
    int a;

    // Inicialização por cópia
    int b = 2;

    // Inicialização direta
    int c (6);

    // Inicialização por lista
    int d {10};

    // Iniciação por valor
    int e {};

    std::cout << "      == EXIBIÇÃO DAS VARIÁVEIS ==" << '\n';
    std::cout << "Variável a: " << a << '\n';
    std::cout << "Variável b: " << b << '\n';
    std::cout << "Variável c: " << c << '\n';
    std::cout << "Variável d: " << d << '\n';
    std::cout << "Variável e: " << e << '\n';
}