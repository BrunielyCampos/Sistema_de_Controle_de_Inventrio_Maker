#include "Itens.hpp"

Itens::Itens() {
    id = -1;
    quantidade = 0;
}

Itens::Itens(int id, string nome, string cat, string loc, int qtd, string cond) {
    this->id = id;
    this->nome = nome;
    this->categoria = cat;
    this->localizacao = loc;
    this->quantidade = qtd;
    this->condicao = cond;
}

Itens::~Itens() {
    // O destrutor da filaEspera é chamado automaticamente
}

int Itens::getId() const { return id; }
string Itens::getNome() const { return nome; }
string Itens::getCategoria() const { return categoria; }
int Itens::getQuantidade() const { return quantidade; }
string Itens::getCondicao() const { return condicao; }

const FilaDeEspera& Itens::getFilaEspera() const {
    return filaEspera;
}

bool Itens::solicitarItem(Usuario* u) {
    if (quantidade > 0) {
        quantidade--;
        cout << "Item retirado com sucesso por " << u->getNome() << "." << endl;
        return true;
    } else {
        cout << "Sem estoque. " << u->getNome() << " entrou na fila de espera." << endl;
        filaEspera.inserir(u);
        return false;
    }
}

void Itens::devolverItem() {
    quantidade++;
    cout << "Item devolvido. Estoque atual: " << quantidade << endl;

    if (!filaEspera.vazia()) {
        Usuario* proximo = filaEspera.remover();
        if (proximo != NULL) {
            cout << ">>> NOTIFICACAO: " << proximo->getNome() 
                 << ", o item '" << nome << "' ja esta disponivel para voce!" << endl;
            // Opcional: Já reservar automaticamente decrementando a quantidade novamente
            // quantidade--; 
        }
    }
}

void Itens::imprimirDetalhes() {
    cout << "--------------------------------" << endl;
    cout << "ID: " << id << " | Nome: " << nome << endl;
    cout << "Categoria: " << categoria << " | Local: " << localizacao << endl;
    cout << "Qtd: " << quantidade << " | Condicao: " << condicao << endl;
    cout << "Fila de Espera: ";
    filaEspera.imprimir(); // Tinha faltado implementar a impressao na fila
    cout << "--------------------------------" << endl;
}