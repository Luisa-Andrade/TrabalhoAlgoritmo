#ifndef PILHA_H
#define PILHA_H

#include "ListaNaoOrdenada.h"

class Pilha {
private:
    ListaNaoOrdenada lista; // composição com lista não ordenada

public:
    void empilhar(Elemento* e);
    void desempilhar();
    Elemento* consultarTopo() const;
    bool pilhaVazia() const;
    bool pilhaCheia() const;
};

#endif
