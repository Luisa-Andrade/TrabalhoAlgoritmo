#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

#include "Elemento.h" 

class ArvoreBinariaBusca {
public:
    // Construtor: cria uma arvore vazia.
    ArvoreBinariaBusca();

    // Destrutor: libera toda a memoria alocada pela arvore.
    ~ArvoreBinariaBusca();

    // --- Metodos de Manipulacao Principais ---

    // Insere um novo elemento na arvore, mantendo a propriedade de busca.
    void Inserir(Elemento* elemento);

    // Busca um elemento na arvore pelo seu ID. Retorna um ponteiro para o
    // Elemento se encontrado, ou nullptr caso contrario.
    Elemento* BuscarPeloId(int id) const;

    // Remove um elemento da arvore com base no seu ID.
    void RemoverPeloId(int id);


    // --- Metodos de Percurso ---

    // Imprime os IDs dos nos em-ordem (esquerda, raiz, direita).
    void emOrdem() const;

    // Imprime os IDs dos nos em pre-ordem (raiz, esquerda, direita).
    void preOrdem() const;

    // Imprime os IDs dos nos em pos-ordem (esquerda, direita, raiz).
    void posOrdem() const;

private:
    // A classe No (Node) e um detalhe de implementacao interno e privado.
    // O usuario da arvore nao precisa saber que ela existe.
    struct No {
        Elemento* dado; // Ponteiro para o dado do tipo Elemento.
        No* esquerda;   // Ponteiro para a subarvore esquerda.
        No* direita;    // Ponteiro para a subarvore direita.

        // Construtor do No para facilitar a criacao.
        No(Elemento* elemento) : dado(elemento), esquerda(nullptr), direita(nullptr) {}
    };

    No* raiz; // Ponteiro para o no raiz da arvore.

    // --- Funcoes Auxiliares Recursivas (privadas) ---
    // A logica principal e implementada aqui, de forma recursiva.

    void inserir(No*& no, Elemento* elemento);
    Elemento* buscarPeloId(No* no, int id) const;
    void removerPeloId(No*& no, int id);
    No* encontrarMinimo(No* no); // Auxiliar para a remocao.

    void emOrdem(No* no) const;
    void preOrdem(No* no) const;
    void posOrdem(No* no) const;

    void destruir(No* no); // Auxiliar para o destrutor.
};

#endif 