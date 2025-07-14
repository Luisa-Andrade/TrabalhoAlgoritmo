#ifndef FILABASICA_H
#define FILABASICA_H

#include "ListaNaoOrdenada.h"

class FilaBasica {
private:
    ListaNaoOrdenada lista;

public:
    void enfileirar(Elemento* e);
    void desenfileirar();
    Elemento* frente() const;
    bool vazia() const;
};

#endif
