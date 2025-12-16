#ifndef ITENS_HPP
#define ITENS_HPP

#include <string>
#include <iostream>
#include "FilaDeEspera.hpp"

using namespace std;

class Itens {
private:
    int id;
    string nome;
    string categoria;
    string localizacao;
    int quantidade;
    string condicao;
    FilaDeEspera filaEspera;

public:
    Itens();
    Itens(int id, string nome, string cat, string loc, int qtd, string cond);
    ~Itens();

    int getId() const;
    string getNome() const;
    string getCategoria() const;
    int getQuantidade() const;
    string getCondicao() const;
    
    // Retorna referência para podermos ver a fila sem copiar
    const FilaDeEspera& getFilaEspera() const;

    // Métodos de negócio
    bool solicitarItem(Usuario* u); // Recebe ponteiro
    void devolverItem();
    void imprimirDetalhes();
};

#endif