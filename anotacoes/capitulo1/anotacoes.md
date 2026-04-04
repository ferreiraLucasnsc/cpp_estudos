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

# Perguntas e Respostas

1. O que é um Comando?
    > Um comando é uma instrução em um programa de computador que diz ao computador para realizar uma ação.

2. O que é uma Função
    > Uma função é uma coleção de comandos que executam sequencialmente.

3. Qual é o nome da função que todos programas devem ter?
    > `main`

4. O que acontece