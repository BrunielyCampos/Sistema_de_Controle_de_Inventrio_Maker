#include "TabelaHash.hpp"
#include <iostream>

using namespace std;

bool TabelaHash::ehPrimo(int n) const {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int TabelaHash::proximoPrimo(int n) const {
    if (n <= 1) return 2;
    int primo = n;
    while (true) {
        primo++;
        if (ehPrimo(primo)) return primo;
    }
}

int TabelaHash::funcaoHash(int chave) const {
    return chave % tamanho;
}

TabelaHash::TabelaHash(int tamInicial) {
    tamanho = tamInicial;
    quantidadeItens = 0;
    if (!ehPrimo(tamanho)) {
        tamanho = proximoPrimo(tamanho);
    }
    tabela = new NoTabela*[tamanho];
    for (int i = 0; i < tamanho; i++) {
        tabela[i] = NULL;
    }
}

TabelaHash::~TabelaHash() {
    for (int i = 0; i < tamanho; i++) {
        NoTabela* atual = tabela[i];
        while (atual != NULL) {
            NoTabela* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
    delete[] tabela;
}

void TabelaHash::rehash() {
    cout << "\n[SISTEMA] Realizando Rehash... (Tamanho antigo: " << tamanho << ")" << endl;
    
    int tamanhoAntigo = tamanho;
    NoTabela** tabelaAntiga = tabela;

    tamanho = proximoPrimo(tamanho * 2);
    tabela = new NoTabela*[tamanho];
    for (int i = 0; i < tamanho; i++) tabela[i] = NULL;
    
    quantidadeItens = 0; // Será incrementado no inserir

    for (int i = 0; i < tamanhoAntigo; i++) {
        NoTabela* atual = tabelaAntiga[i];
        while (atual != NULL) {
            inserir(atual->item); // Isso usa o construtor de cópia do Item e da Fila
            NoTabela* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
    delete[] tabelaAntiga;
    cout << "[SISTEMA] Rehash concluido. (Novo tamanho: " << tamanho << ")\n" << endl;
}

void TabelaHash::inserir(const Itens& novoItem) {
    // Insere sem checar carga primeiro para evitar recursão infinita no rehash
    // Mas num uso normal, checamos antes
    
    int indice = funcaoHash(novoItem.getId());
    
    NoTabela* atual = tabela[indice];
    while(atual != NULL) {
        if(atual->item.getId() == novoItem.getId()) {
            cout << "Erro: Item ID " << novoItem.getId() << " ja existe." << endl;
            return;
        }
        atual = atual->proximo;
    }

    NoTabela* novoNo = new NoTabela(novoItem);
    novoNo->proximo = tabela[indice];
    tabela[indice] = novoNo;
    quantidadeItens++;

    if ((float)quantidadeItens / tamanho > FATOR_CARGA_LIMITE) {
        rehash();
    }
}

// Retorna um ponteiro para o item (ou nullptr se não encontrado)
// Permite manipulação direta do item (solicitar/devolver)
Itens* TabelaHash::buscar(int id) {
    int indice = funcaoHash(id);
    NoTabela* atual = tabela[indice];
    while (atual != NULL) {
        if (atual->item.getId() == id) {
            return &(atual->item);
        }
        atual = atual->proximo;
    }
    return NULL;
}

bool TabelaHash::remover(int id) {
    int indice = funcaoHash(id);
    NoTabela* atual = tabela[indice];
    NoTabela* anterior = NULL;

    while (atual != NULL) {
        if (atual->item.getId() == id) {
            if (anterior == NULL) {
                tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            delete atual;
            quantidadeItens--;
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

void TabelaHash::listarPorCategoria(string categoria) {
    cout << "\n--- Itens da Categoria: " << categoria << " ---" << endl;
    bool achou = false;
    for (int i = 0; i < tamanho; i++) {
        NoTabela* atual = tabela[i];
        while (atual != NULL) {
            if (atual->item.getCategoria() == categoria) {
                atual->item.imprimir();
                achou = true;
            }
            atual = atual->proximo;
        }
    }
    if (!achou) cout << "Nenhum item encontrado." << endl;
}

void TabelaHash::imprimirTabela() {
    cout << "\n--- Estrutura da Hash Table (Debug) ---" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << "[" << i << "]: ";
        NoTabela* atual = tabela[i];
        while (atual != NULL) {
            cout << atual->item.getNome() << "(" << atual->item.getId() << ") -> ";
            atual = atual->proximo;
        }
        cout << "NULL" << endl;
    }
}