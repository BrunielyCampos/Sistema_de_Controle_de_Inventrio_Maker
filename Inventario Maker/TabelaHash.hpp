#ifndef TABELAHASH_HPP
#define TABELAHASH_HPP

#include "NoTabela.hpp"
#include "Item.hpp"
#include <string>

class TabelaHash {
private:
    int tamanho;           // Tamanho atual do array (M)
    int quantidadeItens;   // Quantos itens temos no total (N)
    NoTabela** tabela;     // Vetor de ponteiros (Array de Listas)

    // Constante para definir quando fazer o Rehashing (ex: 0.75)
    const float FATOR_CARGA_LIMITE = 0.75;

    // Métodos Privados (Auxiliares)
    int funcaoHash(int chave);
    void rehash();     // Aumenta a tabela quando fica cheia
    bool ehPrimo(int n);
    int proximoPrimo(int n);

public:
    TabelaHash(int tamInicial = 7);
    ~TabelaHash();

    // Operações principais do CRUD
    void inserir(Item novoItem);
    bool remover(int id);
    Item* buscar(int id);
    
    // Operações extras
    void listarPorCategoria(std::string categoria);
    void imprimirTabela(); // Para debug
};

#endif