#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
#include "FilaDeColisoes.hpp"
#include "Usuario.hpp"

using namespace std;

class Itens {
private:
    int id;                
    string categoria;
    string localizacao;
    int quantidade;
    string condicao;  
    FilaDeColisoes filaEspera; 

public:
    
    Itens();
    Itens(int id, string nome, string cat, string loc, int qtd, string cond);

    
    int getId() const;
    string getNome() const;
    string getCategoria() const;
    int getQuantidade() const;

    // Métodos de Negócio
    bool solicitarItem(Usuario u);
    void devolverItem();
    void imprimirDetalhes();
};

#endif
