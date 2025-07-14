#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#include "Elemento.h"
#include <iostream>

class FilaCircular {
private:
    Elemento* elementos[100];
    int inicio;
    int fim;
    int tamanho;

public:
    FilaCircular();
    ~FilaCircular();

    void enfileirar(Elemento* e);     // O(1)
    void desenfileirar();             // O(1)
    Elemento* frente() const;         // O(1)
    bool vazia() const;               // O(1)
    bool cheia() const;               // O(1)
    void imprimirTodos() const;       // O(n)
};

#endif
