# Programas com Vários Arquivos de Código

## Adicionando Arquivos ao Projeto

Enquanto programas se tornam maiores, é comum separá-los em múltiplos arquivos para propósitos de organização ou reuso. Uma vantagem das IDEs é que trabalhar com mais de um arquivo se torna mais fácil.

Vamos pegar o exemplo passado de funções e dividí-lo em dois arquivos:

adicao.cpp:
```cpp
int adicao(int x, int y)
{
    return x + y;
}
```

main.cpp
```cpp
#include <iostream>

int adicao(int x, int y);

int main()
{
    std::cout << "A soma de 3 e 4 é: " << adicao(3, 4) << '\n';
    return 0;
}
```

Agora, temos um arquivo separado para a lógica da função, e um arquivo para a execução do programa. No arquivo principal, declaramos a função novamente para que seja reconhecida e executada pelo compilador.

## Possíveis Erros

Existem vários erros que podem acontecer na primeira vez em que trabalhamos com vários arquivos em um projeto. Se, ao tentar executar o arquivo *main*, encontrou um erro, veja as seguintes soluções:

1. Se o compilador apresentou um erro sobre a função *adicao* não estar definida no arquivo *main*, lembre-se de acrescentar a declaração no arquivo.
2. Se houver um erro de ligação sobre *adicao* não estar definida, então:
    - Provavelmente, o arquivo *add* não foi adicionado corretamente ao projeto. O compilador precisa analisar ambos *adicao.cpp* e *adicao.cpp*. Busque fazer com que o compilador esteja analisando o projeto como um todo, ao invés de um arquivo somente. A forma como o compilador fará isso varia de IDE para IDE:
        - Visual Studio: os arquivos estarão na pasta de *Source Files*, como um item *C++ File*.
        - Code::Blocks: os arquivos serão criados como uma *C/C++ Source*, com a caixa de adicionar ao projeto marcada.
        - GCC: na linha de comando, crie o arquivo adicional com o editor de escolha e nomeie-o. Ao compilar o programa, inclua os nomes dos arquivos necessários (por exemplo: `g++ main.cpp adicao.cpp -o main`).
        - VS Code: na pasta onde estarão os arquivos, modifique o arquivo *tasks.json* na linha `"${file}",`, substituindo-a pelos nomes dos arquivos que serão lidos em conjunto, um por linha. Também é possível fazer com que o VS Code automaticamente compile todos os arquivos .cpp com o comando `"${fileDirname}\\**.cpp"`.
    - Talvez o arquivo adicional esteja em outro projeto.
    - Talvez o arquivo não esteja configurado para ser compilado ou conectado. Verifique as propriedades do arquivo e tenha certeza que esteja pronto para compilação/ligação.
3. Não faça o `#include "adicao.cpp"`, pois esta prática aumenta o risco de conflitos de nomes e outras consequências não antecipadas.