#ifndef MAQUINA_HPP
#define MAQUINA_HPP

#include "Estoque.hpp"
#include <vector>

class Maquina{
private:
    Estoque* estoque;
    vector<Produto> historico_vendas;
    double valor_total;
    void inicializaEstoque();
public:
    Maquina();
    ~Maquina();
    void visualizarEstoque();
    void visualizarQuantidadeEstoque();
    void visualizarHistorico();
    bool realizarVenda(int id, int quantidade, int valor_pago);
};

#endif
