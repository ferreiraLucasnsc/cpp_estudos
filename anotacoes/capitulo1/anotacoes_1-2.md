# Comentários

Um **comentário** é uma nota inserida diretamente no código-fonte do programa. Comentários são ignorados pelo compilador e são apenas para uso do programador.

Em C++, existem dois estilos de comentários, ambos servindo para o mesmo propósito: ajudar programadores a documentar o código de alguma forma.

## Comentários de Linha Única

O símbolo `//` inicia um comentário de uma linha em C++, o que informa o compilador a ignora tudo do símbolo `//` até o fim da linha. Por exemplo:

```cpp
std::cout << "Olá mundo!" // Tudo daqui até o final da linha será ignorado
```

Geralmente, comentários de linha única são usados para fazer um comentário pequeno sobre uma linha única de código.

Colocar comentários ao final da linha podem fazer ambos código e comentários ficarem difíceis de serem lidos, particularmente se a linha for mais longa:

```cpp
std::cout << "Olá mundo!\n"; // std::cout está na biblioteca iostream
std::cout << "É muito bom te conhecer\n"; // estes comentários fazem o código ficar mais difícil de ler
std::cout << "É mesmo!\n"; // com essas linhas de tamanhos diferentes
```

Se as linhas forem menores, os comentários podem ser alinhados:

```cpp
std::cout << "Olá mundo!\n";                        // std::cout está na biblioteca iostream
std::cout << "É muito bom te conhecer\n";           // isso é bem mais fácil de ler
std::cout << "É mesmo!\n";                          // não acha?
```

Se as linhas forem maiores, no entanto, os comentários de linha única geralmente são colocados acima da linha sobre o qual está comentando:

```cpp
// std::cout está na biblioteca iostream
std::cout << "Olá mundo!\n"; 

// isso é bem mais fácil de ler
std::cout << "É muito bom te conhecer\n"; 

// não acha?
std::cout << "É mesmo!\n"; 
```

## Comentários de Várias Linhas

O par de símbolos `/*` e `*/` denotam um comentário multi-linha no estlo C. Tudo entre o símbolo será ignorado.

```cpp
/* Esse é um comentário multi-linha.
   Essa linha será ignorada.
   E esta também */
```

Alguns programadores adicionam mais símbolos ao comentário de muitas linhas:

```cpp
/* Esse é um comentário multi-linha
 * Os asteriscos à esquerda
 * podem tornar o comentário mais fácil
 * para ler.
*/
```

Comentários multi-linha não podem ser aninhados:

```cpp
/* Esse é um comentário /* multi-linha */ isso não está dentro do comentário */
// O comentário acima termina no primeor */, e não no segundo */
```

## Uso dos Comentários

Geralmente, comentários devem ser usados para três coisas. Primeiro, para uma determinada biblioteca, programa, ou função, comentários são usados para descrever *o que* a bibloteca, programa ou função faz. Estes são colocados no topo do arquivo ou biblioteca, ou imediatamente precedem a função. Por exemplo:

```cpp
// Esse programa calcula a nota final do estudante baseado em seus testes e pontuações.
```

```cpp
// Essa função usa o método de Newton para aproximar a raíz de certa equação.
```

```cpp
// As linhas a seguir geram um item aleatório baseado na raridade, nível, e um fator de peso.
```

Todos esses comentários dão ao leitor uma boa ideia do que a biblioteca, programa ou função está tentando realizar sem ter que olhar no código. O usuário (possivelmente outro alguém, ou você mesmo se estiver reutilizando código que previamente escreveu) pode entender se o código é relevante ao que está tentando fazer. Isso é particularmente importante quando se está trabalhando em uma equipe, onde nem todos estarão familiarizados com seu código.

Segundo, *dentro* de uma biblioteca, programa, ou função, comentários podem ser usados para descrever *como* o código irá realizar sua função.

```cpp
/* Para calcular a nota final, somamos todas as pontuações com peso dos testes de meio de curso e dos deveres de casa
e então dividimos pelo número de testes para assinalar uma porcentagem, que é
usada para calcular uma nota final. */
```

```cpp
// Para gerar um item aleatório, vamos fazer o seguinte:
// 1) Colocar todos os itens de determinada raridade em uma lista
// 2) Calcular a probabilidade para cada item baseado em nível e fator de peso
// 3) Escolher um número aleatório
// 4) Descobrir a qual item o número aleatório corresponde
// 5) Retornar o item apropriado
```

Esses comentários dão ao usuário uma ideia de como o código irá realizar seu propósito sem ter que entender o que cada linha individual do comentário faz.

Terceiro, no nível do comando, comentários devem descrever o *porquê* do código estar fazendo algo. Um comentário ruim explica *o que* o comentário está fazendo. Se for escrever um código tão complexo que precisa de escrever *o que* está fazendo, é melhor reescrever seu comando.

Este é um comentário ruim:

```cpp
// Calcula o custo dos items
custo = quantidade * 2 * precoLoja;
```

Razão: podemos ver que isto é um cálculo de custo, mas por que a quantidade é multiplicada por 2?

Este é um comentário bom:

```cpp
// Multiplicamos a quantidade por 2 porque este item é comprado em pares
custo = quantidae * 2 * precoLoja;
```

Programadores muitas vezes precisam decidir entre resolver um problema de uma maneira ou de outra. Comentários são uma boa forma de se lembrar (ou dizer para alguém) o motivo da decisão.

```cpp
// Decidimos usar o método de Newton para encontrar a raíz de um número porque não há maneira deterministica para resolver estas equações.
```

Finalmente, comentários devem ser escritos de uma forma que faça sentido para quem não tem ideia do que o código faz.

## Código para Comentário

Converter uma linha de código ou mais para um comentário é uma maneira conveniente de (temporariamente) excluir partes do seu código de serem incluidas na compilação do seu programa.

```cpp
std::cout << 1;
std::cout << 2;
std::cout << 3;
```

```cpp
// std::cout << 1;
// std::cout << 2;
// std::cout << 3;
```

Existem algumas razões de o porquê é bom fazer isso:

1. Você está trabalhando em um novo pedaço de código que ainda não será compilado, e precisa rodar o programa. O compilador não irá deixar compilar o código se houverem erros de compilação. Transformar o código que não compila em comentário permite que o programa seja compilado e executado. Quando estiver pronto, pode voltar o código ao normal e trabalhar nele.
2. Você escreveu novo código que compila, mas se comporta de maneira inesperada, e não há muito tempo para consertar até mais tarde. Comentar o código quebrado irá garantir que este não seja executado e não cause problemas até quando puder ser consertado.
3. Para encontrar a origem de um erro. Se um programa não está produzindo os resultados esperados, algumas vezes pode ser útil desabilitar partes do código para tentar isolar o que está causando o erro.
4. Você deseja trocar um código por outro. Ao invés de deletar o código original, você pode comentá-lo e deixá-lo lá para referência. Quando tiver certeza de que o novo código está funcionando, você pode remover o código comentado.

Transformar uma porção de código em comentário é algo tão comum, que muitos IDEs possuem funcionalidades para esta função.