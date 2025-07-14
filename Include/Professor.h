#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Elemento.h"
#include <string>
#include <iostream>

// Classe concreta que herda de Elemento.
// Essa classe implementa o método virtual puro da classe base, tornando-se instanciável.
class Professor : public Elemento {
private:
    std::string nome;       // Este é um exemplo de um atributo específico da classe Professor, que não foi herdado.    
    std::string area;       // Outro atributo específico, representando a área de atuação do professor.

public:
    // Construtor que inicializa os atributos próprios e repassa o ID para a superclasse.
    Professor(int id, const std::string& nome, const std::string& area)     // Representa um professor, com nome e área de atuação.
        : Elemento(id), nome(nome), area(area) {}               

    // Implementação do método virtual puro herdado da classe Elemento.
    void imprimirInfo() const override {
        std::cout << "Professor [ID: " << id << ", Nome: " << nome      // Exibe as informações completas do professor (incluindo o ID herdado),
                  << ", Area: " << area << "]\n";                       // respeitando assim o polimorfismo.
    }
};

#endif
