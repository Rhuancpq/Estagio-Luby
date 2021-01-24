#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <vector>
#include <unordered_map>
#include "Produto.hpp"
using namespace std;

class Estoque{
private:
    unordered_map<int, Produto *> produtos;
    int quantidade_total;
public:
    Estoque();
    ~Estoque();
    vector<Produto> getProdutos();
    Produto* getProduto(int id);
    int getQuantidadeTotal();
    int getQuantidadeProduto(int id);
    void insereProduto(Produto * p);
    void insereProdutos(vector<Produto *> v_p);
    Produto* removeProduto(int id, int quantidade);
    bool abasteceProduto(int id, int quantidade);
};

#endif
