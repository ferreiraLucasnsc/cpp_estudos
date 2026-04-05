# Introdução a Objetos e Variáveis

## Dados e Valores

A maioria das instruções em um programa são, e que funções são agrupamentos de comandos. Os comandos em uma função executam ações para gerar o resultado designado ao programa.

Mas, como os programas produzem resultados? Isso acontece através da manipulação (leitura, mudança e escrita) de dados. Em computação, **dados** são qualquer informação que possa ser movida, processada ou armazenada em um computador.

Um programa pode obter dados para trabalhar em diversas formas: vindo de um arquivo ou base de dados, de uma conexão de rede, de um usuário através de inserção, ou de um programador inserindo dados diretamente no código-fonte do programa. No exemplo do programa "Olá mundo", o texto "Olá, mundo!" foi colocado diretamente no código, providenciando dados para que o programa possa usar. O programa então manipula estes dados, enviando-os ao monitor para serem exibidos.

Em programação, uma unidade de dados é chamada de **valor** (chamada em alguns casos de **valor de dado**). Exemplos comuns de valores são:

- Números (ex.: `5` or `-6.7`)
- Caracteres, que são colocados em aspas simples (ex.: `'H'` ou `'$'`). Apenas um símbolo pode ser usado
- Texto, que é colocado entre aspas duplas (ex.: `"Olá"` ou `"H"`). Um texto pode conter nenhum ou vários caracteres

Valores que são inseridos diretamente no código-fonte são chamados de **literais**.

Uma das ações mais comuns a se tomar com valores é exibir estes na tela. Por exemplo:

```cpp
#include <iostream>

int main() {
    std::cout << 5;         // imprime o número literal '5'
    std::cout << -6.7;      // imprime o número literal '-6.7'
    std::cout << 'H';       // imprime o caractere literal 'H'
    std::cout << "Olá";     // imprime o texto literal "Olá"

    return 0;
}
```

Se um valor de caractere ou de texto não for sinalizado corretamente, o compilador irá tentar interpretar este valor como se fosse um código C++, o que quase sempre resulta em um erro de compilação.

As literais são a forma mais simples de providenciar valores para seu programa, mas elas possuem suas limitações. Literais podem somente serem lidas, então seus valores não podem ser modificados. Logo, se queremos armazenar dados em memória, precisamos fazer isso de outra forma.

## Memória de Acesso Aleatório

A memória principal de um computador é chamada de **Memória de Acesso Aleatório** (muitas vezes abreviada para **RAM** (*Random Access Memory*)). Quando executamos um programa, o sistema operacional carrega o programa na RAM. Qualquer dado que estiver no código do programa é carregado nesse ponto.

O sistema operacional também reserva uma RAM adicional para o programa usar enquanto está rodando. Usos comuns desta memória são armazenar valores do usuário, armazenar dados lidos de um arquivo ou rede, ou guardar valores calculados enquanto o programa roda (ex.: a soma de dois valores), para que sejam usados mais tarde.

Imagine a RAM como uma série de caixas numeradas que podem guardar dados enquanto o programa está em execução.

Em linguagens de programação mais antigas (como Applesoft BASIC), é possível acessar diretamente essas caixas (ex.: é possível escrever um comando para "pegar o valor armazenado na caixa de memória de número 7532").

## Objetos e Variáveis

Em C++, acesso direto à memória não é encorajado. Ao invés disso, acessamos a memória de forma indireta, através de um objeto. Um **objeto** representa uma região de armazenamento (geralmente um registro RAM ou CPU) que pode guardar um valor.

Como o compilador e o sistema operacional trabalham para assinalar memória a objetos será explicado fora desta lição. O conceito chave é que, ao invés de comandar "obter o valor guardado no espaço de memória 7532", podemos comandar "obter o valor guardado neste objeto" e deixar o compilador entender onde e como obter esse valor, e então podemos focar em usar objetos para guardar e obter valores, e não no local da memória onde os objetos estão.

