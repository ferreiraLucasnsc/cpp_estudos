# Atribuição e Inicialização de Variável

## Atribuição de Variável

Depois que uma variável foi definida, você pode atribuir um valor (em um comando separado) usando o operador `=`. Esse processo é chamado de **atribuição**, e o operador `=` é chamado de **operador de atribuição**.

```cpp
int largura;    // define uma variável inteira chamada largura
largura = 5.    // atribuição do valor 5 na variável largura

// a variável largura agora possui o valor 5
```

Por padrão, a atribuição copia o valor à direita do operador para a variável ao lado esquerdo. Isso é chamado de **atribuição de cópia**.

Quando uma variável recebe um valor, esse valor pode ser exibido, através de `std::cout` e do operador `<<`.

A atribuição também pode ser usada para mudar o valor de uma variável:

```cpp
#include <iostream>

int main() {
    int largura;
    largura = 5;

    std::cout << largura;   // imprime 5

    largura = 7;            // muda o valor da variável para 7

    std::cout << largura;   //imprime 7

    return 0;
}
```

A impressão final será:

```console
57
```

Como a ordem de execução do programa é de cima para baixo, a sequência de comandos é a seguinte:

1. Alocação de memória para a variável `largura`
2. Atribuição do valor `5` para a variável `largura`
3. Exibição do valor de `largura` -> `5`
4. Atribuição do valor `7` para a variável `largura`
5. Exibição do valor de `largura` -> `7`

Variáveis comuns guardam um valor por vez.

> **Aviso**
>
> Um dos erros mais comuns é a confusão entre o operador de atribuição (`=`) e o operador de igualdade (`==`). Atribuição (`=`) é usada para atribuir um valor para uma variável. Igualdade (`==`) é usada para testar se dois operandos são iguais em valor.

## Inicialização de Variáveis

A forma anterior de atribuir um valor a uma variável necessita de dois comandos: um para criar a variável, e outro para o valor.

Podemos combinar estes dois comandos. Quando um objeto é definido, é possível providenciar um valor inicial, em um processo chamado de **inicialização**, e a sintaxe usada para inicializar um objeto é conhceida por **inicializador**.

Por exemplo, o comando a seguir define uma variável `largura` (de tipo `int`) e inicializa-a com o valor `5` na mesma linha:

```cpp
#include <iostream>

int main() {
    int largura { 5 };      // define a variável largura e inicializa-a com o valor inicial 5
    std::cout << largura;   // exibe 5
}
```

## Formas de Inicialização

A inicialização em C++ é mais complexa do que aparenta-se. Existem cinco formas comuns de inicialização:

1. Sem inicialização:
    ```cpp
    int a;
    ```
2. Tradicional por cópia (operador =):
    ```cpp
    int b = 5;
    ```
3. Tradicional direta (parênteses):
    ```cpp
    int c ( 6 );
    ```
4. Moderna por lista direta (chaves):
    ```cpp
    int d { 7 };
    ```
5. Moderna por valor (colchetes vazios):
    ```cpp
    int e {};
    ```

### Sem inicialização

Sem a inicialização, o valor de uma variável não é definido, trazendo um valor imprevisível, muitas vezes chamado de "valor de lixo".

### Inicialização Tradicional por Cópia

A inicialização tradicional por cópia vem da linguagem C. O valor à direita do operador é copiado para a variável no lado esquerdo.

Em versões modernas de C++, este método não é muito utilizado, por ser menos eficiente do que outras formas para tipos complexos. Entretanto, C++17 conseguiu resolver a maioria destes problemas, então este método possui algum uso. Além disso, programadores que migraram da linguagem C utilizam bastante essa forma.

### Inicialização Tradicional Direta

A inicialização direta permite uma inicialização mais eficiente de objetos complexos, como classes. Assim como a tradicional por cópia, a inicialização tradicional direta caiu em desuso em C++ moderno, mais pela substituição por inicializações de lista direta.

