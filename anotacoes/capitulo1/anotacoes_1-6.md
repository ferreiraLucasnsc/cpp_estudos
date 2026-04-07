# Variáveis Não Inicializadas e Comportamento Indefinido

## Variáveis não Inicializadas

Ao invés de algumas linguagens de programação, C/C++ não inicializam automaticamente a maioria das variáveis com algum valor (como zero). Quando uma variável que não é inicializada recebe um endereço de memória para guardar dados, o valor padrão da variável é qualquer valor que já esteja no endereço (valor de lixo). Uma variável que não recebeu algum valor (seja por inicialização ou por atribuição) é chamada de **variável não inicializada**.

> **Relembrando:**
>
> - Inicializada: o objeto recebe um valor conhecido no ponto da definição
> - Atribuição: o objeto recebe um valor conhecido fora do ponto de definição
> - Não inicializada: o objeto não recebeu um valor conhecido ainda

Considere o código abaixo:

```cpp
#include <iostream>

int main() {
    int x;  // esta variável não foi inicializada, pois não demos um valor

    std::cout << x;

    return 0;
}
```

Neste caso, o computador irá atribuir alguma memória não usada, e então irá enviar o valor neste local de memória para *std::cout*, que irá exibir o valor (interpretado como um inteiro). O valor exibido não será o mesmo ao longo das execuções de um código.

A maioria dos compiladores modernos irão tentar detectar se uma variável está sendo usada sem um valor. Se este for o caso, eles irão gerar uma mensagem durante a compilação.

## Comportamento Indefinido

Usar um valor de uma variável não inicializada é o nosso primeiro exemplo de comportamento indefinido. **Comportamento indefinido** (muitas vezes abreviado para **UB**) é o resultado de um código executado onde o comportamento não é definido pela linguagem C++. Neste caso, C++ não possui regras determinando o que irá acontecer se usar o valor de uma variável que não recebeu um valor.

Códigos que implementam comportamento indefinido podem:

- Produzir resultados diferentes em toda vez que executa
- Produzir o mesmo resultado incorreto
- Se comportar de forma inconsistente
- Parecer que estão funcionando, mas produzem resultados incorretos
- Travar, imediatamente ou mais tarde
- Funcionar em certos compiladores, mas não em outros
- Funcionar até que se faça uma mudança em código não relacionado

## Comportamento definido por Implementação e Comportamento Indefinido

Um compilador específico e a biblioteca padrão associada são chamados de **implementação** (pois eles são o que implementa o C++). Em alguns casos, o padrão de linguagem C++ permite a implementação determinar como um aspecto da linguagem irá se comportar, então o compilador escolhe o que for mais eficiente para certa plataforma. Comportamento definido pela implementação é chamado de **comportamento definido por implementação**. Comportamento definido por implementação precisa ser documentado e consistente para uma implementação.

Vamos dar uma olhada em um exemplo de comportamento definido por implementação:

```cpp
#include <iostream>

int main() {
    std::cout << sizeof(int);  // exibe quanto bytes de memória um valor int toma
}
```

Enquanto algumas plataformas podem exibir `4`, outras podem exibir `2`.

**Comportamento indefinido** é quase idêntico ao comportamento definido por implementação na questão do comportamento é deixado para que a implementação defina, mas a implementação não é necessária para documentar o comportamento.

Queremos evitar estes tipos de comportamento, pois assim nosso programa pode não funcionar como esperado de compilado em outro compilador.