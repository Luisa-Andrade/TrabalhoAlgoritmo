#ifndef ALUNO_H
#define ALUNO_H

#include "Elemento.h"
#include <string>
#include <iostream>

// Classe concreta que herda de Elemento.
// Essa classe implementa o método virtual puro da classe base, tornando-se instanciável.
class Aluno : public Elemento {
private:
    std::string nome;   // Este é um exemplo de um atributo específico da classe Aluno, que não foi herdado.
    int matricula;      // Outro atributo específico, representando a matrícula do aluno.

public:
    // Construtor que recebe o ID (que é passado para Elemento) e os atributos próprios da classe.       
    Aluno(int id, const std::string& nome, int matricula)
        : Elemento(id), nome(nome), matricula(matricula) {}     // Representa um aluno, com nome e matrícula.

    // Implementação do método virtual puro herdado de Elemento.
    void imprimirInfo() const override {
        std::cout << "Aluno [ID: " << id << ", Nome: " << nome  // Exibe as informações completas do aluno (incluindo o ID herdado),
                  << ", Matricula: " << matricula << "]\n";     // respeitando assim o polimorfismo.
    }
};

#endif
