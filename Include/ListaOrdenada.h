#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "Elemento.h"

class ListaOrdenada {
private:
    Elemento* elementos[100];
    int tamanho = 0;

    int buscaBinaria(int id) const;

public:
    ~ListaOrdenada();
    bool inserir(Elemento* e);                    // O(n)
    bool removerPeloId(int id);                   // O(n)
    Elemento* buscarPeloId(int id) const;         // O(log n)
    bool alterarPeloId(int id, Elemento* novo);   // O(n)
    void imprimirTodos() const;                   // O(n)
};

#endif
