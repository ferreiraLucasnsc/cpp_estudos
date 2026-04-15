# Introdução ao Escopo Local

## Variáveis Locais

Variáveis definidas dentro do corpo de uma função são chamadas de **variáveis locais** (opostas às *variáveis globais*):

Parâmetros de função são também considerados variáveis locais.

```cpp
int add(int x, int y)
{
    int z{ x + y };

    return z;
}
```

A definição de uma variável causa a variável a ser instanciada na execução do comando. No caso de variáveis de função e parâmetros, estas são criadas e inicializadas, respectivamente, no ponto de definição no corpo da função e na entrada da função. Após a criação, então, variáveis também são destruídas, para liberar endereços de memória.

Variáveis locais são destruídas na ordem oposta da criação ao fim da última chave da função a que pertence.

```cpp
int add(int x, int y)  // x e z são criadas e inicializadas
{
    int z{ x + y };  // z é criada e inicializada

    return z;
}  // z, y e x são destruídas
```

A mesma situação vale para variáveis da função `main`:

```cpp
#include <iostream>

void facaAlgo()
{
    std::cout << "Olá!\n";
}

int main()
{
    int x{ 0 };  // x "nasce" aqui

    facaAlgo();  // x ainda está viva na chamada da função

    return 0;
}  // o tempo de vida de x termina aqui
```

Quando um objeto é destruído, ele se torna inválido, e qualquer uso de um objeto destruído resulta em comportamento inesperado. Após a destruição de um objeto, sua memória usada será **dealocada** (liberada para uso).

## Escopo de Bloco

O **escopo** de um identificador determina onde o identificador pode ser visto e usado no código. Quando um identificador pode ser visto e usado, dizemos que está **dentro do escopo**, e quando não pode ser visto e usado, está **fora do escopo**. O escopo é uma propriedade do tempo de compilação, e tentar usar um identificador que não está dentro do escopo resulta em erro de compilação.

Uma variável com **escopo local** (também chamado de **escopo de bloco**) é utilizável do ponto de definição até o fim da estrutura que contém o identificador. Isso garante que variáveis locais não sejam usadas antes do ponto de definição ou após sua destruição.

```cpp
#include <iostream>

// x não está no escopo desta função
void doSomething()
{
    std::cout << "Hello!\n";
}

int main()
{
    int x{ 0 };  // x entra no escopo, pode ser usado

    doSomething();

    return 0;
}  // x sai do escopo, não pode ser usado
```

```cpp
#include <iostream>

int adicao(int x, int y)  // x e y entram no escopo, e são usáveis apenas dentro de adicao()
{
    return x + y;
}  // y e x saem do escopo e são destruídos

int main()
{
    int a{ 5 };  // a entra no escopo
    int b{ 6 };  // b entra no escopo

    // a e b são usaveis somente dentro de main()

    std::cout << adicao(a, b) << '\n';

    return 0;
}  // b e a saem do escopo e são destruídos
```

Através do conceito de escopos, podemos criar variáveis com o mesmo nome sem conflitos. Variáveis de escopos diferentes são consideradas variáveis distintas, mesmo que possuam o mesmo nome.

## Local de Declaração de Variáveis Locais

Em C++ moderno, as variáveis locais são recomendadas a serem definidas o mais perto o possível de seu primeiro uso:

```cpp
int main()
{
    std::cout << "Insira um número: ";
    int x{};
    std::cin >> x;

    std::cout << "Insira outro número: ";
    int y{};
    std::cin >> y;

    int soma{ x + y };
    std::cout << "A soma é: " << soma << '\n';

    return 0;
}
```

## Parâmetros de Funções e Variáveis Locais

Quando uma variável é necessária em uma função, temos como opções uma variável local ou um parâmetro.

Use parâmetros quando a chamada de função inclui um valor de inicialização para a variável.

Use uma variável local para outras funcionalidades.

```cpp
int obterValorDoUser()
{
    int val {};
    std::cout << "Insira um valor: ";
    std::cin >> val;
    return val;
}

int main()
{
    int num { obterValorDoUser() };

    std::cout << "O valor inserido foi " << num << '\n';

    return 0;
}
```

Utilizamos apenas variáveis locais no exemplo acima, pois não é necessário usar passagens de valores entre funções.

## Objetos Temporários - Introdução

Um **objeto temporário** (ou **objeto anônimo**) é um objeto sem nome usado para guardar um valor usado por um curto período de tempo. Objetos temporários são gerados pelo compilador quando necessário.

Um dos casos mais comuns de objetos temporários é na exibição de conteúdos:

```cpp
#include <iostream>

int obterValorDoUser()
{
 	std::cout << "Insira um número: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
	std::cout << obterValorDoUser() << '\n';

	return 0;
}
```

No programa acima, a função `obterValorDoUser()` retorna o valor na variável local `input`. No entanto, essa variável será destruída após o fim da função, então a chamada da função recebe uma cópia do valor.

Onde o valor será guardado, se não definimos uma variável para ele? A resposta é que ele será guardado em um objeto temporário, passado para `std::cout`.

Objetos temporários não possuem escopo e são destruídos no final da expressão onde foram criados. No exemplo acima, o objeto temporário criado no `std::cout` será destruído após o fim da execução da linha.

O C++ moderno usa algumas funcionalidades para tentar evitar objetos temporários onde não seria necessário. Por exemplo, quando um valor de retorno é usado para inicializar uma variável, normalmente precisaria de um objeto temporário par guardar o valor e inicializar a variável. No entanto, em versões acima do C++17, o compilador pula a parte do objeto temporário e inicializa a variável com o valor diretamente.