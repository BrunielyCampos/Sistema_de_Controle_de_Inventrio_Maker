#include "TabelaHash.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// Verifica se um número é primo
bool TabelaHash::ehPrimo(int n) const {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Encontra o próximo número primo maior ou igual a n
int TabelaHash::proximoPrimo(int n) const {
    if (n <= 1) return 2;
    
    int primo = n;
    bool encontrou = false;
    
    while (!encontrou) {
        primo++;
        if (ehPrimo(primo)) {
            encontrou = true;
        }
    }
    return primo;
}

// Função hash simples que retorna o resto da divisão da chave pelo tamanho da tabela
int TabelaHash::funcaoHash(int chave) const {
    return chave % tamanho;
}

// Construtor: inicializa a tabela com um tamanho inicial
TabelaHash::TabelaHash(int tamInicial) {
    tamanho = tamInicial;
    quantidadeItens = 0;
    
    // Garante que o tamanho seja um número primo
    if (!ehPrimo(tamanho)) {
        tamanho = proximoPrimo(tamanho);
    }
    
    // Aloca o array de ponteiros
    tabela = new NoTabela*[tamanho];
    
    // Inicializa todos os ponteiros como nullptr
    for (int i = 0; i < tamanho; i++) {
        tabela[i] = nullptr;
    }
}

// Destrutor: libera toda a memória alocada
TabelaHash::~TabelaHash() {
    for (int i = 0; i < tamanho; i++) {
        NoTabela* atual = tabela[i];
        while (atual != nullptr) {
            NoTabela* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
    }
    delete[] tabela;
}

// Aumenta o tamanho da tabela quando o fator de carga é excedido
void TabelaHash::rehash() {
    int novoTamanho = proximoPrimo(tamanho * 2);
    NoTabela** novaTabela = new NoTabela*[novoTamanho];
    
    // Inicializa a nova tabela
    for (int i = 0; i < novoTamanho; i++) {
        novaTabela[i] = nullptr;
    }
    
    int tamanhoAntigo = tamanho;
    NoTabela** tabelaAntiga = tabela;
    
    // Atualiza os parâmetros da tabela
    tamanho = novoTamanho;
    tabela = novaTabela;
    quantidadeItens = 0;
    
    // Reinsere todos os itens na nova tabela
    for (int i = 0; i < tamanhoAntigo; i++) {
        NoTabela* atual = tabelaAntiga[i];
        while (atual != nullptr) {
            inserir(atual->item);
            NoTabela* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
    
    delete[] tabelaAntiga;
}

// Insere um novo item na tabela
void TabelaHash::inserir(const Itens& novoItem) {
    // Verifica se é necessário fazer rehashing
    if ((float)quantidadeItens / tamanho > FATOR_CARGA_LIMITE) {
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