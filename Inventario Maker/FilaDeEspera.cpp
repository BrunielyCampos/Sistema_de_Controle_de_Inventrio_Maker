#include "FilaDeEspera.hpp"
#include <iostream>

FilaDeEspera::FilaDeEspera() {
    inicio = NULL;
    fim = NULL;
}

FilaDeEspera::~FilaDeEspera() {
    while (inicio != NULL) {
        NoItem* temp = inicio;
        inicio = inicio->proximo;
        delete temp;
    }
}

void FilaDeEspera::inserirNoFim(Itens* item) {
    NoItem* novoItem = new NoItem;
    novoItem->item = item;
    novoItem->proximo = NULL;
    if (fim == NULL) {
        inicio = novoItem;
        fim = novoItem;
    } else {
        fim->proximo = novoItem;
        fim = novoItem;
    }
}

Itens* FilaDeEspera::removerDoInicio() {
    if (inicio == NULL) {
        return NULL;
    }
    NoItem* temp = inicio;
    Itens* item = temp->item;
    inicio = inicio->proximo;
    delete temp;
    return item;
}

bool FilaDeEspera::EstaCheio() const {
    return fim != NULL;
}