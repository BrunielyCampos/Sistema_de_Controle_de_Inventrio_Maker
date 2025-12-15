#include "Itens.hpp"
#include <string>

using namespace std;

#ifndef TABELAHASH_HPP
#define TABELAHASH_HPP
class TabelaHash {
private:
    int tamanho;           // Tamanho atual do array (M)
    int quantidadeItens;   // Quantos itens temos no total (N)
         // Vetor de ponteiros (Array de Listas)

    // Constante para definir quando fazer o Rehashing (ex: 0.75)
    const float FATOR_CARGA_LIMITE = 0.75;

    // Métodos Privados (Auxiliares)
    int funcaoHash(int chave);
    void rehash();     // Aumenta a tabela quando fica cheia
    bool ehPrimo(int n);
    int proximoPrimo(int n);

    int NoTabela* tabela;

public:
    TabelaHash(int tamInicial = 7);
    ~TabelaHash();

    // Operações principais do CRUD
    void inserir(Itens novoItem);
    bool remover(int id);
    Itens* buscar(int id);
    
    // Operações extras
    void listarPorCategoria(string categoria);
    void imprimirTabela(); // Para debug
};

#endif