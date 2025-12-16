#include <iostream>
#include "Itens.hpp"


using namespace std;

    Itens::Itens(){

    }
    Itens::Itens(int id, string nome, string cat, string loc, int qtd, string cond){
        this->id = id;
        this->nome = nome;
        categoria = cat;
        localizacao = loc;
        quantidade = qtd;
        condicao = cond;
    }
    Itens::~Itens(){

    }

    int Itens::getId() const{
        return id;
    }
    string Itens::getNome() const{
        return nome;
    }
    string Itens::getCategoria() const{
        return categoria;
    }
    int Itens::getQuantidade() const{
        return quantidade;
    }
    string Itens::getCondicao() const {
        return condicao;
    }
    FilaDeEspera Itens::getFilaEspera() const {
        return filaEspera;
    }

    bool Itens::solicitarItem(Usuario u) {
        if (quantidade > 0) {
            quantidade--;
            return true;
        } else {
            // Adiciona à fila de espera se não houver itens disponíveis
            filaEspera.inserir(u);
            return false;
        }
    }

    void Itens::devolverItem() {
        quantidade++;
        
        // Verifica se há alguém na fila de espera quando um item é devolvido
        if (!filaEspera.vazia()) {
            Usuario proximo = filaEspera.remover();
            cout << "\nNotificação: " << proximo.getNome() << ", o item " << nome 
                 << " está disponível para retirada!" << endl;
        }
        
    }    
    void Itens::imprimirDetalhes(){
        cout << "ID: " << id << endl;
        cout << "Nome: " << nome << endl;
        cout << "Categoria: " << categoria << endl;
        cout << "Localizacao: " << localizacao << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Condicao: " << condicao << endl;
    }