# Resumo do Capítulo 1

Um **comando** é um tipo de instrução que faz o programa realizar uma ação. Comandos são encerrados por ponto e vírgula.

Uma **função** é um grupo de comandos que são executados sequencialmente. Todo programa C++ deve incluir uma função especial de nome *main*. Ao rodar o programa, a execução inicia do topo da função *main*.

O nome de uma função ou objeto é chamado de **identificador**.

As regras que governam como elementos da linguagem C++ são construídos é chamada **sintaxe**. Um **erro de sintaxe** ocorre ao violar as regras gramaticais da linguagem.

**Comentários** permitem o programador deixar anotações no código. C++ permite dois tipos de comentários. Comentários de linha única começam com `//` e vão até o final da linha. Comentários de bloco começam com `/*` e vão até o par `*/`. Não aninhe comentários de bloco.

Você pode usar comentários para temporariamente desabilitar linhas ou seções de código.

**Dados** são qualquer informação que pode ser movida, processada, ou guardadas por um computador. Uma unidade de dado é chamada de **valor**. Exemplos comuns de valores incluem letras (ex.: `a`), números (ex.: `5`), e textp (ex.: `Olá`).

Uma variável é uma peça de memória com nome que podemos usar para guardar valores. Para criar uma variável, usamos um comando chamado de **comando de definição**. Quando o programa é executado, cada variável definida é **instanciada**, o que significa que é recebe um endereço de memória.

Um **tipo de dado** diz ao compilador como interpretar uma peça de dado em um valor útil. Um **inteiro** é um número que pode ser escrito sem um componente decimal, como 4, 27, 0, -2, ou -12.

**Atribuição por cópia** (por operador =) pode ser usado para atibuir um valor a uma variável já criada.

O processo de especificar um valor inicial para um objeto é chamado de **inicialização**, e a sintaxe usada para inicializar um objeto é chamada de **inicializador**.

C++ suporta seis tipos básicos de inicialização:

| Tipo de Inicialização | Exemplo | Destaque |
| --------------------- | ------- | -------- |
| Inicialização Padrão | int x; | Em muitos casos, deixa variáveis com valor indeterminado |
| Inicialização por Cópia | int x = 5; |     |
| Inicialização Direta | int x ( 5 ); |      |
| Inicialização por Lista | int x { 5 }; | Impede conversões de ponto |
| Inicialização por Cópia de Lista | int x = { 5 }; | Impede conversões de ponto |
| Inicialização de Valor | int x {}; | Geralmente faz inicialização por zero |

Inicialização direta é algumas vezes chamada de inicialização por parênteses, e a inicialização por lista também é chamada de inicialização uniforme ou inicialização por chaves. É melhor usar inicialização por chaves do que outras formas, e é melhor usar inicialização sobre atribuição.

Embora seja possível definir múltiplas variáveis em um único comando, é melhor definir e inicializar cada variável em sua própria linha.

**std::cout** e o operador `<<` nos permite exibir o resultado de uma expressão para o console.

**std::endl** envia um caractere de linha nova, forçando o cursor do console a mover-se para a próxima linha, e faz o flush de qualquer saída pendente ao console. O caractere `'\n'` também exibe um caractere de linha nova, mas deixa o sistema decidir a fazer o flush.

**std::cin** e o operador `>>` permitem obter um valor do teclado.

Uma variável que não recebeu um valor é chamada de **variável não inicializada**. Tentar obter o valor de uma variável não inicializada irá resultar em **comportamento indefinido**, que pode se manifestar em várias maneiras.

C++ reserva uma lista de nomes chamados de **palavras-chaves**. Estes nomes possuem significado especial dentro da linguagem e não podem ser usadas como nomes de variáveis.

Uma **constante literal** é um valor fixo inserido diretamente no código-fonte.

Uma **operação** é um processo envolvendo nenhum ou mais valores de entrada, chamados **operandos**. A operação específica a ser realizada é denotada pelo **operador**. O resultado de uma operaão produz um valor de saída.

Operadores **unários** usam um operando. Operadores **binários** usam dois operandos, chamados de esquerda e direita. Operadores **terciários** usam três operandos. Operadores **nulários** usam nenhum operando.

Uma **expressão** é uma sequência de literais, variáveis, operadores e chamadas de funções que são avaliadas para produzir um único valor de saída. O cálculo deste valor é chamado de **avaliação**. O valor produzido é o **resultado** da expressão.

Um **comando de expressão** é uma expressão transformada em um comando através do ponto e vírgula ao final.

Ao escrever programas, adicione algumas linhas ou uma função, compile, resolva qualquer erro, e tenha certeza de que funciona. Não espere até que tenha escrito o programa inteiro antes de compilar pela primeira vez.

Foque em fazer seu código funcionar. Quando tiver certeza de que irá manter uma parte de código, então use seu tempo removendo ou comentando códigos temporários e fazendo a debugagem, adicionando comentários, formatando seu código, ajustando-o para boas práticas, etc...

Os primeiros programas sempre são confusos e imperfeitos. A maioria dos códigos por aí precisam de limpeza e refinamento para se tornarem códigos excelentes!