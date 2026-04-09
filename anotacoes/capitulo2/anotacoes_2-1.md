# Introdução à Funções

No capítulo anterior, foi definido que uma função é uma coleção de comandos que são executados de forma sequencial. Embora seja verdade, essa definição não toca no ponto mais importante da função. Então, vamos atualizar para: Uma **função** é uma sequência reutilizável de comandos para um serviço específico.

Todo programa executável precisa ter uma função `main()`, onde inicia a execução. Entretanto, quando os programas começarem a ficar maiores, colocar todo o código dentro da função `main()` se torna difícil de gerenciar. As funções providenciam uma forma de repartir o programa em pedaços modulares mais fáceis de organizar, testar e usar.

A maioria dos programas usa funções, e a biblioteca padrão do C++ vem como várias funções já escritas para serem usadas. No entanto, é muito comum o programador escrever suas próprias funções, o que é chamado de **funções definidas pelo usuário**.

A forma como um programa executa funções é semelhante ao uso de marcadores de livros no dia a dia. O programa será executado sequencialmente, até que seja encontrada uma chamada de função. Uma **chamada de função** diz à CPU para interromper a função atual e executar outra função. A CPU, essencialmente, "coloca um marcador" onde a execução da função principal partou, executa a função chamada, e então **retorna** para o ponto marcado para continuar a execução.

## Exemplo de Função Definida pelo Usuário

Vamos começar com a sintaxe mais básica para a definição de uma função:

```cpp
tipoDeRetorno nomeDaFuncao()  // O cabeçalho da função indica ao compilador sobre a existência da função
{
    // O corpo da função diz ao compilador o que a função irá fazer
}
```

A primeira linha é conhecida como **cabeçalho da função**, e ela sinaliza ao compilador sobre a existência de uma função, seu nome, e outras informações. Assim com variáveis, funções do usuário possuem nomes (indentificadores). O uso dos parênteses ao lado do nome indica ao compilador que estamos definindo uma função.

As chaves e os comandos dentro delas são chamadas de **corpo da função**. É aqui onde os comandos que determinam o que a função faz irão ficar.

Para chamar uma função dentro do código, usamos o nome da função junto com os parênteses (ex.: `nomeDaFuncao()`). Convencionalmente, os parênteses são postos ao lado do nome da função e sem espaço em branco entre eles.

Aqui está um exemplo de programa que ilustra a definição e a chamada de uma função do usuário:

```cpp
#include <iostream>

void facaExibicao()
{
    std::cout << "Dentro de facaExibicao()\n";
}

int main() {
    std::cout << "Começando a main()\n";
    facaExibicao();
    std::cout << "Terminando a main()\n";

    return 0;
}
```

O programa inicia a execução no topo da função `main()`, e a primeira linha a ser impressa é `Começando a main()`.

A segunda linha na `main()` é uma chamada para a função `facaExibicao()`. Por ter sido identificada uma chamada de função, a execução dos comandos da `main()` é pausada, e a execução pula para o topo da função `facaExibicao()`. Quando a `facaExibicao()` terminar, a execução volta para o ponto de chamada (a função `main()`) e continua de onde parou.

Então, o próximo comando executado na `main()` será a exibição da linha `Terminando a main()`.

## Vantagens de Funções

### Chamada Múltipla

Funções podem ser chamadas mais de uma vex em momentos distintos do programa:

```cpp
#include <iostream>

void facaExibicao()
{
    std::cout << "Dentro de facaExibicao()\n";
}

int main() {
    std::cout << "Começando a main()\n";
    facaExibicao();
    facaExibicao();
    std::cout << "Terminando a main()\n";

    return 0;
}
```

### Funções em Funções

Assim como a função `main()` pode chamar outras funções, as funções chamadas também podem chamar outras funções:

```cpp
#include <iostream>

void facaB()
{
    std::cout << "Dentro de facaB()\n";
}

void facaA()
{
    std::cout << "Começando facaA()\n";

    facaB();

    std::cout << "Encerrando facaB()\n";
}

int main()
{
    std::cout << "Começando main()\n";

    facaA();

    std::cout << "Encerrando main()\n";

    return 0;
}
```

```console
Começando main()
Começando facaA()
Dentro de facaB()
Encerrando facaA()
Encerrando main()
```

## Funções Aninhadas

Uma função cuja definição está dentro de outra função é chamada de **função aninhada**. Embora possível em outras linguagens de programação, C++ não permite funções aninhadas. 

Então, isso:

```cpp
#include <iostream>

int main()
{
    void foo()
    {
        std::cout << "foo!\n";
    }

    return 0;
}
```

não é possível, e deve ser reescrito desta forma:

```cpp
#include <iostream>

void foo()
{
    std::cout << "foo!\n";
}

int main()
{
    foo();

    return 0;
}
```