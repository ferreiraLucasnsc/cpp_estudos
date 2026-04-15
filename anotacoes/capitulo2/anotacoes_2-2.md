# Funções com Retorno de Valores

Considere o seguinte programa:

```cpp
#include <iostream>

int main()
{
    std::cout << "Insira um número: ";
    int num{};
    std::cin >> num;

    std::cout << num << "multiplicado por 2 é: " << num * 2 << '\n';

    return 0;
}
```

O programa usa uma entrada do usuário para realizar uma ação, que é multiplicá-la por dois. Vamos transformar o processo de obter o valor em uma função:

```cpp
#include <iostream>

void obterValorDoUser() {
    std::cout << "Insira um número: ";
    int val{};
    std::cin >> val;
}

int main()
{
    obterValorDoUser();

    int num {};
    std::cout << num << "multiplicado por 2 é: " << num * 2 << '\n';

    return 0;
}
```

Conseguimos separar as partes, mas o programa não irá funcionar.

A função `obterValorDoUser` será chamada e executará da maneira que foi especificada: permitir que o usuário insira um valor. No entanto, este valor inserido será perdido na transição entre a função `obterValorDoUser` e a `main`.

Precisamos então de alguma coisa que consiga fazer o valor da função `obterValorDoUser` consiga chegar na função `main`.

## Valores de Retorno

Ao escrever uma função de usuário, podemos determinar se a função irá retornar um valor para quem a chama ou não. Para retornar um valor, precisamos de duas coisas.

Primeiro, a função precisa indicar o tipo de valor que será retornado, configurando o **tipo de retorno**, que é o tipo definido antes do nome da função. No exemplo acima, a função criada possui o tipo `void` (não haverá retorno), e a função `main` possui o tipo `int` (o retorno será um inteiro).

Depois, dentro da função que terá o valor, usamos um **comando de retorno** para indicar o valor específico a ser retornado. O comando de retorno consiste da paavra-chave `return` acompanhada por uma expressão e um ponto e vírgula.

Quando o comando de retorno é executado:

- A expressão de retorno é avaliada para produzir um valor
- O valor produzido pela expressão de retorno é copiado para a função que chamou. A cópia é chamada de **valor de retorno**
- A função encerra, e o controle retorna para quem a chamou

Uma função com retorno de valor irá retornar um valor em toda vez que for chamada:

```cpp
#include <iostreamm>

int retornarCinco()
{
    return 5;
}

int main()
{
    std::cout << retornarCinco() << '\n';
    std::cout << retornarCinco() + 2 << '\n';

    retornarCinco();

    return 0;
}
```

Na chamada das funções, mesmo com apenas um comando, o que será exibido será o valor retornado. Na primeira chamada, será exibido `5`, e na segunda será exibido `7` (valor da função -> 5 + 2 -> 7). A última chamada não está atribuída a nada, então o valor será ignorado.

Assim, podemos consertar nosso programa inicial:

```cpp
#include <iostream>

void obterValorDoUser() {
    std::cout << "Insira um número: ";
    int val{};
    std::cin >> val;

    return val;
}

int main()
{
    int num{ obterValorDoUser() };

    std::cout << num << "multiplicado por 2 é: " << num * 2 << '\n';

    return 0;
}
```

Quando o programa executar, o primeiro comando da `main` será criar uma variável `int` com o identificador `num`. Na parte da inicialização, o compilador irá identificar uma chamada para a variável `obterValorDoUser()`, então será executada a função. Os comandos da função a serem executados serão pedir ao usuário para inserir, e então retornar o valor para a função quem chamou (`main()`). Este valor retornado então será usado como o valor para a inicialização da variável `num`, que poderá ser usada quantas vezes for o necessário.

Com o entendimento de como uma função ocorre, podemos entender a função `main()`. Quando o programa roda, o sistema operacional faz uma chamada à função `main()`, e a execução pula para o topo da `main()`. Então, quando a `main()` encerra, retorna um valor inteiro (geralmente `0`), e o programa termina.

Em C++, existem dois requerimentos para a função `main()`:

- A função `main()` precisa retornar um `int`.
- Chamadas à função `main()` explícitas não são permitidas.

## Códigos de Status

O retorno da função `main()` é chamado de **código de status**, e é utilizado para sinalizar se o programa foi um sucesso ou não.

Por convenção, um código de status com `0` significa que o programa correu normalmente, enquanto um código diferente de zero indica algum tipo de falha.

## Comportamento Inesperado com Funções

Se uma função de retorno de valores não possui um retorno de valor do tipo, o que será resultado é comportamento inesperado.

```cpp
#include <iostream>

int pegarValorDoUser()
{
    std::cout << "Insira um número: ";
    int input{};
    std::cin >> input;

    // sem retorno
}

int main()
{
    int num { pegarValorDoUser() };

    std::cout << num;

    return 0;
}
```

Um compilador moderno irá gerar um aviso em uma função com tipo definido sem retorno, e executar um programa com esta situação irá produzir comportamento inesperado.

A única exceção a esta regra é a função `main()`, que implicitamente irá retornar o valor `0` se não houver comando de retorno. Mesmo assim, a melhor prática é inserir um retorno explícito.

## Retorno Único

Uma função com retorno pode retornar apenas um valor quando é chamada. Este valor pode ser o resultado de um expressão válida, como uma variável ou uma chamada de função.

## Reutilização de Funções

Com o funcionamento básico de uma função entendido, podemos mostrar a principal vantagem de uma função: reuso de código.

```cpp
#include <iostream>

int main()
{
    int x{};
    std::cout << "Insira um inteiro: ";
    std::cin >> x;

    int y{};
    std::cout << "Insira um inteiro: ";
    std::cin >> y;

    return 0;
}
```

Embora este código funcione sem problemas com a repetição, repetir as linhas de código é um trabalho desnecessário com código redudante, principalmente se o código duplicado será repetido várias vezes.

Ao invés de repetir código manualmente, podemos criar uma função com a funcionalidade necessária, e repetir a chamada de função o quanto for necessário.

```cpp
#include <iostream>

int pegarValorDoUser()
{
    std::cout << "Insira um número: ";
    int input{};
    std::cin >> input;

    return input;
}

int main()
{
    int x{ pegarValordoUser() };
    int y{ pegarValordoUser() };

    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}
```

Agora, o programa utiliza a função `pegarValorDoUser()` duas vezes, na inicialização das variáveis `x` e `y`. Usando as chamadas de função, evitamos redundância de código.

A essência da programação modular é utilizar funções para reutilização de código e separação de funcionalidades.