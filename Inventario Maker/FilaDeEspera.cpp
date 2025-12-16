#include "FilaDeEspera.hpp"
#include <iostream>

FilaDeEspera::FilaDeEspera() {
    inicio = NULL;
    fim = NULL;
}

FilaDeEspera::~FilaDeEspera() {
   while (inicio != NULL) {
        NoUsuario* temp = inicio;
        inicio = inicio->proximo;
        delete temp;
    }
}

void FilaDeEspera::inserirNoFim(Usuario* Usuario) {
    NoUsuario* novoUsuario = new NoUsuario();
    novoUsuario->usuario = Usuario;
    novoUsuario->proximo = NULL;

    if (fim == NULL) {
        inicio = novoUsuario;
        fim = novoUsuario;
    } else {
        fim->proximo = novoUsuario;
        fim = novoUsuario;
    }
    
}

    Usuario* FilaDeEspera::removerDoInicio() {
    if (inicio == NULL) {
        return NULL;
    }
    NoUsuario* temp = inicio;
    Usuario* Usuario = temp->usuario;
    inicio = inicio->proximo;
    delete temp;
    return Usuario;
    }   

bool FilaDeEspera::EstaCheio() const {
    return fim != NULL;
}