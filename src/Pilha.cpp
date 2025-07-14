#include "Pilha.h"

void Pilha::empilhar(Elemento* e) {
    lista.inserirNoFinal(e);
}

void Pilha::desempilhar() {
    lista.removerUltimo();
}

Elemento* Pilha::consultarTopo() const {
    return lista.getUltimo();
}

bool Pilha::pilhaVazia() const {
    return lista.estaVazia();
}

bool Pilha::pilhaCheia() const {
    return lista.estaCheia();
}
