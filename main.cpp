#include "include/Aluno.h"
#include "include/Professor.h"
#include "include/ListaNaoOrdenada.h"
#include "include/ListaOrdenada.h"
#include "include/Pilha.h"
#include "include/FilaBasica.h"
#include "include/FilaCircular.h"
#include <iostream>

int main() {
    std::cout << "====== Lista Nao Ordenada ======\n";
    ListaNaoOrdenada lnao;
    lnao.inserirNoFinal(new Aluno(1, "Ana", 101));
    lnao.inserirNoFinal(new Professor(2, "Carlos", "Fisica"));
    lnao.imprimirTodos();

    std::cout << "\n====== Lista Ordenada ======\n";
    ListaOrdenada lord;
    lord.inserir(new Aluno(5, "Bianca", 202));
    lord.inserir(new Professor(3, "Daniel", "Quimica"));
    lord.inserir(new Aluno(4, "Edu", 303));
    lord.imprimirTodos();

    std::cout << "\n====== Pilha (Topo = Ultimo Inserido) ======\n";
    Pilha pilha;
    pilha.empilhar(new Aluno(10, "Fabio", 999));
    pilha.empilhar(new Professor(11, "Gabriela", "Historia"));
    if (Elemento* topo = pilha.consultarTopo()) topo->imprimirInfo();
    pilha.desempilhar();
    if (Elemento* topo = pilha.consultarTopo()) topo->imprimirInfo();

    std::cout << "\n====== Fila Basica (Nao Otimizada) ======\n";
    FilaBasica filaB;
    filaB.enfileirar(new Aluno(20, "Helena", 111));
    filaB.enfileirar(new Professor(21, "Igor", "Geografia"));
    if (Elemento* frente = filaB.frente()) frente->imprimirInfo();
    filaB.desenfileirar();
    if (Elemento* frente = filaB.frente()) frente->imprimirInfo();

    std::cout << "\n====== Fila Circular (Eficiente) ======\n";
    FilaCircular filaC;
    filaC.enfileirar(new Aluno(30, "Julia", 1234));
    filaC.enfileirar(new Professor(31, "Lucas", "Portugues"));
    filaC.imprimirTodos();
    filaC.desenfileirar();
    if (Elemento* frente = filaC.frente()) frente->imprimirInfo();

    return 0;
}
