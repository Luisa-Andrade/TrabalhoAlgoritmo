#include "ArvoreBinariaBusca.h"
#include <iostream>

//Construtor e Destrutor

ArvoreBinariaBusca::ArvoreBinariaBusca() : raiz(nullptr) {}

ArvoreBinariaBusca::~ArvoreBinariaBusca() {
    destruir(raiz);
}

void ArvoreBinariaBusca::destruir(No* no) {
    if (no) {
        destruir(no->esquerda);
        destruir(no->direita);
        delete no->dado; //Libera o objeto Elemento.
        delete no;       //Libera o "nó" da arvore.
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

//Metodos de Percurso 

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


//Implementacao Recursivas 

void ArvoreBinariaBusca::inserir(No*& no, Elemento* elemento) {
    if (!no) {
        no = new No(elemento);
    } else if (elemento->getID() < no->dado->getID()) {
        inserir(no->esquerda, elemento);
    } else if (elemento->getID() > no->dado->getID()) {
        inserir(no->direita, elemento);
    }
}

Elemento* ArvoreBinariaBusca::buscarPeloId(No* no, int id) const {
    if (!no) {
        return nullptr; //Dado não encontrado
    }

    if (id < no->dado->getID()) {
        return buscarPeloId(no->esquerda, id);
    } else if (id > no->dado->getID()) {
        return buscarPeloId(no->direita, id);
    } else {
        return no->dado; //Dado encontrado
    }
}

void ArvoreBinariaBusca::removerPeloId(No*& no, int id) {
    if (!no) return; //O Elemento nao esta na arvore

    if (id < no->dado->getID()) {
        removerPeloId(no->esquerda, id);
    } else if (id > no->dado->getID()) {
        removerPeloId(no->direita, id);
    } else { //Encontra o "nó" a ser removido
        if (!no->esquerda) { //Caso 1: Sem filho a esquerda
            No* temp = no;
            no = no->direita;
            delete temp->dado;
            delete temp;
        } else if (!no->direita) { //Caso 2: Sem filho a direita
            No* temp = no;
            no = no->esquerda;
            delete temp->dado;
            delete temp;
        } else { // Caso 3: Com dois filhos
            No* sucessor = encontrarMinimo(no->direita);
            //Troca os dados do "nó" atual com os do sucessor
            //Deletamos o dado antigo do "nó" que sera removido
            delete no->dado;
            //O"nó" atual agora aponta para o dado do sucessor
            no->dado = sucessor->dado;
            //Agora, removemos o "nó" sucessor, que agora contem um dado duplicado
            //e é mais facil de remover, temos que evitar que seu dado seja deletado duas vezes.
            //Para tal, utilizaremos a recursão de remocao que precisa ser ajustada.

            Elemento* dadoSucessor = sucessor->dado;
            sucessor->dado = nullptr; //Evita dupla liberacao de memoria
            delete no->dado; //Libera o dado original
            no->dado = dadoSucessor;
            removerPeloId(no->direita, sucessor->dado->getID());
        }
    }
}


//Funcao auxiliar para encontrar o menor no em uma sub-arvore (o mais a esquerda)
ArvoreBinariaBusca::No* ArvoreBinariaBusca::encontrarMinimo(No* no) {
    while (no && no->esquerda != nullptr) {
        no = no->esquerda;
    }
    return no;
}

//Implementacao dos percursos

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