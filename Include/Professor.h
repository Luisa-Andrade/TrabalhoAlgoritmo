#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Elemento.h"
#include <string>
#include <iostream>

class Professor : public Elemento {
private:
    std::string nome;
    std::string area;

public:
    Professor(int id, const std::string& nome, const std::string& area)
        : Elemento(id), nome(nome), area(area) {}

    void imprimirInfo() const override {
        std::cout << "Professor [ID: " << id << ", Nome: " << nome
                  << ", Area: " << area << "]\n";
    }
};

#endif