### Inicialização por Lista

A forma mais moderna de incializar objetos em C+++ é utilizar uma lista, definida por chaves.

Antes do C++11, alguns tipos de inicialização necessitavam da forma por cópia, e outros tipos necessitavam da forma direta. Ambas atribuição e inicialização por cópia utilizam o mesmo operador, então são difíceis de serem identificadas. E a inicialização direta utiliza parênteses, assim como funções.

A sintaxe da inicializaçao por lista foi introduzida para funcionar em vários casos e trazer um fim para a ambiguidade.

Além disso, a inicialização por lista traz uma forma de inicializar objetos que necessitam de uma lista de valores.

#### Inicialização por Lista - Conversões de Precisão

Um dos maiores benefícios da inicialização por lista é que a "conversão de precisão" é desabilidade. Isso significa que ao tentar inicializar por lista uma variável usando um valor que a variável não pode guardar, o compilador é obrigado a produzir um erro ou aviso:

```cpp
int main() {
    int w1 { 4.5 };
    int w2 = 4.5;
    int w3 (4.5);
}
```

No exemplo acima, temos as variáveis `w1`, `w2`, e `w3`, cada uma com um tipo de inicialização diferente, mas todas do tipo inteiro, ou seja, não guardam valores decimais.

As variáveis `w2` e `w3` usam métodos de inicialização que permitem o arredondamento de valores decimais ao guardá-los em variáveis inteiras. Nesse caso, o valor guardado em ambas é o valor `4`, e o decimal `.5` é descartado, o que pode significar perda de dados.

Por sua vez, a primeira variável `w1` utiliza um método de inicialização que não permite este arredondamento. Então, neste caso, ao invés de guardar o valor `4`, o compilador irá retornar um erro.

#### Inicialização por Valor - Inicialização por Zero

Quando uma variável é inicializada usando um par vazio de chaves, uma forma especial da inicialização por lista chamada de **inicialização por valor** acontece. Em muitos casos, a inicialização por valor irá, por implícito, inicializar a variável para zero, ou o valor mais perto de zero para o tipo. Nos casos do zero tomando lugar do valor, o nome da inicialização é **inicialização por zero**.

```cpp
int largura {}; // inicialização por valor / inicialização por zero para valor 0
```

> **Tópico Avançado**
>
> A inicialização por valor em classes pode inicializar o objeto para valores predeterminados, diferentes de zero.

### Método mais Recomendado em C++ Moderno

A inicialização por lista (e a inicialização por valor) é a forma de inicialização mais recomendada do que as outras formas, por ser mais consistente em seu funcionamento, por desabilitar o arredondamento de valores, e por permitir inicialização com uma lista de valores.

O próprio Bjarne Stroustrup (criador de C++) e também Herb Sutter (expert em C++) recomendam a inicialização por lista.

## Inicialização de Múltiplas Variáveis

Da mesma forma que podemos definir muitas variáveis *do mesmo tipo* em uma linha, podemos inicializar múltiplas variáveis na mesma linha:

```cpp
int a = 5, b = 6;
int c ( 7 ), d ( 8 );
int e { 9 }, f { 10 };
int i {}, j {};
```

Para inicializar variáveis com o mesmo valor, ambas precisam mencionar este valor:

```cpp
int a, b = 5;       // errado: a não é inicializada para 5
int a = 5, b = 5;   // correto: a e b são inicializadas para 5
```

## Variáveis Não Usadas

A maioria dos compiladores retorna erros ou avisos para a presença de variáveis inicializadas, mas que não possuem nenhum uso, nem mesmo para exibição.

Para resolver esta questão, podemos:

1. Remover a definição da variável
2. Usá-la em outro lugar
3. Usar o atributo `[[maybe_unused]]` (C++17):
    ```cpp
    [[maybe_unused]] double pi { 3.14159 };
    ```