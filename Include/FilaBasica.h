
#ifndef FILABASICA_H
#define FILABASICA_H

#include "ListaNaoOrdenada.h"

class FilaBasica {
private:
	
    ListaNaoOrdenada lista;

public:

    // adiciona um elemento no fim da fila.
    bool enfileirar(Elemento* e);

    // remove o elemento do início da fila.
    bool desenfileirar();

    // retorna o elemento no início da fila, sem o apagar
    const Elemento* frente() const;

    // verifica se a fila se encontra vazia
    bool vazia() const;

    // verifica status da fila
    bool cheia() const;

    // exibir todos os elementos da fila
    void imprimirTodos() const;
};

#endif 
