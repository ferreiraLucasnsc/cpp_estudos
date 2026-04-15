# Declarações e Definições à Frente

Veja o seguinte código:

```cpp
#include <iostream>

int main()
{
    std::cout << "A soma de 3 e 4 é: " << adicao(3, 4) << '\n';
    return 0;
}

int adicao(int x, int y)
{
    return x + y;
}
```

Embora seja semelhante aos programas utilizando funções normalmente, este código não irá compilar!

A razão disso é que, como o compilador analisa os conteúdos sequencialmente, a chamada à função `adicao` não é entendida porque não definimos a função anterior à chamada.

Para resolver esse problema, devemos resolver o fato que o compilador não sabe o que a função `adicao` é. Para isso, temos duas formas de resolver este problema.

## Opção 1: Reordenar as definições de funções

```cpp
#include <iostream>

int adicao(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << "A soma de 3 e 4 é: " << adicao(3, 4) << '\n';
    return 0;
}
```

A primeira forma é trazer a função para antes da chamada. Embora isso resolva o problema, em um código maior, reorganizar todas as funções será um trabalho mais difícil, ainda mais se algumas funções possuem dependem de outras funções.

Por exemplo, temos duas funções *A* e *B*. Se a função *A* chama a função *B*, e a função *B* chama a função *A*, não haverá jeito de resolver esse problema. Se *A* for definida primeiro, o compilador não saberá o que *B* é. E, se *B* for definida primeiro, o compilador não saberá o que *A* é;

## Opção 2: Usar uma Delcaração à Frente

Uma **declaração à frente** nos permite dizer ao compilador sobre a existência de um identificador *antes* da sua definição. Para as funções, isso permite que o compilador saiba da existência da função antes da definição de seu corpo. Dessa forma, quando o compilador encontrar uma chamada para a função, entenderá a chamada e irá buscar a função correta, mesmo que ainda não saiba como ou onde a função foi definida.

Para escrever uma declaração à frente de uma função, usamos um comando de **declaração de função**, mostrando o tipo de retorno, nome e parâmetros, sem incluir o corpo dela:

```cpp
int adicao(int x, int y);
```

Agora, vamos utilizar o mesmo programa, que não compilava, e utilizar este tipo de declaração:

```cpp
#include <iostream>

int adicao(int x, int y);

int main()
{
    std::cout << "A soma de 3 e 4 é: " << adicao(3, 4) << '\n';
    return 0;
}

int adicao(int x, int y)
{
    return x + y;
}
```

Dessa vez, o compilador irá entender, na chamada da função, que a função `adicao` existe!

Devemos lembrar também que as declarações de função não precisam de nomes para os parâmetros. Então, podemos declarar também a função como:

```cpp
int adicao(int, int);
```

No entanto, é melhor manter os nomes, para entendermos o que são os parâmetros ao olharmos para a declaração.

## Motivo do uso de Declarações à Frente

Em muitas vezes, declarações à frente são usadas para dizer ao compilador sobre a existência de uma função definida em um arquivo diferente. E não será possível reordenar nesse cenário, já que a chamada às funções e as funções em si estão em arquivos diferentes!

As declarações à frente também são usadas para definir nossas funções de uma maneira mais livre, permitindo definir funções em uma ordem que seja melhor para organização, como deixar funções relacionadas mais próximas.

## Declarações e Definições

Uma **declaração** diz ao compilador sobre a *existência* de um identificador e seu tipo associado.

```cpp
int adicao(int x, int y);
int x;
```

Uma **definição** é uma declaração que implementa (para funções e tipos) ou instancia (para variáveis) o identificador.

```cpp
int adicao(int x, int y)
{
    int z{ x + y };

    return z;
}

int x;
```

Em C++, todas as definições são declarações, então `int x;` é uma definição e uma declaração. Mas, nem todas as declarações são definições. Declarações que não são definições são chamadas de **declarações puras**, e essas incluem declarações à frente para funções, variáveis e tipos.

Quando o compilador encontra um identificador, ele irá verificar se o uso daquele verificador é válido (se o identificador está dentro do escopo, se foi usado corretamente pela sintaxe, etc...).

Em muitos casos, uma declaração é suficiente para o compilador garantir o uso de um identificador. No entanto, existem casos onde o compilador precisa ver a definição completa para usar o identificador (como em definições de modelos e tipos).

Resumindo:

| Termo | Significado Técnico | Exemplos |
| ----- | ------------------- | -------- |
| Declaração | Diz ao compilador sobre um identificador e seu tipo associado | `void foo();` `void goo();` `int x;` |
| Definição | Implementa uma função ou instancia uma variável. Definições também são declarações. | `void foo() {};` `int x;` |
| Declaração pura | Uma declaração que não é uma definição | `void foo();` |
| Inicialização | Providencia um valor inicial para um objeto definido | `int x { 2 };` |

## Regra de Uma Definição (ODR)

A **regra de uma definição** é uma regra conhecida em C++, e possui três partes:

1. Em um *arquivo*, cada função, variável, tipo, ou modelo em certo escopo, pode ter apenas uma definição. Definições em escopos diferentes (como variáveis locais de escopos diferentes, ou funções definidas em namespaces distintos) não violam esta regra
2. Em um *programa*, cada função ou variável em certo escopo pode ter apenas uma definição. Essa regra existe porque programas podem ter mais de um arquivo. Funções e variáveis não visíveis ao conector são excluídas desta regra
3. Tipos, modelos, funções inline e variáveis inline podem ter definições duplicadas em arquivos diferentes, enquanto cada definição for idêntica.