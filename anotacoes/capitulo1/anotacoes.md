# Capítulo 1 - Básicos em C++

O capítulo 1 será focado em tópicos essenciais para todo programa em C++, em nível básico, sendo cada tópico retomado com mais detalhes em momentos posteriores.

## Comandos

Um programa é uma sequência de instruções que dizem ao computador o que se deve fazer. Um **comando** é um tipo de instrução que faz o computador *realizar alguma ação*.

Comandos são o tipo de instrução mais comum em um programa C++, pois são a menor unidade independente de computação. Desse modo, seu uso é parecido com as frases em uma linguagem do mundo real. Quando queremos mostrar uma ideia para outra pessoa, geralmente usamos frases escritas ou faladas. Em C++, quando queremos que nosso programa faça algo, geralmente escrevemos comandos.

A maioria dos comandos em C++ terminam com ponto e vírgula.

Em uma linguagem de alto nível como C++, um único comando pode compilar em várias instruções de linguagem de máquina.

>
> **Para leitores avançados**
>
> Existem vários tipos de comandos em C++:
>
> - Comando de declaração
> - Comando de salto
> - Comando de expressão
> - Comando composto
> - Comando de seleção (condicionais)
> - Comando de iteração (loops)
> - Blocos `try`
>
> Todos estes serão explicados mais a frente.
>

## Funções e a Função `main`

Em C++, comandos tipicamente são agrupados em unidades chamadas funções. Uma **função** é uma coleção de comandos que são executados sequencialmente (de cima para baixo).

>
> **Regra**
>
> Todo programa C++ precisa ter uma função nomeada **main** (letras minúsculas).
>

Quando o programa é executado, os comandos dentro da `main` são executados em ordem.

Programas geralmente terminam (encerram a execução) após o último comando dentro da função `main` ter sido executado (embora programas possam encerrar antes em algumas circunstâncias, ou fazer alguma limpeza ao final).

Funções são escritas para realizar um trabalho específico ou fazer uma ação útil. Por exemplo, uma função nomeada `max` contém comandos para determinar qual de dois números é maior. Uma função nomeada `calcularNota` deve calcular a nota de um aluno baseada em pontuações de testes. Uma função nomeada `exibirFuncionario` imprime no console as informações sobre um funcionário. Mais adiante as funções serão explicadas.

>
> **Nomenclatura**
>
> Discutindo sobre funções, é comum abreviar um par de parênteses ao final do nome de uma função. Por exemplo, se ver o termo `main()` ou `facaAlgo()`, isto é a abreviação de funções chamadas `main` ou `facaAlgo`. Isso ajuda a diferenciar funções de outras coisas nomeadas (como variáveis) sem escrever a palavra "função" toda vez.
>

Em programação, o nome de uma função (ou objeto, tipo, modelo, etc...) é chamado de **identificador**.

## Caracteres e Texto

Os primeiros computadores foram designados para cálculos matemáticos e processamento de dados. Com a evolução do hardware, o networking (contato entre pessoas/máquinas) se tornando mais acessível, e o software consumidor evoluindo, computadores se tornaram também ferramentas valiosa para comunicação escrita.

Na linguagem escrita, a unidade mais básica de comunicação é o caractere. Para simplificar, um **caractere** é um símbolo ou marca escrito, como uma letra, dígito, símbolo de pontuação, ou símbolo matemático. Quando usamos uma tecla alfabética ou numérica, um caractere é produzido como resultado, que pode ser mostrado na tela. Os seguintes símbolos são todos caracteres: `a`, `2`, `$`, e `=`.

Em muitos casos, assim como em escrita de palavras e frases, queremos usar mais de um caractere. Uma sequência de caracteres é chamada de **texto** (também chamada de **string** em contexto de programação).

>
> **Nomenclatura**
>
> Convencionalmente, o termo "texto" também é usado para dizer "texto simples", que é um texto que contém apenas caracteres que apareçam em um teclado comum, sem formatação especial. Por exemplo, textos simples não podem representar palavras em negrito, pois necessitaria de formatação.
>
> Nossos programas em C++ são escritos como textos simples.
>

>
> **Para leitores avançados**
>
> Computadores têm um tipo adicional de caractere, chamado de "caractere de controle". Estes são caracteres que possuem significado especial para o computador, mas não são intencionados para exibição, ou são exibidos como algo além de um símbolo singular visível. Exemplos conhecidos de caracteres de controle são "escape" (que não exibe nada), "tab" (que exibe um número de espaços), e "backspace" (que apaga o caractere anterior).
>

## Analise de Olá mundo!

Agora que temos um breve entendimento de o que são comandos e funções, vamos olhar o exemplo mais simples de programa em C++ e analisar cada parte:

