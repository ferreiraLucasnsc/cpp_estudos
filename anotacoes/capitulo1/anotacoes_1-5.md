# Introdução ao iostream: cout, cin, e endl

## A biblioteca de entrada/saída

A **biblioteca de entrada/saída** (bibloteca io - input/output) é parte da biblioteca padrão C++ que lida com entrada e saída básica. Iremos usar a funcionalidade nessa biblioteca para obter entradas pelo teclado e saídas para o console.

Para usar as funcionalidades na biblioteca *iostream*, precisamos incluí-la no topo do arquivo que irá usar a biblioteca:

```cpp
#include <iostream>
```

## std::cout

A biblioteca *iostream* contém algumas variáveis predeterminadas para uso. Uma das mais utilizadas é **std::cout**, que nos permite enviar dados para o console para serem exibidos como texto. O termo *cout* significa "character output" (saída de caractere).

```cpp
#include <iostream>  // para std::cout

int main() {
    std::cout << "Olá mundo!";  // exibe Olá mundo! no console

    return 0;
}
```

```console
Olá mundo!
```

Junto com *std::cout* temos o **operador de inserção** (`<<`), para enviar o texto ao console.

*std::cout* pode imprimir também números:

```cpp
#include <iostream>

int main() {
    std::cout << 4;

    return 0;
}
```

Também é possível imprimir o valor das variáveis.

Para exibir mais de um conteúdo na mesma linha, o operador de inserção (`<<`) pode ser usado várias vezes para concatenar (juntar) peças de saídas:

```cpp
#include <iostreamm>

int main() {
    std::cout << "x é igual a: " << x;
    return 0;
}
```

## std::endl

Por padrão, linhas exibidas pelo *std::cout* permitem que o próximo uso junte as linhas:

```cpp
#include <iostream>

int main() {
    std::cout << "Olá!";
    std::cout << "Meu nome é Alex";
    return 0;
}
```

```console
Olá!Meu nome é Alex
```

Se queremos imprimir linhas separadas para o console, precisamos dizer ao console para mover o cursor para a próxima linha. Podemos fazer isso imprimindo uma linha nova (newline). Uma **newline** é um caractere específico para o SO (sistema operacional) ou uma sequência de caracteres que movem o cursor para o começo da próxima linha.

Uma forma de imprimir uma linha nova é através do `std::endl` (end line - fim de linha):

```cpp
#include <iostream>

int main() {
    std::cout << "Olá!" << std::endl;
    std::cout << "Meu nome é Alex." << std::endl;
}
```

```console
Olá!
Meu nome é Alex.
```

> **Dica**
>
> A sintaxe `std::endl` tem mais alguns usos do que somente uma linha nova:
>
> - Ajuda a indicar que a linha de saída é um "pensamento completo", e não necessita de ser completada em outra parte do código
> - Posiciona o cursor na próxima linha, para que saídas adicionais apareçam onde experamos
> - Exibe o prompt de comando em uma linha nova, enquanto alguns sistemas não façam o mesmo sem a presença do endl

## Buffer de std::cout

As saídas de informações no console pelo `std::cout` não são imediatas. Ao invés disso, a saída requisitada é guardada em uma região de memória separada para coletar requisições (chamada de **buffer**). Periodicamente, os dados de um buffer são transferidos para seus destinos (neste caso, o console).

Isso também significa que, no caso do programa quebrar ou pausar antes da limpeza do buffer, qualquer saída esperando não será exibida.

## Uso de \n

Por limpar o buffer, uma atividade lenta, utilizar `std::endl` é considerado ineficiente, principalmente no caso de várias linhas.

Como o sistema de saída do C++ é feito para limpar periodicamente o buffer, é mais simples e eficiente deixar essa tarefa para o modo automático.

Para exibir uma linha nova sem interferir na limpeza do buffer, usamos o símbolo `\n` dentro de aspas simples ou duplas. Este é um símbolo especial que o compilador interpreta como um caractere de nova linha. `\n` move o cursor para a linha abaixo sem causar uma limpeza, então possui uma performance melhor. Este símbolo também é mais fávil de se escrever e pode ser inserido em uma linha de texto:

```cpp
#include <iostream>

int main() {
    int x{ 5 };
    std::cout << "x é igual a: " << x << '\n';  // aspas simples (convencional)
    std::cout << "É." << "\n"; // aspas duplas
    std::cout << "Isso é tudo, pessoal!\n";  // dentro de texto (convencional)
}
```

