#include "ListaOrdenada.h"
#include <iostream>

ListaOrdenada::~ListaOrdenada() {
    for (int i = 0; i < tamanho; ++i)
        delete elementos[i];
}

int ListaOrdenada::buscaBinaria(int id) const {
    int ini = 0, fim = tamanho - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (elementos[meio]->getID() == id)
            return meio;
        else if (elementos[meio]->getID() < id)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

bool ListaOrdenada::inserir(Elemento* e) {
    if (tamanho >= 100) return false;
    int i = tamanho - 1;
    while (i >= 0 && elementos[i]->getID() > e->getID()) {
        elementos[i + 1] = elementos[i];
        i--;
    }
    elementos[i + 1] = e;
    tamanho++;
    return true;
}

bool ListaOrdenada::removerPeloId(int id) {
    int pos = buscaBinaria(id);
    if (pos == -1) return false;
    delete elementos[pos];
    for (int i = pos; i < tamanho - 1; ++i)
        elementos[i] = elementos[i + 1];
    tamanho--;
    return true;
}

Elemento* ListaOrdenada::buscarPeloId(int id) const {
    int pos = buscaBinaria(id);
    return pos != -1 ? elementos[pos] : nullptr;  // Aqui: nullptr (C++11)
    // Se erro persistir, troque por: return pos != -1 ? elementos[pos] : NULL;
}

bool ListaOrdenada::alterarPeloId(int id, Elemento* novo) {
    bool removido = removerPeloId(id);
    if (!removido) return false;
    bool inserido = inserir(novo);
    return inserido;
}

void ListaOrdenada::imprimirTodos() const {
    for (int i = 0; i < tamanho; ++i)
        elementos[i]->imprimirInfo();
}
