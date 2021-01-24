#include "Estoque.hpp"
#include "Produto.hpp"
#include <vector>

Estoque::Estoque(){
    this->quantidade_total = 0;
}

Estoque::~Estoque(){
    for(auto x : produtos){
        if(x.second != nullptr)
            delete x.second;
    }
}

vector<Produto> Estoque::getProdutos(){
    vector<Produto> res;
    for(auto x : this->produtos){
        if(x.second == nullptr)
            continue;
        res.push_back(*x.second);
    }
    return res;
}

Produto * Estoque::getProduto(int id){
    return produtos[id];
}

int Estoque::getQuantidadeTotal(){
    return this->quantidade_total;
}

int Estoque::getQuantidadeProduto(int id){
    if(this->produtos[id] == nullptr){
        return 0;
    }
    return this->produtos[id]->getQuantidade();
}

void Estoque::insereProduto(Produto * p){
    this->quantidade_total += p->getQuantidade(); 
    produtos[p->getId()] = p;
}

void Estoque::insereProdutos(vector<Produto *> v_p){
    for(auto p : v_p){
        this->quantidade_total += p->getQuantidade();
        produtos[p->getId()] = p;
    }
}

bool Estoque::abasteceProduto(int id, int quantidade){
    if(produtos[id] == nullptr){
        return false;
    }
    quantidade_total += quantidade;
    Produto *p = produtos[id];
    p->setQuantidade(p->getQuantidade()+quantidade);
    return true;
}

/* Retorna um ponteiro pra um produto, contendo a quantidade;
   retorna nulo se não tiver a quantidade disponível no estoque */
Produto* Estoque::removeProduto(int id, int quantidade){
    Produto *p = produtos[id];
    if(p == nullptr)
        return nullptr;
    if(p->getQuantidade() - quantidade < 0)
        return nullptr;
    if(p->getQuantidade() - quantidade == 0){
        produtos.erase(id);
        Produto* p_res = new Produto(id, p->getValor(), quantidade);
        delete p;
        return p_res;
    }else{
        produtos[id]->setQuantidade(p->getQuantidade()-quantidade);
        return new Produto(id, p->getValor(), quantidade);
    }
}