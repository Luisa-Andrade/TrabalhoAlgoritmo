#include "include/Aluno.h"
#include "include/Professor.h"
#include "include/ListaNaoOrdenada.h"
#include "include/ListaOrdenada.h"
#include "include/Pilha.h"
#include "include/FilaBasica.h"
#include "include/FilaCircular.h"
#include <iostream>
#include <limits>
#include <string>
#include <stdlib.h>

using namespace std;

// Variáveis globais
ListaNaoOrdenada lnao;
ListaOrdenada lord;
Pilha pilha;
FilaBasica filaB;
FilaCircular filaC;

// Protótipos
void limparBuffer();
void menuPrincipal();
void menuListaNaoOrdenada();
void menuListaOrdenada();
void menuPilha();
void menuFila();
bool idExiste(int id);
Elemento* criarElementoComIdValido(int tipo);

// Implementações

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Verifica se ID já existe em listas (pode estender para pilha/fila)
bool idExiste(int id) {
    if (lnao.buscarPeloId(id) != nullptr) return true;
    if (lord.buscarPeloId(id) != nullptr) return true;
    // Se quiser, implemente buscarPeloId na pilha e filas e cheque aqui também
    return false;
}

// Cria elemento pedindo ID válido (único)
Elemento* criarElementoComIdValido(int tipo) {
    int id;
    while (true) {
        cout << "ID (único): ";
        cin >> id;
        limparBuffer();
        if (idExiste(id)) {
            cout << "ID já existe! Tente outro.\n";
        } else {
            break;
        }
    }

    string nome;
    cout << "Nome: ";
    getline(cin, nome);

    if (tipo == 1) {
        int matricula;
        cout << "Matrícula: ";
        cin >> matricula;
        limparBuffer();
        return new Aluno(id, nome, matricula);
    } else {
        string area;
        cout << "Área: ";
        getline(cin, area);
        return new Professor(id, nome, area);
    }
}

Elemento* criarElemento(int tipo) {
    // Se precisar de uma versão simples sem checagem, mantenha esta
    // Senão, sempre use criarElementoComIdValido no menu
    int id;
    cout << "ID: ";
    cin >> id;
    limparBuffer();

    string nome;
    cout << "Nome: ";
    getline(cin, nome);

    if (tipo == 1) {
        int matricula;
        cout << "Matrícula: ";
        cin >> matricula;
        limparBuffer();
        return new Aluno(id, nome, matricula);
    } else {
        string area;
        cout << "Área: ";
        getline(cin, area);
        return new Professor(id, nome, area);
    }
}

void menuPrincipal() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== MENU PRINCIPAL ==========\n";
        cout << "1. Lista Não Ordenada\n";
        cout << "2. Lista Ordenada\n";
        cout << "3. Pilha\n";
        cout << "4. Fila\n";
        cout << "5. Arvore de busca Binaria\n";
        cout << "6. Sair/n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: menuListaNaoOrdenada(); break;
            case 2: menuListaOrdenada(); break;
            case 3: menuPilha(); break;
            case 4: menuFila(); break;
            case 5: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida!\n";
        }
    } while(opcao != 5);
}

