# Desenvolvendo o Primeiro Programa

Todas as lições passadas nos introduziam a uma grande quantia de terminologia e conceitos que serão usados em todo programa a ser criado. Agora, vamos usar esses conceitos em nosso primeiro simples programa.

## Multiplicar por 2

Primeiro, vamos criar um programa que recebe um inteiro do usuário, e o diz quanto é esse número multiplicado por 2, produzindo a seguinte saída (considerando a entrada como 4):

```console
Insira um inteiro: 4
O dobro desse número é: 8
```

> **Boa Prática**
>
> Programadores iniciantes tendem a escrever o programa inteiro de uma vez, e então sentem-se sobrecarregados quando vários erros aparecem. Adicione uma peça por vez, tenha certeza de que esta compile, e faça o teste. Se estiver funcionando, vá para a próxima peça.

Vamos criar o programa passo a passo.

Primeiro, criamos um novo projeto de console (ou arquivo C++ (extensão `.cpp`)).

Vamos iniciar com estruturas básicas. Sabemos que precisamos de uma função main():

```cpp
int main()
{
    return 0;
}
```

Sabemos que também precisamos mostrar textos ao console, e obter entradas do usuário, através da biblioteca iostream e das variáveis std::cout e std::cin:

```cpp
#include <iostream>

int main()
{
    return 0;
}
```

Agora, vamos dizer ao usuário para inserir um número inteiro:

```cpp
#include <iostream>

int main()
{
    std::cout << "Insira um inteiro: ";

    return 0;
}
```

Se compilarmos e executarmos o programa, teremos o seguinte:

```console
Insira um inteiro: 
```

Vamos agora obter a entrada do usuário, usando std::cin e o operador `>>`. Para isso, também devemos usar uma variável para guardar essa entrada:

```cpp
#include <iostream>

int main()
{
    std::cout << "Insira um inteiro: ";

    int num{ };
    std::cin >> num;

    return 0;
}
```

Testando o programa, agora, ao invés de terminar automaticamente, o console irá esperar a entrada, e então irá encerrar.

Agora, vamos fazer o último passo: multiplicar por 2.

Temos aqui três maneiras:

### Maneira não tão boa:

```cpp
#include <iostream>

int main()
{
    std::cout << "Insira um inteiro: ";

    int num{ };
    std::cin >> num;

    num = num * 2;

    std::cout << "O dobro desse número é: " << num << '\n';

    return 0;
}
```

Usamos uma expressão para multiplicar *num* por 2, e retornar esse valor para *num*. Esta solução não é tão boa, pois:

- Antes da atribuição, a variável tem um valor, mas após tem outro valor
- Sobrescrevemos a entrada do usuário, perdendo-a

### Maneira mediana

```cpp
#include <iostream>

int main()
{
    std::cout << "Insira um inteiro: ";

    int num{ };
    std::cin >> num;

    int doublenum{ num * 2 };
    std::cout << "O dobro desse número é: " << doublenum << '\n';

    return 0;
}
```

Esta solução não tem a troca da entrada do usuário, mas não é necessário criar uma nova variável apenas para uma exibição.

### Maneira melhor

```cpp
#include <iostream>

int main()
{
    std::cout << "Insira um inteiro: ";

    int num{ };
    std::cin >> num;

    std::cout << "O dobro desse número é: " << num * 2 << '\n';

    return 0;
}
```

Essa é a melhor maneira para o objetivo de uma exibição simples. O valor da variável não será alterado, permitindo usá-lo depois, e não precisamos gastar memória com um variável usada para uma parte somente.