Embora objetos em C++ possam funcionar sem nome, é muito mais comum nomear os objetos usando um identificador. Um objeto com um nome é chamado de **variável**.

> **Detalhes**
>
> - Um objeto é usado para guardar um valor em memória. Uma variável é um objeto que possui um nome (identificador). Nomear os objetos nos permite usá-los novamente no programa.
> - No contexto geral de programação, um *objeto* se refere à um objeto sem nome, uma variável ou uma função. Em C++, este termo possui uma definição mais específica que exclui funções. Durante as anotações, o termo objeto possuirá a definição no contexto de C++.

## Definição de Variável

Para usar uma variável em nosso programa, precisamos dizer ao compilador que desejamos uma. A maneira mais comum é usar um tipo especial de comando chamado de **definição**.

Aqui está um exemplo de definição de uma variável chamada `x`:

```cpp
int x;      // define uma variável chamada x (de tipo int)
```

No momento de compilação (quando o programa está sendo compilado), ao encontrar este comando, o compilador se lembra que desejamos uma variável com o nome `x`, e que a variável possui o tipo `int`. Deste ponto adiante, quando usarmos o identificador `x`, o compilador saberá que nos referimos à esta variável.

Uma variável criada por declaração é dita a ser **declarada** no ponto onde o comando está. Até o momento, as variáveis devem estar dentro de funções (como a `main()`).

```cpp
int main() {
    int x;          // definição da variável x

    return 0;
}
```

## Criação de Variável

No momento de execução (quando o programa é carregado na memória e rodado), cada objeto recebe um local de armazenamento (como um registro de RAM ou CPU) usado para guardar valores. O processo de reservar armazenamento para o uso de um objeto é chamado de **alocação**. Quando a alocação ocorre, o objeto foi criado e pode ser usado.

Por exemplo, digamos que a variável `x` foi instanciada no local de memória 140. Quando o programa usar a variável `x`, irá acessar o valor no local de memória 140.

## Tipos de Dados

Até agora, falamos sobre os objetos serem regiões de armazenamento para guardar um valor de dado. Um **tipo de dado** (abreviado para **tipo**) determina qual tipo de valor (ex.: um número, uma letra, um texto, etc...) o objeto irá guardar.

No exemplo anterior, nossa variáve `x` recebeu o tipo `int`, o que significa que a variável `x` irá armazenar um valor inteiro. Um **inteiro** é um número escrito sem um componente decimal, como `4`, `27`, `0 `, `-2`, ou `-12`.

Em C++, o tipo de um objeto prexisa ser reconhecido no tempo de compilação, e esse tipo não pode ser modificado sem a recompilação do programa. Isso significa que uma variável inteira pode guardar apenas valores inteiros. Se quiser guardar outro tipo de valor, será necessário outro tipo.

Inteiros são apenas um dos diversos tipos que C++ suporta. Existem outros diversos tipos de dados, e até mesmo a possibilidade de criar seus próprios tipos de dados.

## Definindo várias Variáveis

É possível definir muitas variáveis *do mesmo tipo* em um único comando, separando-as por vírgula. O código a seguir:

```cpp
int a;
int b;
```

é a mesma coisa que este:

```cpp
int a, b;
```

Ao definir múltiplas variáveis deste jeito, existem três erros comuns a novos programadores.

O primeiro é dar a cada variável na sequência um tipo.

```cpp
int a, int b;       // errado (erro de compilação)

int a, b;           // correto
```

O segundo erro é tentar definir variáveis de tipos diferentes no mesmo comando, o que não é permitido. Variáveis de tipos diferentes devem ser definidas em comandos diferentes.

```cpp
int a, double b;        // errado (erro de comipilação)

int a; double b;        // correto (mas não recomendado)

// correto e recomendado (mais legível)
int a;
double b;
```

O terceiro erro está mais relacionado ao próximo assunto.