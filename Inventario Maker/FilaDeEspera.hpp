#ifndef FILADEESPERA_HPP
#define FILADEESPERA_HPP

#include "Usuario.hpp"
#include <iostream>

struct NoUsuario {
    Usuario* usuario; 
    NoUsuario* proximo;
};

class FilaDeEspera {
private:
    NoUsuario* inicio;
    NoUsuario* fim;

public:
    FilaDeEspera();
    FilaDeEspera(const FilaDeEspera& outra); 
    ~FilaDeEspera();

    void inserir(Usuario* u);
    Usuario* remover();       
    bool vazia() const;
    bool estaCheio() const;
    void imprimir() const;
};

#endif