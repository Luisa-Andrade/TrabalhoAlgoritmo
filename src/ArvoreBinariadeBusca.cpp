#include "Arvore_Binaria.h"
#include <iostream>

// --- Construtor e Destrutor

ArvoreBinariaBusca::ArvoreBinariaBusca() : raiz(nullptr) {}

ArvoreBinariaBusca::~ArvoreBinariaBusca() {
    destruir(raiz);
}

void ArvoreBinariaBusca::destruir(No* no) {
    if (no) {
        destruir(no->esquerda);
        destruir(no->direita);
        delete no->dado; // Libera o objeto Elemento.
        delete no;       // Libera o no da arvore.
    }
}

//Metodos Publicos (Interface)

void ArvoreBinariaBusca::Inserir(Elemento* elemento) {
    inserir(raiz, elemento);
}

Elemento* ArvoreBinariaBusca::BuscarPeloId(int id) const {
    return buscarPeloId(raiz, id);
}

void ArvoreBinariaBusca::RemoverPeloId(int id) {
    removerPeloId(raiz, id);
}

//Metodos de Percurso Publicos

void ArvoreBinariaBusca::emOrdem() const {
    std::cout << "Percurso emOrdem: [ ";
    emOrdem(raiz);
    std::cout << "]" << std::endl;
}

void ArvoreBinariaBusca::preOrdem() const {
    std::cout << "Percurso preOrdem: [ ";
    preOrdem(raiz);
    std::cout << "]" << std::endl;
}

void ArvoreBinariaBusca::posOrdem() const {
    std::cout << "Percurso posOrdem: [ ";
    posOrdem(raiz);
    std::cout << "]" << std::endl;
}


//Implementacoes Recursivas Privadas

void ArvoreBinariaBusca::inserir(No*& no, Elemento* elemento) {
    if (!no) {
        no = new No(elemento);
    } else if (elemento->getID() < no->dado->getID()) {
        inserir(no->esquerda, elemento);
    } else if (elemento->getID() > no->dado->getID()) {
        inserir(no->direita, elemento);
    }
    // Nota: IDs duplicados sao ignorados nesta implementacao.
}

Elemento* ArvoreBinariaBusca::buscarPeloId(No* no, int id) const {
    if (!no) {
        return nullptr; // Nao encontrado
    }

    if (id < no->dado->getID()) {
        return buscarPeloId(no->esquerda, id);
    } else if (id > no->dado->getID()) {
        return buscarPeloId(no->direita, id);
    } else {
        return no->dado; // Encontrado
    }
}

void ArvoreBinariaBusca::removerPeloId(No*& no, int id) {
    if (!no) return; // Elemento nao esta na arvore

    if (id < no->dado->getID()) {
        removerPeloId(no->esquerda, id);
    } else if (id > no->dado->getID()) {
        removerPeloId(no->direita, id);
    } else { // Encontrou o no a ser removido
        if (!no->esquerda) { // Caso 1: Sem filho a esquerda
            No* temp = no;
            no = no->direita;
            delete temp->dado;
            delete temp;
        } else if (!no->direita) { // Caso 2: Sem filho a direita
            No* temp = no;
            no = no->esquerda;
            delete temp->dado;
            delete temp;
        } else { // Caso 3: Com dois filhos
            No* sucessor = encontrarMinimo(no->direita);
            // Troca os dados do no atual com os do sucessor
            // Primeiro, deletamos o dado antigo do no que sera "removido"
            delete no->dado;
            // O no atual agora aponta para o dado do sucessor
            no->dado = sucessor->dado;
            // Agora, removemos o no sucessor, que agora contem um dado duplicado
            // e e mais facil de remover. Precisamos evitar que seu dado seja deletado duas vezes.
            // Para isso, a recursao de remocao precisa ser ajustada.
            // Uma abordagem mais segura:
            // Trocar ponteiros de dados e remover o sucessor
            Elemento* dadoSucessor = sucessor->dado;
            sucessor->dado = nullptr; // Evita dupla liberacao de memoria
            delete no->dado; // Libera o dado original
            no->dado = dadoSucessor;
            removerPeloId(no->direita, sucessor->dado->getID());
        }
    }
}


// Funcao auxiliar para encontrar o menor no em uma sub-arvore (o mais a esquerda)
ArvoreBinariaBusca::No* ArvoreBinariaBusca::encontrarMinimo(No* no) {
    while (no && no->esquerda != nullptr) {
        no = no->esquerda;
    }
    return no;
}

// Implementacao dos percursos recursivos privados
void ArvoreBinariaBusca::emOrdem(No* no) const {
    if (no) {
        emOrdem(no->esquerda);
        std::cout << no->dado->getID() << " ";
        emOrdem(no->direita);
    }
}

void ArvoreBinariaBusca::preOrdem(No* no) const {
    if (no) {
        std::cout << no->dado->getID() << " ";
        preOrdem(no->esquerda);
        preOrdem(no->direita);
    }
}

void ArvoreBinariaBusca::posOrdem(No* no) const {
    if (no) {
        posOrdem(no->esquerda);
        posOrdem(no->direita);
        std::cout << no->dado->getID() << " ";
    }
}