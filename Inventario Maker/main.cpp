#include <iostream>
#include "TabelaHash.hpp"
#include "Usuario.hpp"

using namespace std;

void imprimirTituloSeção(string titulo){
    cout<<"=========================================="<<endl;
    cout<< titulo <<endl;
    cout<<"=========================================="<<endl;
    
}

int main() {
  
    Usuario usuario("123", "Usuario Teste", "2023001", ALUNO);
    

    TabelaHash inventario(7);
    
   
    inventario.inserir(Itens(101, "Arduino Uno", "Eletronica", "Armario A", 3, "Novo"));
    inventario.inserir(Itens(102, "Multimetro", "Eletronica", "Armario A", 2, "Usado"));
    inventario.inserir(Itens(201, "Impressora 3D", "Impressao", "Bancada 1", 1, "Novo"));
    

    cout << "=== TESTANDO BUSCA ===" << endl;
    Itens* item = inventario.buscar(101);
    if (item) {
        cout << "Item encontrado:" << endl;
        item->imprimir();
    }
    
   
    cout << "\n=== TESTANDO SOLICITACAO ===" << endl;
    item = inventario.buscar(101);
    if (item) {
        cout << "Solicitando Arduino Uno..." << endl;
        item->solicitarItem(&usuario);
        item->imprimir();
    }
    
    cout << "\n=== ITENS DE ELETRONICA ===" << endl;
    inventario.listarPorCategoria("Eletronica");
    
 
    cout << "\n=== REMOVENDO ITEM 102 ===" << endl;
    if (inventario.remover(102)) {
        cout << "Item 102 removido com sucesso!" << endl;
    }
    
    cout << "\n=== TODOS OS ITENS ===" << endl;
    inventario.imprimirTabela();


    cout<<"SEÇÃO DE DEMONSTRAÇÃO DAS FUNCIONALIDADES DE: \n";
    cout<<"     REHASH E TRATAMENTO DE COLISÕES"<<endl;

    TabelaHash tabelaTeste(7);

    imprimirTituloSeção("=== Demonstração de Colisão: ===");

    cout<<"Inserindo o Display Digital com o ID(7) com o modulo =  (Hash: 7 % 7 = 0)";

    tabelaTeste.inserir(Itens(7, "Display Digital", "Eletronica", "Armario B", 2,  ))


    
    return 0;
}