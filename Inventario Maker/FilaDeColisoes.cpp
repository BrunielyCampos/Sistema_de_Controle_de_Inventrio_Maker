#include "FilaDeColisoes.hpp"
#include <iostream>

using namespace std;

FilaDeColisoes::FilaDeColisoes() : frente(nullptr), tras(nullptr) {}

void FilaDeColisoes::enfileirar(const string& nome, const string& matricula) {
    No* novo = new No;
    novo->nome = nome;
    novo->matricula = matricula;
    novo->proximo = nullptr;

    if (tras == nullptr) {
        frente = novo;
        tras = novo;
    } else {
        tras->proximo = novo;
        tras = novo;
    }
}

void FilaDeColisoes::desenfileirar() {
    if (frente == nullptr) return;

    No* temp = frente;
    frente = frente->proximo;
    delete temp;

    if (frente == nullptr) {
        tras = nullptr;
    }
}
