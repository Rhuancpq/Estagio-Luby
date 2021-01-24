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
    int realizarVenda(int id, int quantidade, int valor_pago);
    bool verificaProduto(int id);
};

#endif
