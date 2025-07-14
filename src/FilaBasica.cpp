#include "FilaBasica.h"

void FilaBasica::enfileirar(Elemento* e) {
    lista.inserirNoFinal(e);
}

void FilaBasica::desenfileirar() {
    lista.removerPrimeiro(); // O(n) pois desloca elementos
}

Elemento* FilaBasica::frente() const {
    return lista.getPrimeiro();
}

bool FilaBasica::vazia() const {
    return lista.estaVazia();
}
