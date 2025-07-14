#pragma once 

class Elemento {
private:
    long id; // Usando long para o ID

public:
    // Construtor
    Elemento(long id_val) : id(id_val) {}

    // Destrutor virtual 
    virtual ~Elemento() {}

    // Getter para o ID
    long getID() const {
        return id;
    }

    // Função virtual 
    virtual void imprimirInfo() const = 0;
};