#include "ListaNaoOrdenada.h"
#include <iostream>

ListaNaoOrdenada::~ListaNaoOrdenada() {
    for (int i = 0; i < tamanho; ++i)
        delete elementos[i];
}

bool ListaNaoOrdenada::inserirNoInicio(Elemento* e) {
    if (tamanho >= 100) return false;
    for (int i = tamanho; i > 0; --i)
        elementos[i] = elementos[i - 1];
    elementos[0] = e;
    tamanho++;
    return true;
}

bool ListaNaoOrdenada::inserirNoFinal(Elemento* e) {
    if (tamanho >= 100) return false;
    elementos[tamanho++] = e;
    return true;
}

bool ListaNaoOrdenada::removerPrimeiro() {
    if (tamanho == 0) return false;
    delete elementos[0];
    for (int i = 1; i < tamanho; ++i)
        elementos[i - 1] = elementos[i];
    tamanho--;
    return true;
}

bool ListaNaoOrdenada::removerUltimo() {
    if (tamanho == 0) return false;
    delete elementos[--tamanho];
    return true;
}

bool ListaNaoOrdenada::removerPeloId(int id) {
    for (int i = 0; i < tamanho; ++i) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            for (int j = i; j < tamanho - 1; ++j)
                elementos[j] = elementos[j + 1];
            tamanho--;
            return true;
        }
    }
    return false;
}

Elemento* ListaNaoOrdenada::buscarPeloId(int id) const {
    for (int i = 0; i < tamanho; ++i)
        if (elementos[i]->getID() == id)
            return elementos[i];
    return nullptr;
}

bool ListaNaoOrdenada::alterarPeloId(int id, Elemento* novo) {
    for (int i = 0; i < tamanho; ++i) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            elementos[i] = novo;
            return true;
        }
    }
    return false;
}

void ListaNaoOrdenada::imprimirTodos() const {
    for (int i = 0; i < tamanho; ++i)
        elementos[i]->imprimirInfo();
}

int ListaNaoOrdenada::getTamanho() const {
    return tamanho;
}

Elemento* ListaNaoOrdenada::getUltimo() const {
    if (tamanho == 0) return nullptr;
    return elementos[tamanho - 1];
}

Elemento* ListaNaoOrdenada::getPrimeiro() const {
    if (tamanho == 0) return nullptr;
    return elementos[0];
}

bool ListaNaoOrdenada::estaCheia() const {
    return tamanho >= 100;
}

bool ListaNaoOrdenada::estaVazia() const {
    return tamanho == 0;
}
