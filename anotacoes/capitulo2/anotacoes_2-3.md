# Funções Void

A sintaxe mais básica da definição de uma função é:

```cpp
tipoDeRetorno identidicador()
{
    // código
}
```

Dentre os tipos de retorno, explicamos sobre o tipo `int`. Outro tipo de função comum é o tipo `void`.

Enquanto funções de retorno precisam retornar algum valor, uma função não necessáriamente necessita ser de retorno. Para funções que não retornam valor algum, utilizamos o tipo **void** (vazio).

```cpp
#include <iostream>

void imprimaOla()
{
    std::cout << "Olá" << '\n';
}

int main()
{
    imprimaOla();

    return 0;
}
```

No exemplo acima, a função `imprimaOla` está encarregada de exibir na tela uma informação, mas ela não necessita retornar algum valor, pois sua função não possui retorno. Logo, `imprimaOla` recebe o valor `void`, para que o compilador entenda que não há necessidade de um retorno.

Quando a `main` chama `imprimaOla`, o código na função executa. Ao final da função, o controle volta para a `main`, e o programa continua.

Uma função void automaticamente será encerrada quando chegar nas linhas finais de sua definição, sem a necessidade de um comando de retorno, embora possamos usar um comando de retorno vazio (no entanto, seria redundância de código).

Por não retornarem valor, as funções void não podem ser usadas em expressões que necessitam de valores, como exibições de funções, ou cálculos com valores matemáticos.