void menuListaNaoOrdenada() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== LISTA NÃO ORDENADA ==========\n";
        cout << "1. Inserir no início\n";
        cout << "2. Inserir no final\n";
        cout << "3. Remover primeiro\n";
        cout << "4. Remover último\n";
        cout << "5. Remover por ID\n";
        cout << "6. Buscar por ID\n";
        cout << "7. Alterar por ID\n";
        cout << "8. Imprimir todos\n";
        cout << "9. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();

                Elemento* e = criarElementoComIdValido(tipo);
                if(lnao.inserirNoInicio(e)) {
                    cout << "Inserido com sucesso!\n";
                } else {
                    cout << "Falha ao inserir!\n";
                    delete e;
                }
                break;
            }
            case 2: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();

                Elemento* e = criarElementoComIdValido(tipo);
                if(lnao.inserirNoFinal(e)) {
                    cout << "Inserido com sucesso!\n";
                } else {
                    cout << "Falha ao inserir!\n";
                    delete e;
                }
                break;
            }
            case 3:
                if(lnao.removerPrimeiro()) {
                    cout << "Primeiro elemento removido!\n";
                } else {
                    cout << "Lista vazia!\n";
                }
                break;
            case 4:
                if(lnao.removerUltimo()) {
                    cout << "Último elemento removido!\n";
                } else {
                    cout << "Lista vazia!\n";
                }
                break;
            case 5: {
                int id;
                cout << "ID para remover: ";
                cin >> id;
                limparBuffer();

                if(lnao.removerPeloId(id)) {
                    cout << "Removido com sucesso!\n";
                } else {
                    cout << "ID não encontrado!\n";
                }
                break;
            }
            case 6: {
                int id;
                cout << "ID para buscar: ";
                cin >> id;
                limparBuffer();

                if(const Elemento* elem = lnao.buscarPeloId(id)) {
                    elem->imprimirInfo();
                } else {
                    cout << "Elemento não encontrado!\n";
                }
                break;
            }
            case 7: {
                int id;
                cout << "ID para alterar: ";
                cin >> id;
                limparBuffer();

                if (!lnao.buscarPeloId(id)) {
                    cout << "ID não encontrado!\n";
                    break;
                }

                int tipo;
                cout << "Novo tipo (1-Aluno 2-Professor): ";
                cin >> tipo;
                limparBuffer();

                Elemento* novo = nullptr;

                if (tipo == 1) {
                    string nome;
                    int matricula;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Matrícula: ";
                    cin >> matricula;
                    limparBuffer();

                    novo = new Aluno(id, nome, matricula);

                } else if (tipo == 2) {
                    string nome, area;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Área: ";
                    getline(cin, area);

                    novo = new Professor(id, nome, area);

                } else {
                    cout << "Tipo inválido!\n";
                    break;
                }

                if (lnao.alterarPeloId(id, novo)) {
                    cout << "Alterado com sucesso!\n";
                } else {
                    cout << "Falha ao alterar!\n";
                    delete novo;
                }
                break;
            }
            case 8:
                cout << "====== ELEMENTOS NA LISTA ======\n";
                lnao.imprimirTodos();
                break;
            case 9: break;
            default: cout << "Opção inválida!\n";
        }

        if(opcao != 9) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 9);
}

void menuListaOrdenada() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== LISTA ORDENADA ==========\n";
        cout << "1. Inserir\n";
        cout << "2. Remover por ID\n";
        cout << "3. Buscar por ID\n";
        cout << "4. Alterar por ID\n";
        cout << "5. Imprimir todos\n";
        cout << "6. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();

                Elemento* e = criarElementoComIdValido(tipo);
                if(lord.inserir(e)) {
                    cout << "Inserido com sucesso!\n";
                } else {
                    cout << "Falha ao inserir (ID duplicado ou lista cheia)!\n";
                    delete e;
                }
                break;
            }
            case 2: {
                int id;
                cout << "ID para remover: ";
                cin >> id;
                limparBuffer();

                if(lord.removerPeloId(id)) {
                    cout << "Removido com sucesso!\n";
                } else {
                    cout << "ID não encontrado!\n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "ID para buscar: ";
                cin >> id;
                limparBuffer();

                if (const Elemento* elem = lord.buscarPeloId(id)) {
                    elem->imprimirInfo();
                } else {
                    cout << "Elemento não encontrado!\n";
                }
                break;
            }
            case 4: {
                int id;
                cout << "ID para alterar: ";
                cin >> id;
                limparBuffer();

                if (!lord.buscarPeloId(id)) {
                    cout << "ID não encontrado!\n";
                    break;
                }

                int tipo;
                cout << "Novo tipo (1-Aluno 2-Professor): ";
                cin >> tipo;
                limparBuffer();

                Elemento* novo = nullptr;

                if (tipo == 1) {
                    string nome;
                    int matricula;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Matrícula: ";
                    cin >> matricula;
                    limparBuffer();

                    novo = new Aluno(id, nome, matricula);

                } else if (tipo == 2) {
                    string nome, area;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Área: ";
                    getline(cin, area);

                    novo = new Professor(id, nome, area);

                } else {
                    cout << "Tipo inválido!\n";
                    break;
                }

                if (lord.alterarPeloId(id, novo)) {
                    cout << "Alterado com sucesso!\n";
                } else {
                    cout << "Falha ao alterar!\n";
                    delete novo;
                }
                break;
            }
            case 5:
                cout << "====== ELEMENTOS NA LISTA ======\n";
                lord.imprimirTodos();
                break;
            case 6: break;
            default: cout << "Opção inválida!\n";
        }
        if(opcao != 6) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 6);
}

