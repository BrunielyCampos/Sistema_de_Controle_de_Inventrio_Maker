#ifndef FILADEESPERA_HPP
#define FILADEESPERA_HPP

#include "Usuario.hpp"
#include <iostream>

struct NoUsuario {
    Usuario* usuario; // Ponteiro para o usuário (agregacao)
    NoUsuario* proximo;
};

class FilaDeEspera {
private:
    NoUsuario* inicio;
    NoUsuario* fim;

public:
    FilaDeEspera();
    // Importante: Construtor de Cópia para o Rehash funcionar
    FilaDeEspera(const FilaDeEspera& outra); 
    ~FilaDeEspera();

    void inserir(Usuario* u); // Renomeado para bater com seu uso em Itens
    Usuario* remover();       // Renomeado
    bool vazia() const;
    bool estaCheio() const;   // Filas dinâmicas raramente enchem, mas mantive
    void imprimir() const;
};

#endif