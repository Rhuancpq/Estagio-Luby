#include "Produto.hpp"

Produto::Produto(int id, double valor, int quantidade){
    this->id = id;
    this->quantidade = quantidade;
    this->valor = valor;
}

Produto::~Produto(){
    
}

int Produto::getId(){
    return this->id;
}

int Produto::getQuantidade(){
    return this->quantidade;
}

double Produto::getValor(){
    return this->valor;
}

void Produto::setQuantidade(int quantidade){
    this->quantidade = quantidade;
}
