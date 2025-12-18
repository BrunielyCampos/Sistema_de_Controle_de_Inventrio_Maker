#include "FilaDeEspera.hpp"

FilaDeEspera::FilaDeEspera() {
    inicio = nullptr;
    fim = nullptr;
}

FilaDeEspera::FilaDeEspera(const FilaDeEspera& outra) {
    inicio = nullptr;
    fim = nullptr;
    NoUsuario* atual = outra.inicio;
    while (atual != nullptr) {
        this->inserir(atual->usuario);
        atual = atual->proximo;
    }
}

FilaDeEspera::~FilaDeEspera() {
    while (inicio != nullptr) {
        NoUsuario* temp = inicio;
        inicio = inicio->proximo;
        delete temp;
    }
}

void FilaDeEspera::inserir(Usuario* u) {
    NoUsuario* novo = new NoUsuario();
    novo->usuario = u;
    novo->proximo = nullptr;

    if (fim == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }
}

Usuario* FilaDeEspera::remover() {
    if (inicio == nullptr) return nullptr;

    NoUsuario* temp = inicio;
    Usuario* u = temp->usuario;
    inicio = inicio->proximo;

    if (inicio == nullptr) fim = nullptr;

    delete temp;
    return u;
}

bool FilaDeEspera::estaVazia() const {
    return inicio == nullptr;
}

bool FilaDeEspera::estaCheio() const {
    return false; 
}

void FilaDeEspera::imprimir() const {
    NoUsuario* atual = inicio;
    if (!atual) {
        cout << " (Vazia)";
    }
    while (atual != nullptr) {
        cout << "[" << atual->usuario->getNome() << "] ";
        atual = atual->proximo;
    }
    cout << endl;
}