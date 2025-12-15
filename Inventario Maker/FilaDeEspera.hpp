#ifndef FILADEESPERA_HPP
#define FILADEESPERA_HPP

#include "Itens.hpp"

struct NoItem {
    Itens* item;
    NoItem* proximo;
};

class FilaDeEspera {
private:
    NoItem* inicio;
    NoItem* fim;

public:
    FilaDeEspera();
    ~FilaDeEspera();

    void inserirNoFim(Itens* item);
    Itens* removerDoInicio();
    bool EstaCheio() const;
};

#endif