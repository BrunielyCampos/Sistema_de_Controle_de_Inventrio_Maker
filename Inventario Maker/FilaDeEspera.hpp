#include "Usuario.hpp"

#ifndef FILADEESPERA_HPP
#define FILADEESPERA_HPP

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
    ~FilaDeEspera();

    void inserirNoFim(Usuario* usuario);
    Usuario* removerDoInicio();
    bool EstaCheio() const;
    bool EstaVazio() const;
    void imprimirFila();
};

#endif