```cpp
#include <iostream>
int main()
{
    std::cout << "Olá, mundo!";
    return 0;
}
```

A primeira linha é uma linha especial chamada de diretiva de pré-processador. Este `#include` indica que utilizaremos os conteúdos da biblioteca `iostream`, que é a parte da biblioteca padrão de C++ que permite a escrita e leitura de texto do console e para o console. Precisamos desta linha para poder usar `std::cout` na linha 5, e excluir esta linha irá resultar em um erro, pois o compilador não saberá o que é `std::cout`.

A segunda linha é vazia, e ignorada pelo compilador. Esta linha existe para deixar o programa mais legível para humanos.

A terceira linha diz ao compilador que iremos escrever (definir) uma função cujo nome (identificador) é `main`. Como dito antes, todo programa C++ precisa de uma função `main`. Esta função irá produzir um valor do tipo `int` (um inteiro).

As linhas 4 e 7 dizem ao compilador quais linhas fazem parte da função *main*. Tudo que está dentro da abertura de chave na linha 4 e da fecha de chave na linha 7 é considerado parte da função `main`. Isso é chamado de corpo da função.

A quinta linha é o primeiro comando na função `main`, e o primeiro comando lido quando executamos o programa. `std::cout` (que significa "character output", ou saída de caractere) e o operador `<<` nos permitem mostrar informação no console. Neste caso, estamos exibindo o texto `"Olá, mundo!"`. Este comando cria a saída visível do programa.

A sexta linha é um comando de retorno. Quando um programa executável encerra, o programa envia um valor de volta ao sistema operacional para indicar se sua execução foi feita com sucesso ou não. Este comando de retorno específico retorna o valor inteiro `0` para o sistema operacional, o que significa "tudo ocorreu bem!". Este é o último comando em um programa executável.

Todos os programas a serem criados seguirão este modelo ou uma variação deste.

Compilando e executando o programa, verá que será exibida a seguinte informação no console:

```
Olá, mundo!
```

## Sintaxe e Erros de Sintaxe

Na linguagem do Português Brasileiro, frases são construídas de acordo com certas regras gramaticais que são ensinadas na matéria de Português nas escolas. Por exemplo, frases comuns são encerradas por um ponto final. Este conjunto de regras que descreve como certas palavras (e pontuação) são organizadas para formar frases válidas em uma linguagem é chamado de **sintaxe**. Por exemplo, "Minha pintada casa é azul" é um erro de sintaxe, porque a ordem das palavras é inconvencional. "Toda a sua base é pertence a nós!" é outro erro notável.

A linguagem de programação C++ também tem uma sintaxe, que descreve como os elementos do programa devem ser escritos e organizados para que o programa seja considerado válido. Quando um programa compila, o compilador é responsável por ter certeza de que o programa siga as regras de sintexe. Se seu programa faz algo que não se adequa à sintaxe da linguagem, o compilador irá parar a compilação e retornar Um *_erro de sintaxe*.

As regras de sintaxe do C++ são estritamente definidas. Erros deste tipo são comuns. Felizmente, estes erros são fáceis de encontrar e corrigir, pois o compilado mostra onde estão. A compilação de um programa irá completar somente se todos os erros de sintaxe forem resolvidos.

Já que a sintaxe da maioria dos comandos ordena um ponto e vírgula ao final, vamos ver o que ocorre na omissão deste símbolo no programa:

```cpp
#include <iostream>
int main()
{
    std::cout << "Olá, mundo!"
    return 0;
}
```

Dependendo do programa de compilação, teremos resultados com uma leve diferença, mas apontando para o mesmo erro.

A compilação com Clang irá retornar a seguinte mensagem de erro:

```
prog.cc:5:31: error: expected ';' after expression
```
(Tradução -> erro: ';' esperado após expressão)

Clang nos disse que, na linha 5, no 31º caractere, a regra de sintaxe necessita de um ponto e vírgula, mas não providenciamos um.

A compilação com Visual Studio produz o seguinte erro>

```
hello.cpp(6): error C2143: syntax error : missing ';' before 'return'
```
(Tradução -> erro C2143: erro de sintaxe: ';' faltando antes de 'return')

O Visual Studio mostra o erro na linha 6, que é a linha compilada quando o erro ocorreu.

---

## Comentários

Um **comentário** é uma nota inserida diretamente no código-fonte do programa. Comentários são ignorados pelo compilador e são apenas para uso do programador.

Em C++, existem dois estilos de comentários, ambos servindo para o mesmo propósito: ajudar programadores a documentar o código de alguma forma.

### Comentários de Linha Única

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

### Comentários de Várias Linhas

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

### Uso dos Comentários

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

### Código para Comentário

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

1. Você está trabalhando