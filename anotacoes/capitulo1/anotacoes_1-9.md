# Introdução a Literais e Operadores

## Literais

Uma **literal** (também conhecida como **constante literal**) é um valor fixo inserido diretamente no código.

Ambas literais e variáveis possuem um valor e um tipo. Ao invés da variável (cujo valor pode ser iniciado e modificado), o valor de uma literal é fixo e não pode ser mudado.

Vamos examinar o seguinte programa:

```cpp
int main()
{
    std::cout << 5 << '\n';  // valor da literal

    int x { 5 };
    std::cout << x << '\n'/  // valor da variável
}
```

Na linha 5, estamos exibindo o valor `5` para o console, um valor compilado ao executável que pode ser usado diretamente.

Na linha 7, criamos uma variável chamada `x` e a inicializando com o valor `5`. O compilador irá gerar o código que copia o valor para o local de memória dado a `x`. Na linha 8, exibimos o valor obtido no local de memória.

## Operadores

Na matemática, uma **operação** é um processo involvendo nenhum ou mais valores (**operandos**) que produzem um novo valor (chamado de *valor de saída*). A operação específica é denotada por um símbolo chamado de **operador**.

Em C++, as operações funcionam como esperado:

```cpp
int main()
{
    std::cout << 1 + 2 << '\n';  // exibe 3 (1 + 2 == 3)
    
    return 0;
}
```

No programa, as literais `1` e `2` são operandos para o operador de mais (`+`), que produz o valor `3`. Este valor então é exibido ao console. Em C++, o valor de saída de uma operação é chamado de **valor de retorno*.

Existem os operadores comuns da matemática em C++, como a adição (`+`), subtração (`-`), multiplicação (`*`) e a divisão (`\`), mas também temos o operador de atribuição (`=`), inserção (`<<`), extração (`>>`) e igualdade (`==`). Enquanto a maioria dos operadores usam símbolos, alguns utilizam palavras reservadas (ex.: `new`, `delete` e `throw`).

Os operadores em C++ são separados em quatro tipos dependendo da quantidade de operandos que podem ser utilzados (a **aritidade**):
- Unários: usam um operando
    - Ex.: operador `-` para negativar um número (`5` -> `-5`)
- Binários: usam dois operandos esquerdo e direito
    - Ex.: operador `+` para somar números (`3 + 4` -> `7`)
- Terciários: três operandos
    - Ex.: operador condicional `?` (mais para frente)
- Nulários: nenhum operando
    - Ex.: operador `throw`

## Sequência de Operadores

Operadores podem ser colocados em sequência, fazendo com que o resultado de um operador sirva como operando para outro. Veja por exemplo a sequência `2 * 3 + 4`. Aqui, a multiplicação fará sua parte (`2 * 3` -> `6`), e o resultado da operação da multiplicação servirá como operando para a adição (`6 + 4` -> `10`).

A ordem das operações acompanha as convenções matemáticas de *PEMDAS* (ou PEDMAS, BEDMAS, BODMAS, BIDMAS): parênteses, expoentes, multiplicação/divisão na ordem de leitura, adição/subtração da ordem de leitura.

## Efeito Colateral

Alguns operadores em C++ fazem mais de um trabalho. Uma função ou operação que tenha um outro efeito além de retornar um valor é dita ter um **efeito colateral**. Por exemplo, `x = 5` tem o efeito colateral de atribuir o valor `5` à variável `x`.