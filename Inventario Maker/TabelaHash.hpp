#ifndef TABELAHASH_HPP
#define TABELAHASH_HPP

#include "Itens.hpp"

// Nó para o encadeamento externo da Hash
struct NoTabela {
    Itens item;
    NoTabela* proximo;

    NoTabela(Itens i) : item(i), proximo(NULL) {}
};

class TabelaHash {
private:
    NoTabela** tabela;
    int tamanho;
    int quantidadeItens;
    const float FATOR_CARGA_LIMITE = 0.7;

    bool ehPrimo(int n) const;
    int proximoPrimo(int n) const;
    int funcaoHash(int chave) const;
    void rehash();

public:
    TabelaHash(int tamInicial = 7);
    ~TabelaHash();

    void inserir(const Itens& novoItem);
    // Retorna um ponteiro para o item (ou nullptr se não encontrado)
    // Permite manipulação direta do item (solicitar/devolver)
    Itens* buscar(int id);
    bool remover(int id);
    void listarPorCategoria(string categoria);
    void imprimirTabela(); // Para debug
};

#endif