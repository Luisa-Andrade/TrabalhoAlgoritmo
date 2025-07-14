
#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#include "Elemento.h"

class FilaCircular {
private:

    // Array fixo que armazena ponteiros para os elementos da fila.
    Elemento* elementos[100];
    // Índice que aponta para o primeiro elemento da fila.
    int inicio;
    // Índice que aponta para a próxima posição vaga no final da fila.
    int fim;
    // Quantidade atual de elementos na fila.
    int tamanho;

public:

    FilaCircular();
    // será chamado quando o objeto for destruido
    ~FilaCircular();

    // Adiciona um elemento no fim da fila.
    bool enfileirar(Elemento* e);
    // Remove o elemento do início da fila.
    bool desenfileirar();
    // Consulta o elemento no início da fila, sem o apagar.
    const Elemento* frente() const;
    // Verifica se a fila não contém elementos.
    bool vazia() const;
    // Verifica se a fila atingiu sua capacidade máxima.
    bool cheia() const;
    // Exibe todos os elementos contidos na fila.
    void imprimirTodos() const;
};

#endif
