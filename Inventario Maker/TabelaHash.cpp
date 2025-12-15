#include "TabelaHash.hpp"
#include <iostream>
using namespace std;

bool TabelaHash::ehPrimo(int n){
    if (n <= 1){
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0){
            return false;
        }
        return true;
    }
}

int TabelaHash::proximoPrimo(int n) {
    while (!ehPrimo(n)) n++;
    return n;
}

int TabelaHash::funcaoHash(int chave) {
    return chave % tamanho;
}

// --- CONSTRUTOR E DESTRUTOR ---

TabelaHash::TabelaHash(int tamInicial) {
    tamanho = proximoPrimo(tamInicial);
    quantidadeItens = 0;
    int tabela;
    
    // Aloca o array de ponteiros
    tabela = new NoTabela*[tamanho];
    
    // Inicializa tudo com nullptr (listas vazias)
    for (int i = 0; i < tamanho; i++) {
        tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash() {
    for (int i = 0; i < tamanho; i++) {
        NoTabela* atual = tabela[i];
        while (atual != nullptr) {
            NoTabela* remover = atual;
            atual = atual->proximo;
            delete remover;
        }
    }
    delete[] tabela;
}

// --- REHASHING (A Parte Complexa e Importante) ---

void TabelaHash::rehash() {
    int tamanhoAntigo = tamanho;
    int novoTamanho = proximoPrimo(tamanho * 2);
    
    cout << "\n[SISTEMA] Fator de carga excedido. Realizando Rehashing..." << endl;
    cout << "          Tamanho antigo: " << tamanhoAntigo << " -> Novo: " << novoTamanho << endl;

    // Salva a tabela antiga
    NoTabela** tabelaAntiga = tabela;

    // Cria a nova tabela
    tabela = new NoTabela*[novoTamanho];
    for (int i = 0; i < novoTamanho; i++) {
        tabela[i] = nullptr;
    }

    // Atualiza o tamanho e reseta a contagem (será recontada no inserir)
    tamanho = novoTamanho;
    quantidadeItens = 0;

    // Transfere os itens
    for (int i = 0; i < tamanhoAntigo; i++) {
        NoTabela* atual = tabelaAntiga[i];
        while (atual != nullptr) {
            // Insere na nova tabela (vai recalcular o hash com o novo tamanho)
            inserir(atual->item); 
            
            NoTabela* temp = atual;
            atual = atual->proximo;
            delete temp; // Deleta o nó antigo (o item foi copiado para o novo nó)
        }
    }
    delete[] tabelaAntiga; // Deleta o vetor antigo
}

// --- OPERAÇÕES PRINCIPAIS ---

void TabelaHash::inserir(Item novoItem) {
    // 1. Verifica fator de carga antes de inserir
    float carga = (float)quantidadeItens / tamanho;
    if (carga > FATOR_CARGA_LIMITE) {
        rehash();
    }

    int indice = funcaoHash(novoItem.getId());
    
    // Verifica se já existe (atualização ou erro) - Opcional, aqui vamos assumir inserção direta
    // Colisão: Inserção no início da lista (O(1))
    NoTabela* novoNo = new NoTabela(novoItem);
    novoNo->proximo = tabela[indice];
    tabela[indice] = novoNo;
    
    quantidadeItens++;
}

Item* TabelaHash::buscar(int id) {
    int indice = funcaoHash(id);
    NoTabela* atual = tabela[indice];

    while (atual != nullptr) {
        if (atual->item.getId() == id) {
            return &(atual->item); // Retorna o endereço do item original
        }
        atual = atual->proximo;
    }
    return nullptr; // Não achou
}

bool TabelaHash::remover(int id) {
    int indice = funcaoHash(id);
    NoTabela* atual = tabela[indice];
    NoTabela* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->item.getId() == id) {
            // Achou o item a ser removido
            if (anterior == nullptr) {
                // É o primeiro da lista
                tabela[indice] = atual->proximo;
            } else {
                // Está no meio ou fim
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
    cout << "--- Itens da Categoria: " << categoria << " ---" << endl;
    for (int i = 0; i < tamanho; i++) {
        NoTabela* atual = tabela[i];
        while (atual != nullptr) {
            if (atual->item.getCategoria() == categoria) {
                atual->item.imprimirDetalhes();
            }
            atual = atual->proximo;
        }
    }
}

void TabelaHash::imprimirTabela() {
    cout << "\n--- Estrutura da Hash Table ---" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << "[" << i << "]: ";
        NoTabela* atual = tabela[i];
        while (atual != nullptr) {
            cout << atual->item.getNome() << " (ID:" << atual->item.getId() << ") -> ";
            atual = atual->proximo;
        }
        cout << "NULL" << endl;
    }
}