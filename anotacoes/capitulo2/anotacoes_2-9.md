# Colisões de Nomes e Introdução aos Espaços de Nomes

Em C++, todos os identificadores não podem ser ambíguos. Se dois identificadores são introduzidos no mesmo programa de forma que o compilador não consiga separá-los, este irá produzir um erro de **colisão de nomes** (ou **conflito de nomes**).

Se identificadores em colisão são introduzido no mesmo arquivo, o resultado será um erro de compilação. Se os identificadores em conflito são introduzidos em arquivos separados do mesmo programa, o resultado será um erro de ligação.

## Exemplo de Colisão de Nomes

No exemplo a seguir, temos dois arquivos:

a.cpp:

```cpp
#include <iostream>

void minhaFuncao(int x)
{
    std::cout << x;
}
```

main.cpp:
```cpp
#include <iostream>

void minhaFuncao(int x)
{
    std::cout << 2 * x;
}

int main()
{
    return 0;
}
```

Na compilação do programa, ambos arquivos serão analisados independentemente, e cada arquivo irá compilar sem problemas.

No entanto, na ligação entre os arquivos, as definições no *a.cpp* e *main.cpp* serão juntadas, e aqui serão descobertos os conflitos para a função `minhaFuncao()`. O ligador irá abortar com um erro, mesmo sem a chamada da função.

A maioria dos conflitos de colisão acontecem em dois casos:

1. Duas (ou mais) funções (ou variáveis globais) com o mesmo nome são introduzidas em arquivos separados no mesmo programa Isso resulta em um erro de ligação.
2. Duas (ou mais) funções (ou variáveis globais) com o mesmo nome são introduzidas no mesmo arquivo. Isso resulta em um erro de compilação.

Com o crescimento dos programas e o maior uso de identificadores, as chances de uma colisão de nomes também crescem. A bos notícia é que C++ providencia vários mecanismos que evitam conflitos de nomes. Escopo local, que mantém variáveis locais definidas em uma função para evitar conflitos com outras, é um exemplo de mecanismo. Mas, o escopo local não funciona com funções em si.

## Regiões de Escopo

Uma **região de escopo** é uma área do código onde todos os identificadores declarados são considerados distintos dos declarados em outros escopos. Dois identificadores com o mesmo nome podem ser declarados em regiões de escopo diferentes sem causar um conflito de nomes. No entanto, dentro de uma região de escopo, todos os identificadores devem ser únicos.

O corpo de uma função é um exemplo de região de escopo. Dois identificadores com nomes iguais podem ser definidos em funções separadas sem problemas. Entretanto, se tentar definir dois identificadores iguais na mesma função, vai acontecer uma colisão de nomes.

## Espaços de Nomes

Um **espaço de nome** providencia outro tipo de região de escopo que permite declarar ou definir nomes dentro dela para o propósito de não haver ambiguidade. Os nomes declarados em um espaço de nome são isolados de nomes em outros escopos.

Por exemplo, duas funções com declarações idênticas podem ser definidas dentro de espaços de nomes diferentes, e nenhum conflito de nomes irá acontecer.

Espaços de nomes podem conter apenas declarações e definições. Comandos executáveis não são permitidos se não fazem parte de uma definição.

Espaços de nomes são usados para agrupar identificadores relacionados em um projeto largo para ajudar a evitar colisões. Por exemplo, se todas as suas funções matemáticas estão em um espaço de nomes `math`, então elas não irão colidir com funções de mesmo nome fora do espaço `math`.

## O Espaço de Nomes Global

Em C++, qualquer nome não definido dentro de uma classe, função, ou outro espaço de nome é considerado parte do **espaço de nome global** (ou o **escopo global**).

No exemplo da função acima, as funções `main()` e ambas versões da `minhaFuncao()` são definidas dentro do espaço global. A colisão de nomes encontrada acontece porque as duas versões da função estão dentro do espaço global, o que viola a regra que todos os nomes em um escopo devem ser únicos.

```cpp
#include <iostream>

// Todos os comandos a seguir fazem parte do espaço global

void foo();  // declaração a frente de função (ok)
int x;  // variável não global (prática não recomendada)
int y { 5 };  // variável não global (prática não recomendada)
x = 5;  // erro de compilação: comando executável

int main()  // definição de função (ok)
{
    return 0;
}

void goo();  // declaração de função (ok)
```

## Espaço de Nome std

Quando C++ foi originalmente criado, todos os identificadores da biblioteca padrão poderiam ser usados sem o prefixo `std::` (eram parte do espaço global). No entanto, isso significa que qualquer identificador na biblioteca padrão poderia entrar em conflito com qualquer outro nome para seus próprios identificadores. Um código que estava funcionando poderia ter um conflito de nomes ao incluir uma parte diferente da biblioteca padrão. Ou, pior, um código que compilava em uma versão do C++ não iria compilar na outra versão, pois novos identificadores introduzidos na biblioteca padrão poderiam entrar em conflito. Para resolver este problema, C++ moveu toda a funcionalidade na biblioteca padrão para o espaço `std` (abreviação de standart - padrão).

Então, o nome do `std::cout` não é exatamente este. É, na verdade, `cout`, e `std` é o nome do espaço de nomes que ele faz parte.

Existem algumas maneiras de evidenciar ao compilador o espaço de nomes que iremos usar.

### Qualificador de Nomes Explícito

```cpp
#include <iostream>

int main()
{
    std::cout << "Olá, mundo";
    return 0;
}
```

Aqui, usamos o nome do espaço e o **operador de resolução de escopo** `::`, onde o nome à esquerda é o nome do espaço, e à direita temos o que está contido neste espaço.

Quando dizemos `std::cout`, estamos dizendo que queremos usar o `cout` que está dentro do espaço `std`.

Esta é a maneira mais segura, pois não permite ambiguidade.

### Uso de namespace std

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "Olá, mundo";
    return 0;
}
```

Outra maneira é incluir um comando de uso direto, podendo assim usar um espaço de nomes sem incluir sua identificação.

No entanto, esta é uma prática não recomendada, pois aumente a chance de conflitos de nomes. Por exemplo, se temos nossa própria função `cout`, com uma definição diferente, então usar esta função e a `cout` da biblioteca padrão introduziria um conflito de nomes, trazendo um erro de compilação.

## Chaves e Código Identado

Em C++, as chaves são usadas para delinear uma região de escopo aninhada em outra região (além de outros usos, como iniciação por listas). Por exemplo, uma função definida dentro da região global usa chaves para separar a região de scopo da função da região global.

Em certos casos, os identificadores definidos fora das chaves ainda fazem parte do escopo definido pelas chaves -- os parâmetros das funções são um exemplo disso.

```cpp
#include <iostream>

void foo(int x)  // foo definido no escopo global, x definido no escopo de foo()
{  // chaves que delimitam a região aninhada de foo()
    std::cout << x << '\n';
}  // x sai de escopo aqui

int main()
{
    foo(5);

    int x { 6 };  // x definido no escopo de main()
    std::cout << x << '\n';

    return 0;
}  // x sai de escopo aqui
// foo e main (e std::cout) saem de escopo aqui
```