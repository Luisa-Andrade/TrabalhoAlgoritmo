#ifndef ELEMENTO_H
#define ELEMENTO_H

// Aqui iremos criar a classe abstrata com nome "Elemento" com um atributo ID.
class Elemento {
protected:
    int id; // Atributo protegido, de nome ID, como chave primária.
            // Seu acesso só é permitido via getID().

public:
    Elemento(int id) : id(id) {}    // Construtor que inicializa o ID. É o que permite a criação de objetos derivados.
    virtual ~Elemento() {}          // Destrutor virtual.
   
    // Método de acesso ao ID — única forma externa de acessar o ID.
    int getID() const {             
        return id;
    }

    // Método para alteração: permite alterar o ID de um elemento.
    void setID(int novoId) {
        id = novoId;
    }

    
    // Método virtual puro — obriga as classes filhas a implementarem sua própria versão.
    virtual void imprimirInfo() const = 0;
        // Isso faz com que cada tipo de elemento (Aluno e Professor) tenha sua própria forma de imprimir informações,
        // com isso respeitando o POLIMORFISMO.
};

#endif
