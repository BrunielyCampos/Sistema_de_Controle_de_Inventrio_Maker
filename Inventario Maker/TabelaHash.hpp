#ifndef TABELAHASH_HPP
#define TABELAHASH_HPP

#include "Itens.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estrutura para os nós da tabela hash
struct NoTabela {
    Itens item;
    NoTabela* proximo;
    
    NoTabela(const Itens& item) : item(item), proximo(nullptr) {}
};

class TabelaHash {
private:
    int tamanho;           // Tamanho atual da tabela
    int quantidadeItens;   // Número de itens na tabela
    NoTabela** tabela;     // Array de ponteiros para listas encadeadas

    // Constante para fator de carga máximo (0.75 é um bom valor padrão)
    const float FATOR_CARGA_LIMITE = 0.75f;

    // Métodos auxiliares
    int funcaoHash(int chave) const;
    void rehash();
    bool ehPrimo(int n) const;
    int proximoPrimo(int n) const;

public:
    TabelaHash(int tamInicial = 7);
    ~TabelaHash();

    // Operações principais
    void inserir(const Itens& novoItem);
    bool remover(int id);
    Itens* buscar(int id);
    
    // Operações de consulta
    void listarPorCategoria(const string& categoria) const;
    void imprimirTabela() const;
    
    // Getters
    int getTamanho() const { return tamanho; }
    int getQuantidadeItens() const { return quantidadeItens; }
};

#endif