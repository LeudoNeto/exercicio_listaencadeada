#include <iostream>

using namespace std;

class No {
    public:
        int valor;
        No *next;

        No() : valor(0), next(nullptr) {}
        No(int valor) : valor(valor), next(nullptr) {}
        No(int valor, No *next) : valor(valor), next(next) {}

};

class LinkedList {
    private:
        No *head;
        int tamanho;

    public:

        LinkedList() : head(nullptr), tamanho(0) {}

        void printarLista() {
            No *atual = head;
            cout << "[ ";
            while (atual != nullptr) {
                cout << atual->valor << ", ";
                atual = atual->next;
            }
            cout << "]" << endl;
        }


        bool estaVazia() {
            return head == nullptr;            
        }

        int obterTamanho() {
            return tamanho;
        }

        int recuperarValor(int pos) {
            if (pos < 1 || pos > tamanho) {
                cerr << "Tentativa de acessar posição inválida." << endl;
                return -1;
            }
            No *atual = head;
            for (int i = 1; i < pos; i++) {
                atual = atual->next;
            }
            return atual->valor;
        }


        void modificarValor(int valor, int pos) {
            if (pos < 1 || pos > tamanho) {
                cerr << "Tentativa de modificação de fora da lista." << endl;
                return;
            }
            No *atual = head;
            for (int i = 1; i < pos; i++) {
                atual = atual->next;
            }
            atual->valor = valor;
        }

        void inserirValor(int valor, int pos) {
            if (pos < 1 || pos > tamanho + 1) {
                cerr << "Tentativa de inserção para fora da lista." << endl;
                return;
            }
            No *novoNo = new No(valor);
            if (pos == 1) {
                novoNo->next = head;
                head = novoNo;
            } else {
                No *anterior = head;
                for (int i = 1; i < pos - 1; i++) {
                    anterior = anterior->next;
                }
                novoNo->next = anterior->next;
                anterior->next = novoNo;
            }
            tamanho++;
        }


        void removerElemento(int pos) {
            if (pos < 1 || pos > tamanho) {
                cerr << "Tentativa de remoção de fora da lista." << endl;
                return;
            }
            No *remover;
            if (pos == 1) {
                remover = head;
                head = head->next;
            } else {
                No *anterior = head;
                for (int i = 1; i < pos - 1; i++) {
                    anterior = anterior->next;
                }
                remover = anterior->next;
                anterior->next = remover->next;
            }
            delete remover;
            tamanho--;
        }

        
};

int main() {

    cout << "Criando lista vazia" << endl;

    LinkedList lista = LinkedList();

    lista.printarLista();

    cout << "Verificando se a lista está vazia: " << lista.estaVazia() << endl;

    cout << "Inserindo os valores 10, 20, 30, nas posições 1, 2 e 3" << endl;

    lista.inserirValor(10, 1);
    lista.inserirValor(20, 2);
    lista.inserirValor(30, 3);

    lista.printarLista();

    cout << "Verificando se a lista está vazia: " << lista.estaVazia() << endl;

    cout << "Obtendo o tamanho da lista: " << lista.obterTamanho() << endl;

    cout << "Obtendo o valor do elemento na posição 2: " << lista.recuperarValor(2) << endl;

    cout << "Modificando o elemento na posição 3 para 50" << endl;

    lista.modificarValor(50, 3);

    lista.printarLista();

    cout << "Retirando o elemento na posição 1: " << endl;

    lista.removerElemento(1);

    lista.printarLista();

    cout << endl << "-=-=-=-= Casos de Erro -=-=-=-=" << endl << endl;

    cout << "Tentando inserir um elemento numa posição 0, negativa, ou maior que o tamanho da lista + 1." << endl;

    lista.inserirValor(10, 0);
    lista.inserirValor(10, -2);
    lista.inserirValor(10, 4);

    cout << "Tentando modificar o valor um elemento numa posição 0, negativa, ou maior que o tamanho da lista + 1." << endl;

    lista.modificarValor(10, 0);
    lista.modificarValor(10, -2);
    lista.modificarValor(10, 4);

    cout << "Tentando obter o valor um elemento numa posição 0, negativa, ou maior que o tamanho da lista + 1." << endl;

    lista.recuperarValor(0);
    lista.recuperarValor(-2);
    lista.recuperarValor(4);

    cout << "Tentando remover um elemento numa posição 0, negativa, ou maior que o tamanho da lista + 1." << endl;

    lista.removerElemento(0);
    lista.removerElemento(-2);
    lista.removerElemento(4);

    return 0;
}