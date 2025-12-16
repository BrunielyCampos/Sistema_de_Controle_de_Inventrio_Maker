# Sistema de Controle de Inventário Maker

Este é um sistema de controle de inventário desenvolvido em C++ que utiliza uma tabela hash para armazenar itens e gerenciar empréstimos. O sistema é projetado para ser eficiente e fácil de usar, com suporte a operações básicas de CRUD (Criar, Ler, Atualizar, Deletar) em itens do inventário.

## Funcionalidades

- Cadastro de itens com ID, nome, categoria, localização, quantidade e condição
- Busca de itens por ID
- Remoção de itens
- Listagem de itens por categoria
- Sistema de empréstimo com fila de espera
- Rehashing automático quando necessário

## Estrutura do Projeto

- `main.cpp`: Contém a função principal e a interface do usuário
- `Itens.[hpp/cpp]`: Classe que representa um item do inventário
- `TabelaHash.[hpp/cpp]`: Implementação da tabela hash para armazenamento eficiente
- `FilaDeEspera.[hpp/cpp]`: Gerencia a fila de espera para itens emprestados
- `Usuario.[hpp/cpp]`: Classe que representa um usuário do sistema
- `FilaDeColisoes.[hpp/cpp]`: Implementação da lista encadeada para tratamento de colisões
- `Makefile`: Para compilação do projeto

## Requisitos

- Compilador C++ compatível com C++11 (g++ ou similar)
- Sistema operacional Windows (ou adaptar o Makefile para outros sistemas)

## Como Compilar e Executar

1. Certifique-se de ter um compilador C++ instalado
2. Abra um terminal na pasta do projeto
3. Execute o comando `make` para compilar o projeto
4. Execute o programa com `make run` ou `./inventario_maker`

## Uso

1. Ao iniciar o programa, um menu será exibido com as opções disponíveis
2. Siga as instruções na tela para realizar as operações desejadas
3. Utilize a opção de sair para encerrar o programa corretamente

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo LICENSE para obter mais informações.
