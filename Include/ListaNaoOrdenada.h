#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"

class ListaNaoOrdenada {
private:
    Elemento* elementos[100];
    int tamanho = 0;

public:
    ~ListaNaoOrdenada();

    bool inserirNoInicio(Elemento* e);     // O(n)
    bool inserirNoFinal(Elemento* e);      // O(1)
    bool removerPrimeiro();                // O(n)
    bool removerUltimo();                  // O(1)
    bool removerPeloId(int id);            // O(n)
    Elemento* buscarPeloId(int id) const;  // O(n)
    bool alterarPeloId(int id, Elemento* novo); // O(n)
    void imprimirTodos() const;            // O(n)

    int getTamanho() const;
    Elemento* getUltimo() const;
    Elemento* getPrimeiro() const;          // <== NOVO
    bool estaCheia() const;
    bool estaVazia() const;
};

#endif
