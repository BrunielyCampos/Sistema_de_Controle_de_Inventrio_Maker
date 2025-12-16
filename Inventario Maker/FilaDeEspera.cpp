#include "FilaDeEspera.hpp"

FilaDeEspera::FilaDeEspera() {
    inicio = NULL;
    fim = NULL;
}


FilaDeEspera::FilaDeEspera(const FilaDeEspera& outra) {
    inicio = NULL;
    fim = NULL;
    NoUsuario* atual = outra.inicio;
    while (atual != NULL) {
        this->inserir(atual->usuario);
        atual = atual->proximo;
    }
}

FilaDeEspera::~FilaDeEspera() {
    while (inicio != NULL) {
        NoUsuario* temp = inicio;
        inicio = inicio->proximo;
        delete temp;
    }
}

void FilaDeEspera::inserir(Usuario* u) {
    NoUsuario* novo = new NoUsuario();
    novo->usuario = u;
    novo->proximo = NULL;

    if (fim == NULL) {
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }
}

Usuario* FilaDeEspera::remover() {
    if (inicio == NULL) return NULL;

    NoUsuario* temp = inicio;
    Usuario* u = temp->usuario;
    inicio = inicio->proximo;

    if (inicio == NULL) fim = NULL;

    delete temp;
    return u;
}

bool FilaDeEspera::vazia() const {
    return inicio == NULL;
}

bool FilaDeEspera::estaCheio() const {
    return false; 
}

void FilaDeEspera::imprimir() const {
    NoUsuario* atual = inicio;
    if (!atual) {
        cout << " (Vazia)";
    }
    while (atual != NULL) {
        cout << "[" << atual->usuario->getNome() << "] ";
        atual = atual->proximo;
    }
    cout << endl;
}