# Palavras-Chave a Identificadores

## Palavras-Chave

C++ reserva uma lista de 92 palavras para seu próprio uso. Estas são **palavras-chave** (ou palavras reservadas), e cada uma destas palavras possui um significado especial em C++.

## Regras de Nomes para Identificadores

O nome de uma variável é chamado de identificador. C++ permite flexibilidade para nomear os identificadores da forma que necessita, dentro de algumas regras:

- O identificador não pode ser uma palavra reservada
- O identificador pode conter apenas letras, números e o caractere underscore (`_`)
- O identificador pode começar somente com uma letra
- C++ é sensível a caixas (case sensitive), ou seja, distingue entre letras maiúsculas e minúsculas. `nvalor` é diferente de `nValor`, que é diferente de `NVALOR`.

## Boas Práticas para Identificadores

1. É convencional em C++ que os nomes da variáveis devem iniciar com uma letra minúscula. Se a variável é uma plavra só ou uma sigla, tudo deve estar em letra minúsculas.

    ```cpp
    int valor;  // convencional
    ```

    - Na maioria dos casos, nomes de funções também começam com letras minúsculas.
    - Identificadores que começam com letras maiúsculas geralmente são usados para tipos definidos pelo usuário (como enumerações e classes);
    - Se a variável ou nome da função tiver mais de uma palavra, existem duas convenções: palavras separadas pelo underscore (snake_case) ou caixas intercaladas (camelCase):

        ```cpp
        int nome_da_variavel;  // snake_case
        int nomeDaVariavel;  // camelCase
        ```

2. Evite nomes que iniciem com um underscore, pois são mais usados para uso do compilador, da biblioteca, e do sistema operacional
3. O nome dos seus identificadores necessita esclarecer o que o seu valor significa
    - Outra prática comum é mudar o tamanho do nome de acordo com suas características:
        - Use um nome menor para identificadores que:
            - existam por alguns comandos (ex.: no corpo de uma função curta)
            - representem um número não específico (ex.: entrada do usuário)
        - Use um nome maior para identificadores que:
            - sejam acessíveis em qualquer lugar do código
            - representem um valor específico
4. Evite abreviações não comuns
5. Em declarações de variáveis, pode ser útil inserir um comentário para descrever o uso de uma variável ou algo a mais que não seja óbvio