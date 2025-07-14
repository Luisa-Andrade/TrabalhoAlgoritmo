#pragma once
#include "elemento.h"
#include <deque> 
#include <iostream>


class ListaSimplesmenteEncadeada {
private:
    std::deque<Elemento*> elementos_fake;

public:
    // O destrutor limpa a memória!
    ~ListaSimplesmenteEncadeada() {
        for (Elemento* el : elementos_fake) {
            delete el;
        }
    }

    void inserirNoInicio(Elemento* elemento) {
        elementos_fake.push_front(elemento);
    }
    void inserirNoFim(Elemento* elemento) {
        elementos_fake.push_back(elemento);
    }
    void removerPrimeiro() {
        if (!estaVazia()) {
            delete elementos_fake.front(); // Libera a memória
            elementos_fake.pop_front();
        }
    }
    Elemento* getPrimeiroElemento() const {
        return estaVazia() ? nullptr : elementos_fake.front();
    }
    bool estaVazia() const {
        return elementos_fake.empty();
    }
};