```console
x é igual a: 5
É.
Isso é tudo, pessoal!
```

## std::cin

Outra variável útil da biblioteca `iostream` é `std::cin` (character input - entrada de caractere), usada para ler entrada de dados pelo teclado. Geralmente usamos o operador de extração `>>` para inserir o dado em uma variável.

```cpp
#include <iostream>

int main() {
    std::cout << "Insira um número: ";
    int x{};
    std::cin >> x;

    std::cout << "Você inseriu " << x << '\n';
    return 0;
}
```

Ao compilar e executar o código acima, a primeira linha exibida será esta:

```console
Insira um número: _
```

Neste momento, o cursor está na frente da linha, esperando que o usuário faça uma inserção de um dado, através da digitação no teclado. Ao inserir um número e pressionar ENTER, o número será atribuído à variável `x`. E, então, o programa irá exibir a outra linha:

```console
Insira um número: 4
Você inseriu 4
```

Assim como a saída, é possível inserir mais de um valor em uma linha somente:

```cpp
#include <iostream>

int main() {
    std::cout << "Insira dois números separados por um espaço: ";
    int x{};
    int y{};
    std::cin >> x >> y;

    std::cout << "Você inseriu " << x << " e " << y << '\n';

    return 0;
}
```

```console
Insira dois números separados por um espaço: 5 6
Você inseriu 5 e 6
```

O espaço para separar os valores deve ser um espaço em branco (espaço comum, tab ou nova linha).

## Buffer de std::cin

`std::cin` também possui um processo de duas fases: adição dos caracteres ao final de um buffer, inclusive da tecla ENTER, guardada na forma de `\n`; remoção de caracteres na frente do buffer pelo operador '>>' e conversão para valor (atribuição por cópia).

Veja o seguinte código:

```cpp
#include <iostream>

int main() {
    std::cout << "Insira dois números: ";

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    std::cout << "Você inseriu " << x << " e " << y << '\n';

    return 0;
}
```

O programa acima insere para duas variáveis. Faremos dois testes.

No primeiro teste, insira o valor `4` na primeira espera. Neste momento, será enviado ao buffer de entrada `4\n`, e o valor `4` irá para a variável `x`. Na segunda espera, insira o valor `5`. Igualmente, `5\n` será enviado ao buffer, e a variável irá receber o valor `5`.

No segundo teste, insira os valores `4 5` na primeira espera. O valor `4 5\n` será enviado ao buffer, mas apenas o valor `4` irá para a extração. A segunda espera, entretanto, não irá acontecer, e a variável `y` receberá o valor `5` imediatamente após.

## Processo básico de Extração

Uma vista simplificada de como o operador `>>` funciona:

1. Se `std::cin` não está em um bom estado (ex.: se a extração anterior falhou e a variável não foi limpa), não haverá extração, e o processo encerra imediatamente
2. Espaços em branco serão descartados do buffer, descartando caracteres de nova linha não requisitados
3. Se o buffer de entrada está vazio, o operador irá esperar dados pelo usuário. Qualquer espaço em branço é descartado do dado inserido
4. O operador então extrai o máximo de caracteres consecutivos que pode, até encontrar um espaço de nova linha ou um caractere inválido para a variável

O resultado da extração é o seguinte:

- Se o processo foi encerrado no passo 1, então não haverá tentativa de extração, e nada acontece
- Se qualquer caractere fosse extraído no passo 4, a extração foi um sucesso. Os caracteres extraídos são convertidos em um valor e atribuídos.
- Se nenhum caractere foi extraído, a extração falhou. O objeto recebendo a extração recebe a atribuição do valor `0` (em C++11), e qualquer extração futura irá falhar, até que `std::cin` seja limpo. Qualquer caractere não extraído, incluíndo se tornará disponível para a próxima extração.

Exemplo:

```cpp
int x{};
std::cin >> x;
```

- Se o usuário inserir `5a`, `5a\n` será adicionado ao buffer. `5` será extraído, convertido para inteiro, e atribuído para a variável. `a\n` restarão no buffer e estarão disponíveis na próxima extração
- Se o usuário inseri `b`, `b\n` será adicionado ao buffer. `b` não sendo um inteiro válido, não haverá caracteres para extração, então a extração será um fracasso. A variável receberá `0`, e extrações futuras também irão falhar enquanto o canal de entrada não for limpo
- Se `std::cin` não estiver em bom estado por conta de uma extração malsucedida, nada acontece, e o valor de `x` não é alterado.