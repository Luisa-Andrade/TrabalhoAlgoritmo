# Trabalho de Programação Orientada a Objetos

## Objetivo

Este trabalho visa a aplicação prática dos quatro pilares da Programação Orientada a Objetos (Abstração, Encapsulamento, Herança e Polimorfismo) na implementação de estruturas de dados clássicas em C++. O sistema implementado é coeso, reutilizável e robusto, seguindo boas práticas da orientação a objetos.

---

## Estrutura do Projeto

- `include/` — arquivos `.h` contendo as declarações das classes.
- `src/` — arquivos `.cpp` com as implementações.
- `main.cpp` — programa principal para testes e demonstração.
- `README.md` — documentação do projeto.

---

## Parte I — Implementações com Alocação Sequencial

### Hierarquia Elemento

- **Elemento** (classe abstrata)
  - Atributo protegido `id` (tipo `int`)
  - Método público `getID() const`
  - Método virtual puro `imprimirInfo() const = 0` para obrigar implementação em classes concretas
- Classes concretas que herdam de Elemento:
  - **Aluno** — atributos: `nome`, `matricula`
  - **Professor** — atributos: `nome`, `area`

Essas classes servem para demonstrar o polimorfismo e armazenamento heterogêneo nas estruturas de dados.

---

### Lista Não Ordenada

- Métodos: 
  - `inserirNoInicio`, `inserirNoFinal`
  - `removerPrimeiro`, `removerUltimo`
  - `removerPeloId`, `buscarPeloId`, `alterarPeloId`
- Implementação: array estático de ponteiros para `Elemento`.
- Complexidades:
  - Inserir no início: O(n) (desloca elementos)
  - Inserir no final: O(1)
  - Remover primeiro: O(n)
  - Remover último: O(1)
  - Buscar/remover/alterar pelo ID: O(n)

---

### Lista Ordenada

- Mesmos métodos da lista não ordenada, mas mantendo a ordem crescente pelo `id`.
- Busca implementada via busca binária para otimizar para O(log n).
- Inserções mantêm a ordem deslocando elementos.
- Complexidades:
  - Inserir: O(n)
  - Buscar: O(log n)
  - Remover: O(n)

---

### Pilha (Stack)

- Implementada via composição usando a Lista Não Ordenada.
- Métodos expostos:
  - `empilhar` (push)
  - `desempilhar` (pop)
  - `consultarTopo` (top)
  - `pilhaCheia`, `pilhaVazia`
- Todas as operações mapeadas para métodos da lista subjacente.

---

### Fila (Queue)

#### Implementação básica (FilaBasica)

- Composição com Lista Não Ordenada.
- Operação `desenfileirar` faz remoção do primeiro elemento (O(n)).
- Operação `enfileirar` insere no final (O(1)).
- Ineficiência devido ao deslocamento na remoção.

#### Implementação otimizada (FilaCircular)

- Usa array circular fixo (tamanho 100).
- Ponteiros para Elemento gerenciados circularmente.
- Todas as operações: enfileirar, desenfileirar, consultar frente, pilhaCheia e pilhaVazia são O(1).
- Resolve problema da fila básica.

---

## Parte II — Implementações com Alocação Encadeada

*(Ainda não implementado — pode ser estendido conforme requisitos futuros)*

---

## Decisões de Design

- Uso extensivo de polimorfismo para permitir armazenar objetos heterogêneos em uma mesma estrutura.
- Classes abstratas e virtuais puras para garantir implementação correta dos métodos essenciais.
- Gerenciamento manual de memória (`new` e `delete`) para cada elemento inserido/removido.
- Separação clara entre declarações (`.h`) e implementações (`.cpp`).
- Uso de composição para construir Pilha e Fila a partir das listas existentes, facilitando reaproveitamento de código.

---

## Complexidade das Estruturas e Operações

| Estrutura          | Operação           | Complexidade   |
|--------------------|--------------------|---------------|
| Lista Não Ordenada  | Inserir no início  | O(n)          |
|                    | Inserir no final   | O(1)          |
|                    | Remover primeiro   | O(n)          |
|                    | Remover último     | O(1)          |
|                    | Buscar/Alterar/Remover pelo ID | O(n)          |
| Lista Ordenada      | Inserir            | O(n)          |
|                    | Buscar             | O(log n)      |
|                    | Remover            | O(n)          |
| Pilha               | Empilhar           | O(1)          |
|                    | Desempilhar        | O(1)          |
|                    | Consultar topo     | O(1)          |
| Fila Básica         | Enfileirar         | O(1)          |
|                    | Desenfileirar      | O(n)          |
| Fila Circular       | Enfileirar         | O(1)          |
|                    | Desenfileirar      | O(1)          |

---

## Como Compilar e Executar

```bash
g++ -std=c++11 main.cpp src/*.cpp -Iinclude -o trabalhoPOO
./trabalhoPOO