void menuPilha() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== PILHA ==========\n";
        cout << "1. Empilhar\n";
        cout << "2. Desempilhar\n";
        cout << "3. Consultar topo\n";
        cout << "4. Imprimir todos\n";
        cout << "5. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();

                Elemento* e = criarElementoComIdValido(tipo);
                if(pilha.empilhar(e)) {
                    cout << "Empilhado com sucesso!\n";
                } else {
                    cout << "Falha ao empilhar (pilha cheia)!\n";
                    delete e;
                }
                break;
            }
            case 2:
                if(pilha.desempilhar()) {
                    cout << "Desempilhado com sucesso!\n";
                } else {
                    cout << "Pilha vazia!\n";
                }
                break;
            case 3:
                if(const Elemento* topo = pilha.consultarTopo()) {
                    cout << "Elemento no topo:\n";
                    topo->imprimirInfo();
                } else {
                    cout << "Pilha vazia!\n";
                }
                break;
            case 4: {
                cout << "====== ELEMENTOS NA PILHA (TOPO → BASE) ======\n";
                
                Pilha temp;
                while (!pilha.pilhaVazia()) {
                    const Elemento* topo = pilha.consultarTopo();
                    topo->imprimirInfo();
                    temp.empilhar(const_cast<Elemento*>(topo));
                    pilha.removerTopoSemDeletar();  // NÃO deleta
                }

                // Restaurar a pilha original
                while (!temp.pilhaVazia()) {
                    pilha.empilhar(const_cast<Elemento*>(temp.consultarTopo()));
                    temp.removerTopoSemDeletar();
                }
                break;
            }
            case 5:
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
        if(opcao != 5) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 5);
}

void menuFila() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== FILA ==========\n";
        cout << "1. Fila Básica\n";
        cout << "2. Fila Circular\n";
        cout << "3. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        if(opcao == 1) {
            int op;
            do {
                system("cls || clear");
                cout << "========== FILA BÁSICA ==========\n";
                cout << "1. Enfileirar\n";
                cout << "2. Desenfileirar\n";
                cout << "3. Consultar frente\n";
                cout << "4. Imprimir todos\n";
                cout << "5. Voltar\n";
                cout << "Escolha uma opção: ";
                cin >> op;
                limparBuffer();

                switch(op) {
                    case 1: {
                        int tipo;
                        cout << "1. Aluno\n2. Professor\nEscolha: ";
                        cin >> tipo;
                        limparBuffer();

                        Elemento* e = criarElementoComIdValido(tipo);
                        if(filaB.enfileirar(e)) {
                            cout << "Enfileirado com sucesso!\n";
                        } else {
                            cout << "Falha ao enfileirar (fila cheia)!\n";
                            delete e;
                        }
                        break;
                    }
                    case 2:
                        if(filaB.desenfileirar()) {
                            cout << "Desenfileirado com sucesso!\n";
                        } else {
                            cout << "Fila vazia!\n";
                        }
                        break;
                    case 3:
                        if(const Elemento* frente = filaB.frente()) {
                            cout << "Elemento na frente:\n";
                            frente->imprimirInfo();
                        } else {
                            cout << "Fila vazia!\n";
                        }
                        break;
                    case 4:
                        cout << "====== ELEMENTOS NA FILA ======\n";
                        filaB.imprimirTodos();
                        break;
                    case 5: break;
                    default: cout << "Opção inválida!\n";
                }
                if(op != 5) {
                    cout << "\nPressione Enter para continuar...";
                    cin.get();
                }
            } while(op != 5);
        }

        else if(opcao == 2) {
            int op;
            do {
                system("cls || clear");
                cout << "========== FILA CIRCULAR ==========\n";
                cout << "1. Enfileirar\n";
                cout << "2. Desenfileirar\n";
                cout << "3. Consultar frente\n";
                cout << "4. Imprimir todos\n";
                cout << "5. Voltar\n";
                cout << "Escolha uma opção: ";
                cin >> op;
                limparBuffer();

                switch(op) {
                    case 1: {
                        int tipo;
                        cout << "1. Aluno\n2. Professor\nEscolha: ";
                        cin >> tipo;
                        limparBuffer();

                        Elemento* e = criarElementoComIdValido(tipo);
                        if(filaC.enfileirar(e)) {
                            cout << "Enfileirado com sucesso!\n";
                        } else {
                            cout << "Falha ao enfileirar (fila cheia)!\n";
                            delete e;
                        }
                        break;
                    }
                    case 2:
                        if(filaC.desenfileirar()) {
                            cout << "Desenfileirado com sucesso!\n";
                        } else {
                            cout << "Fila vazia!\n";
                        }
                        break;
                    case 3:
                        if(const Elemento* frente = filaC.frente()) {
                            cout << "Elemento na frente:\n";
                            frente->imprimirInfo();
                        } else {
                            cout << "Fila vazia!\n";
                        }
                        break;
                    case 4:
                        cout << "====== ELEMENTOS NA FILA CIRCULAR ======\n";
                        filaC.imprimirTodos();
                        break;
                    case 5: break;
                    default: cout << "Opção inválida!\n";
                }
                if(op != 5) {
                    cout << "\nPressione Enter para continuar...";
                    cin.get();
                }
            } while(op != 5);
        }
        else if(opcao != 3) {
            cout << "Opção inválida!\n";
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 3);
}

int main() {
    menuPrincipal();
    return 0;
}
