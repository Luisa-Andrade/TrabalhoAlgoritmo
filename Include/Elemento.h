#ifndef ELEMENTO_H
#define ELEMENTO_H

// Classe abstrata usada como base para todos os tipos de dados nas estruturas
class Elemento {
protected:
    int id;

public:
    Elemento(int id) : id(id) {}
    virtual ~Elemento() {}

    int getID() const {
        return id;
    }

    // Método virtual puro obriga as classes filhas a implementarem
    virtual void imprimirInfo() const = 0;
};

#endif
