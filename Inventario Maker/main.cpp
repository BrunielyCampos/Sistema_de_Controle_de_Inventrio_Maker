#include <iostream>
#include <string>
#include <limits>
#include "TabelaHash.hpp"
#include "Usuario.hpp"

using namespace std;

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void exibirMenu() {
    cout << "\n=== SISTEMA DE CONTROLE DE INVENTÁRIO MAKER ===\n";
    cout << "1. Cadastrar novo item\n";
    cout << "2. Buscar item por ID\n";
    cout << "3. Remover item\n";
    cout << "4. Listar itens por categoria\n";
    cout << "5. Listar todos os itens\n";
    cout << "6. Solicitar empréstimo\n";
    cout << "7. Devolver item\n";
    cout << "8. Sair\n";
    cout << "Escolha uma opção: ";
}

void cadastrarItem(TabelaHash& tabela) {
    int id, quantidade;
    string nome, categoria, localizacao, condicao;
    
    cout << "\n=== CADASTRAR NOVO ITEM ===\n";
    cout << "ID: ";
    cin >> id;
    limparBuffer();
    
    cout << "Nome: ";
    getline(cin, nome);
    
    cout << "Categoria: ";
    getline(cin, categoria);
    
    cout << "Localização: ";
    getline(cin, localizacao);
    
    cout << "Quantidade: ";
    cin >> quantidade;
    limparBuffer();
    
    cout << "Condição: ";
    getline(cin, condicao);
    
    Itens novoItem(id, nome, categoria, localizacao, quantidade, condicao);
    tabela.inserir(novoItem);
    
    cout << "\nItem cadastrado com sucesso!\n";
}

void buscarItem(TabelaHash& tabela) {
    int id;
    cout << "\n=== BUSCAR ITEM ===\n";
    cout << "Digite o ID do item: ";
    cin >> id;
    
    Itens* item = tabela.buscar(id);
    if (item != nullptr) {
        cout << "\nItem encontrado!\n";
        item->imprimirDetalhes();
    } else {
        cout << "\nItem não encontrado.\n";
    }
}

void removerItem(TabelaHash& tabela) {
    int id;
    cout << "\n=== REMOVER ITEM ===\n";
    cout << "Digite o ID do item a ser removido: ";
    cin >> id;
    
    if (tabela.remover(id)) {
        cout << "Item removido com sucesso!\n";
    } else {
        cout << "Falha ao remover o item. Verifique o ID.\n";
    }
}

void listarPorCategoria(TabelaHash& tabela) {
    string categoria;
    cout << "\n=== LISTAR POR CATEGORIA ===\n";
    cout << "Digite a categoria: ";
    limparBuffer();
    getline(cin, categoria);
    
    tabela.listarPorCategoria(categoria);
}

void solicitarEmprestimo(TabelaHash& tabela, Usuario& usuario) {
    int id;
    cout << "\n=== SOLICITAR EMPRÉSTIMO ===\n";
    cout << "Digite o ID do item desejado: ";
    cin >> id;
    
    Itens* item = tabela.buscar(id);
    if (item != nullptr) {
        if (item->solicitarItem(usuario)) {
            cout << "\nSolicitação de empréstimo realizada com sucesso!\n";
        } else {
            cout << "\nItem não disponível no momento. Você foi adicionado à fila de espera.\n";
        }
    } else {
        cout << "\nItem não encontrado.\n";
    }
}

void devolverItem(TabelaHash& tabela) {
    int id;
    cout << "\n=== DEVOLVER ITEM ===\n";
    cout << "Digite o ID do item a ser devolvido: ";
    cin >> id;
    
    Itens* item = tabela.buscar(id);
    if (item != nullptr) {
        item->devolverItem();
        cout << "\nItem devolvido com sucesso!\n";
    } else {
        cout << "\nItem não encontrado.\n";
    }
}

int main() {
    TabelaHash tabela(7); // Tabela hash com tamanho inicial 7
    Usuario usuario("Usuário Padrão", 1); // Usuário padrão para testes
    
    int opcao;
    bool executando = true;
    
    while (executando) {
        exibirMenu();
        cin >> opcao;
        limparBuffer();
        
        switch (opcao) {
            case 1:
                cadastrarItem(tabela);
                break;
            case 2:
                buscarItem(tabela);
                break;
            case 3:
                removerItem(tabela);
                break;
            case 4:
                listarPorCategoria(tabela);
                break;
            case 5:
                cout << "\n=== TODOS OS ITENS ===\n";
                tabela.imprimirTabela();
                break;
            case 6:
                solicitarEmprestimo(tabela, usuario);
                break;
            case 7:
                devolverItem(tabela);
                break;
            case 8:
                executando = false;
                cout << "\nSaindo do sistema...\n";
                break;
            default:
                cout << "\nOpção inválida! Tente novamente.\n";
        }
    }
    
    return 0;
}
