# Espaço em Branco e Formatação Básica

**Espaço em branco** é um termo usado para referir a caracteres usado para formatação. Em C++, este nome se refere mais para espaços, tabs e novas linhas. Espaço em branco em C++ é usado para três coisas: separar elementos da linguagem, dentro de texto, e para formatação de código.

## Separação de Elementos

A sintaxe da linguagem necessita que alguns elementos sejam separados. Isso ocorre mais quanto duas palavras-chave ou identificadores devem ser colocados consecutivamente.

```cpp
int x;  // int e x devem ser separados
int main();  // int e main devem ser separados
```

Quando o espaço em branco deve ser usado para a separação, o compilador não se importa com a quantidade de espaços usados. Então, todas as definições abaixo são válidas:

```cpp
int x;
int             y;
            int
z;
```

Em certos casos, novas linhas são usadas como separadores, como para encerrar códigos de linha única e diretivas de pré-processador:

```cpp
std::cout << "Olá mundo!";  // isso é parte do comentário
isso não é

#include <iostream>
#include <string>
```

## Dentro de Textos

Dentro de textos com aspas, a quantidade de espaços em branco é vista pelo literal. Então,

```cpp
std::cout << "Olá mundo";
```

é diferente de:

```cpp
std::cout << "Olá       mundo!";
```

Novas linhas não são permitidas, e textos separados por nada além de espaços em branco serão concatenados.

## Formatação de Código

Espaços em branco no código geralmente são ignorados, e são utilizados para facilitar a leitura do código pelas pessoas.

Por exemplo, o seguinte código:

```cpp
#include <iostream>
int main(){std::cout<<"Olá mundo";return 0;}
```

mesmo que difícil de ler, será executado da mesma forma que:

```cpp
#include <iostream>
int main() {
std::cout << "Olá mundo";
return 0;
}
```

e que a forma a seguir, muito mais legível:

```cpp
#include <iostream>

int main()
{
    std::cout << "Olá mundo";

    return 0;
}
```

Comandos longos podem ser divididos em várias linhas, se necessário.

## Formatação Básica

C++ não enforça restrições na formatação de código. Enquanto é bom ter a liberdade de formatação, existem muitas formas de formatar programas, sem um consenso absoluto de quais são melhores ou piores.

Aqui vão algumas recomendações:

- Utilize espaços comuns ou tabs para identação, e as tabs podem inserir quantos espaços forem configurados, embora seja mais recomendado que o tab possua quatro espaços
- Existem duas formas convencionais para chaves de uma função:
    ```cpp
    int main() {
        // ---
    }
    ```
    ```cpp
    int main()
    {
        // ---
    }
    ```
- Cada comando dentro de chaves devem começar a um tab de distância da chave de abertura da função:
    ```cpp
    int main()
    {
        std::cout<< "Olá mundo!\n";  // tab de distância
    }
    ```
- Linhas não devem ser muito longas, e o máximo de caracteres considerado são 80. Se a linha está passando desta quantidade, deve ser dividida em outras linhas continuadas
- Se uma linha longa é dividia com um operador, o operador deve ser colocado no início da próxima linha
- Use espaço em branco para fazer seu código mais fácil de ler, alinhando valores, comentários, ou espaço entre linhas de código

## Formatação Automática

Muitas IDEs modernas possuem ferramentas, comandos e atalhos para que seja feita a formatação automática do arquivo onde está sendo trabalhado.

## Guias de Estilos

Ao longo da internet, existem **guias de estilos**, documentos de opinião sobre formatação e convenções. Alguns mais comuns são:
- (Guias Fundamentais de C++)[http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines], mantido por Bjarne Stroustrup e Herb Sutter
- (Google)[https://google.github.io/styleguide/cppguide.html]
- (LLVM)[https://llvm.org/docs/CodingStandards.html]
- (GCC/CNU)[https://gcc.gnu.org/codingconventions.html]