#ifndef ALUNO_H
#define ALUNO_H

#include "Elemento.h"
#include <string>
#include <iostream>

class Aluno : public Elemento {
private:
    std::string nome;
    int matricula;

public:
    Aluno(int id, const std::string& nome, int matricula)
        : Elemento(id), nome(nome), matricula(matricula) {}

    void imprimirInfo() const override {
        std::cout << "Aluno [ID: " << id << ", Nome: " << nome
                  << ", Matricula: " << matricula << "]\n";
    }
};

#endif
