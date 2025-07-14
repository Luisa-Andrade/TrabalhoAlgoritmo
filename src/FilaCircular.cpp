#include "FilaCircular.h"

FilaCircular::FilaCircular() : inicio(0), fim(0), tamanho(0) {}

FilaCircular::~FilaCircular() {
    while (!vazia()) {
        desenfileirar();
    }
}

void FilaCircular::enfileirar(Elemento* e) {
    if (cheia()) return;
    elementos[fim] = e;
    fim = (fim + 1) % 100;
    tamanho++;
}

void FilaCircular::desenfileirar() {
    if (vazia()) return;
    delete elementos[inicio];
    inicio = (inicio + 1) % 100;
    tamanho--;
}

Elemento* FilaCircular::frente() const {
    if (vazia()) return nullptr;
    return elementos[inicio];
}

bool FilaCircular::vazia() const {
    return tamanho == 0;
}

bool FilaCircular::cheia() const {
    return tamanho == 100;
}

void FilaCircular::imprimirTodos() const {
    for (int i = 0; i < tamanho; ++i) {
        int indice = (inicio + i) % 100;
        elementos[indice]->imprimirInfo();
    }
}
