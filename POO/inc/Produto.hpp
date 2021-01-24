#ifndef PRODUTO_HPP
#define PRODUTO_HPP

class Produto{
private:
    int id, quantidade;
    double valor;
public:
    Produto(int id, double valor, int quantidade);
    ~Produto();
    double getValor();
    int getId();
    int getQuantidade();
    void setQuantidade(int quantidade);
};


#endif
