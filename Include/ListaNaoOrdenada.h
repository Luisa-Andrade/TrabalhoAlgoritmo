#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"

class ListaNaoOrdenada {
private:
    Elemento* elementos[100]; 
    int tamanho = 0;           

public:
    ~ListaNaoOrdenada();  // liberar memória dos elementos

    //  Métodos de Inserção 
    bool inserirNoInicio(Elemento* e);  // Adiciona no começo (custo O(n) - deslocamento)
    bool inserirNoFinal(Elemento* e);   // Adiciona no final (custo O(1) - direto)
    
    //  Métodos de Remoção 
    bool removerPrimeiro();             // Remove primeiro elemento (O(n) - deslocamento)
    bool removerUltimo();               // Remove último elemento (O(1) - direto)
    bool removerPeloId(int id);         // Remove por ID (O(n) - busca + deslocamento)
    
    //  Métodos de Busca/Modificação 
    const Elemento* buscarPeloId(int id) const;  // Busca elemento por ID (O(n))
    bool alterarPeloId(int id, Elemento* novo);  // Substitui elemento por ID (O(n))
    
    //  Métodos Auxiliares 
    void imprimirTodos() const;                     // Imprime todos elementos
    int getTamanho() const { return tamanho; }      // Retorna quantidade atual
    const Elemento* getPrimeiro() const;            // Acessa primeiro elemento
    const Elemento* getUltimo() const;              // Acessa último elemento
    bool estaCheia() const { return tamanho >= 100; }  // Verifica capacidade máxima
    bool estaVazia() const { return tamanho == 0; }    // Verifica lista vazia
    
    // Remove último SEM destruir o objeto
    Elemento* removerUltimoSemDeletar();
};

#endif
