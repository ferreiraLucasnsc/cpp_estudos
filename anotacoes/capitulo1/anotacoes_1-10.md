# Introdução a Expressões

## Expressões

Veja a seguinte série de comandos:

```cpp
int five() {
    return 5;
}

int main()
{
    int a{ 2 };
    int b{2 + 3};
    int c{ (2 * 3) + 4};
    int d{ b };
    int e{ five() };

    return 0;
}
```

Os inicializadores acima usam uma variedade de entidades: literais, variáveis, operadores e chamadas de funções. De alguma forma, C++ está convertendo todas essas coisas diferentes em um único valor usado como a incial da variável.

Todos estes inicializadores usam uma **expressão**, uma sequência não vazia de literais, variáveis, operadores e chamadas de função que calculam um valor. O processo de executar uma expressão é chamado de **avaliação**, e o valor resultande é chamado de **resultado** ou **valor de retorno**.

Quando uma expressão é avaliada, cada um dos termos dentro da expressão é avaliado, até que um único valor reste.

Literais avaliam seu próprio valor. Variáveis avaliam o valor da variável. Operadores usam seus operandos para avaliarem outro valor.

As expressões não terminam com ponto e vírgula, e não podem ser compiladas por si mesmas.

## Comandos de Expressão

Certas expressões (como `x = 5`) são usadas por conta de seus efeitos colaterais. Entretanto, expressões também não podem ser executadas sozinhas, e precisam existir como parte de um comando, transformando-se então em um **comando de expressão**, que é uma expressão acompanhada por ponto e vírgula.

Quando uma expressão é usada em um comando de expressão, qualquer resultado gerado pela expressão não é usado. O comando de expressão `x = 5;`, por exemplo, descarta o valor do operador `=`, em favor da ação de atribuir `5` ao `x`.

Existem comandos de expressão que podem ser inúteis ao código. O comando `2 * 3;` é uma expressão com resultado `6`, mas este resultado não é utilizado, e então descartado.

## Subexpressões, Expressões Completas, e Expressões Compostas

Veja as seguintes expressões:

```cpp
2  // literal que avalia para o valor 4
2 + 3  // 2 + 3 usa o operador + para avaliar para 5
x = 4 + 5  // 4 + 5 avalia para 9, que é atribuido para a variável x
```

Uma **subexpressão** é uma expressão usada como operando. Na expressão `x = 4 + 5`, as subexpressões são `x` e `4 + 5`, e as subexpressões de `4 + 5` são `4` e `5`.

Uma **expressão completa** é uma expressão que não seja uma subexpressão. Aqui, temos `2`, `2 + 3` e `x = 4 + 5`, expressões que não servem como operandos em nenhuma outra.

Uma **expressão composta** utiliza dois ou mais operadores. A expressão `x = 4 + 5` usa os operadores de atribuição (`=`) e de adição (`+`).