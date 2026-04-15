# Introdução a Parâmetros e Argumentos

Vamos voltar para o exemplo passado de funções:

```cpp
#include <iostream>

int obterValorDoUser()
{
 	std::cout << "Insira um inteiro: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
	int num { obterValorDoUser() };

	std::cout << num << " em dobro é: " << num * 2 << '\n';

	return 0;
}
```

Se quisermos que a parte de exibição faça parte de uma função separada, poderiamos tentar o seguinte:

```cpp
#include <iostream>

int obterValorDoUser()
{
 	std::cout << "Insira um inteiro: ";
	int input{};
	std::cin >> input;

	return input;
}

void exibirMultiplicacao()
{
    std::cout << num << " em dobro é: " << num * 2 << '\n';
}

int main()
{
	int num { obterValorDoUser() };

	exibirMultiplicacao();

	return 0;
}
```

O programa acima não irá compilar, pois a função `exibirMultiplicacao` não sabe o que o identificador `num` é. Embora podemos definir a variável dentro da função, ainda teremos o problema da variável ter o valor 0. Precisamos de uma maneira de fazer com que o valor inserido na função `obterValorDoUser` passe para a função `exibirMultiplicacao`.

## Parâmetros e Argumentos de Função

Em vários casos, é útil passar informações para uma função sendo chamada, para que esta possa tratar os dados. Para isso, usamos argumentos e parâmetros.

Um **parâmetro de função** é uma variável usada no cabeçalho da função, e funcionam de forma semelhante a variáveis comuns, com a diferença que sua inicialização ocorre com o valor providenciado na chamada da função.

```cpp
void impressao()
{
    std::cout << "Dentro de impressao()\n";
}

void imprimirValor(int x)
{
    std::cout << x << '\n';
}

int adicao(int x, int y)
{
    return x + y;
}
```

Enquanto a primeira função não possui parâmteros, a segunda recebe um parâmetro (a variável `int` `x`, usada dentro da função), e a terceira recebe dois parâmetros (as variáveis `int` `x` e `y`, usadas dentro da função).

Enquanto o parâmetro é usado no cabeçalho da função para a criação da variável, o **argumento** é o valor passado por quem chama a função:

```cpp
impressao();  // não necessita de argumento
imprimirValor(6);  // 6 passado para int x em imprimirValor()
adicao(2, 3);  // 2 e 3 passados para int x e y em adicao()
```

Quando uma função é chamada, todos os parâmetros da função são criados como variáveis, e o valor de cada argumento é *copiado* para o parâmetro (uso de inicialização por cópia). Este processo é conhecido por **passagem por valores**.

Então, agora, podemos consertar nosso programa inicial:

```cpp
#include <iostream>

int obterValorDoUser()
{
 	std::cout << "Insira um inteiro: ";
	int input{};
	std::cin >> input;

	return input;
}

void exibirMultiplicacao(int valor)
{
    std::cout << valor << " em dobro é: " << valor * 2 << '\n';
}

int main()
{
	int num { obterValorDoUser() };

	exibirMultiplicacao(num);

	return 0;
}
```

Agora, a variável `num` é inicializada com o valor inserido pelo usuário (função `obterValorDoUser`). Então, a função `exibirMultiplicacao` é chamada, e o valor do argumento `num` é copiado para o parâmetro `valor` da função `exibirMultiplicacao`, que utiliza o valor deste parâmetro.

Para tornar o código ainda mais eficiente, podemos usar o valor do retorno da primeira função como o parâmetro da segunda função:

```cpp
#include <iostream>

int obterValorDoUser()
{
 	std::cout << "Insira um inteiro: ";
	int input{};
	std::cin >> input;

	return input;
}

void exibirMultiplicacao()
{
    std::cout << num << " em dobro é: " << num * 2 << '\n';
}

int main()
{
	int num { obterValorDoUser() };

	exibirMultiplicacao(obterValorDoUser());

	return 0;
}
```

Para entender melhor como retornos e parâmetros trabalham juntos, vamos analisar a série seguinte de chamadas de funções:

```cpp
#include <iostream>

int adicao(int x, int y)
{
    return x + y;
}

int multiplicacao(int z, int w)
{
    return z * w;
}

int main()
{
    std::cout << adicao(4, 5) << '\n';
    std::cout << adicao(1 + 2, 3 * 4) << '\n';

    int a{ 5 };
    std::cout << adicao(a, a) << '\n';

    std::cout << adicao(1, multiplicacao(2, 3)) << '\n';
    std::cout << adicao(1, adicao(2, 3)) << '\n';

    return 0;
}
```

Vamos analisar cada chamada à função `adicao`:

1. `adicao(4, 5)`: o valor 4 é copiado para o parâmetro `int x`, e o valor 5 é copiado para o parâmetro `int y`.
2. `adicao(1 + 2, 3 * 4)`: a primeira expressão (1 + 2) resulta 3, que é enviado para o primeiro parâmetro. A segunda expressão (3 * 4) resulta 12, que é enviado para o segundo parâmetro.
3. `adicao(a, a)`: ambos argumentos são o valor da variável `a`, que é 5.
4. `adicao(1, multiplicacao(2, 3))`: o primeiro argumento é o valor 1. O segundo argumento, no entanto, é o retorno da função `multiplicacao` com seus próprios argumentos 2 e 3. O retorno da função `multiplicacao` será 6, e este valor será usado como segundo argumento da função `adicao`.
5. `adicao(1, adicao(2, 3))`: o primeiro argumento é 1. O segundo argumento é o retorno de uma segunda função `adicao`, com os argumentos 2 e 3. O retorno da segunda `adicao` será 5, que será o segundo argumento da primeira `adicao`.

## Parâmetros sem Referência e Parâmetros sem Nome

Em certos casos, funções podem aparecer com parâmetros que não foram usados no corpo da função. Estes são **parâmetros sem referência**.

```cpp
void facaAlgo(int count)
{
    // esta função não utiliza o parâmetro count
}

int main()
{
    facaAlgo(4);
}
```

Na definição de uma função, o nome de um parâmetro é opcional. Logo, em casos onde o parâmetro precisa existir mas não é usado no corpo da função, é Temos assim um **parâmetro sem nome**.

```cpp
void facaAlgo(int)
{
}
```