# Lista Encadeada em C++

Este repositório contém uma implementação básica de uma lista encadeada em C++. O projeto inclui funções básicas para manipulação da lista, como inserção, remoção e modificação de elementos. O projeto é voltado para um Exercício da cadeira de Estrutura de Dados, prof. Gilberto.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

- `main.cpp`: Contém a implementação da lista encadeada e o programa principal que testa suas funcionalidades.
- `Makefile`: Um arquivo Makefile para compilar o projeto.

## Estrutura da Lista Encadeada

A lista encadeada é composta por duas classes:

### Classe `No`

Representa um nó da lista encadeada. Contém os seguintes membros:

- `valor`: O valor armazenado no nó.
- `next`: Um ponteiro para o próximo nó na lista.

Construtores:

- `No()`: Construtor padrão que inicializa `valor` como 0 e `next` como `nullptr`.
- `No(int valor)`: Construtor que inicializa `valor` com o valor fornecido e `next` como `nullptr`.
- `No(int valor, No *next)`: Construtor que inicializa `valor` com o valor fornecido e `next` com o ponteiro fornecido.

### Classe `LinkedList`

Representa a lista encadeada. Contém os seguintes membros:

- `head`: Ponteiro para o primeiro nó da lista.
- `tamanho`: Número de elementos na lista.

Métodos Públicos:

- `LinkedList()`: Construtor padrão que inicializa a lista como vazia.
- `void printarLista()`: Imprime todos os elementos da lista.
- `bool estaVazia()`: Retorna `true` se a lista estiver vazia, caso contrário, `false`.
- `int obterTamanho()`: Retorna o número de elementos na lista.
- `int recuperarValor(int pos)`: Retorna o valor do elemento na posição especificada. Exibe uma mensagem de erro se a posição for inválida.
- `void modificarValor(int valor, int pos)`: Modifica o valor do elemento na posição especificada. Exibe uma mensagem de erro se a posição for inválida.
- `void inserirValor(int valor, int pos)`: Insere um novo elemento com o valor especificado na posição fornecida. Exibe uma mensagem de erro se a posição for inválida.
- `void removerElemento(int pos)`: Remove o elemento na posição especificada. Exibe uma mensagem de erro se a posição for inválida.

## Como Compilar e Executar

Para compilar o projeto, use o comando `make` no terminal. O Makefile fornecido cuida do processo de compilação.

```bash
make
```

Isso criará um executável chamado `main.exe`. Para executar o programa, use o comando:

```bash
./main.exe
```

## Exemplo de Uso

O programa principal (`main.cpp`) realiza as seguintes operações:

1. Cria uma lista vazia.
2. Insere valores nas posições 1, 2 e 3.
3. Imprime a lista.
4. Obtém o tamanho da lista.
5. Recupera e modifica o valor de um elemento na lista.
6. Remove um elemento da lista.
7. Testa casos de erro ao tentar inserir, modificar, recuperar e remover elementos em posições inválidas.

## Casos de Erro

O programa também inclui casos de teste para verificar o comportamento da lista quando operações inválidas são realizadas, como:

- Inserção em posições 0 ou negativas.
- Modificação em posições 0 ou negativas.
- Recuperação de valores em posições 0 ou negativas.
- Remoção em posições 0 ou negativas.

## Limpeza

Para limpar os arquivos compilados, use o comando `make clean`:

```bash
make clean
```

Isso removerá os arquivos `.exe` gerados durante a compilação.