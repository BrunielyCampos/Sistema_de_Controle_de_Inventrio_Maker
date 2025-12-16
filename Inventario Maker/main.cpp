#include <iostream>
#include "TabelaHash.hpp"
#include "Usuario.hpp"

using namespace std;

int main() {
    // Criar usuário padrão para testes
    Usuario usuario("123", "Usuario Teste", "2023001", ALUNO);
    
    // Inicializar a tabela hash
    TabelaHash inventario(10);
    
    // Adicionar alguns itens iniciais
    inventario.inserir(Itens(101, "Arduino Uno", "Eletronica", "Armario A", 3, "Novo"));
    inventario.inserir(Itens(102, "Multimetro", "Eletronica", "Armario A", 2, "Usado"));
    inventario.inserir(Itens(201, "Impressora 3D", "Impressao", "Bancada 1", 1, "Novo"));
    
    // Testar busca
    cout << "=== TESTANDO BUSCA ===" << endl;
    Itens* item = inventario.buscar(101);
    if (item) {
        cout << "Item encontrado:" << endl;
        item->imprimirDetalhes();
    }
    
    // Testar solicitação de item
    cout << "\n=== TESTANDO SOLICITACAO ===" << endl;
    item = inventario.buscar(101);
    if (item) {
        cout << "Solicitando Arduino Uno..." << endl;
        item->solicitarItem(&usuario);
        item->imprimirDetalhes();
    }
    
    // Testar listagem por categoria
    cout << "\n=== ITENS DE ELETRONICA ===" << endl;
    inventario.listarPorCategoria("Eletronica");
    
    // Testar remoção
    cout << "\n=== REMOVENDO ITEM 102 ===" << endl;
    if (inventario.remover(102)) {
        cout << "Item 102 removido com sucesso!" << endl;
    }
    
    // Listar todos os itens
    cout << "\n=== TODOS OS ITENS ===" << endl;
    inventario.imprimirTabela();
    
    return 0;
}