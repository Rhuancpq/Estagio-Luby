#include "Maquina.hpp"
#include "Produto.hpp"
#include "Estoque.hpp"
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

Maquina::Maquina(){
    this->valor_total = 0.0;
    estoque = new Estoque();
    this->inicializaEstoque();
}

Maquina::~Maquina(){
    delete estoque;
}

void Maquina::visualizarEstoque(){
    if(this->estoque->getQuantidadeTotal() == 0){
        cout << "Estoque vazio!!" << endl;
        return;
    }
    vector<Produto> produtos = this->estoque->getProdutos();
    setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << setprecision(2);
    cout << endl;
    for (int i = 0; i < 50; i++)
        cout << '-';
    cout << "Produtos disponíveis no estoque" << endl;
    
    for (auto x : produtos){
        cout << " ID: " << x.getId()
        << " | Valor: R$ " << x.getValor()
        << " | Quantidade: " << x.getQuantidade();
    }
    
}

void Maquina::visualizarQuantidadeEstoque(){
    cout << "Atualmente no estoque há " << this->estoque->getQuantidadeTotal()
    << " produtos ao todo!!" << endl;
}

void Maquina::visualizarHistorico(){
    if(historico_vendas.size() == 0){
        cout << "Não foi efetuada nenhuma venda ainda" << endl;
    }else{
        cout << endl;
        cout << setprecision(2);
        cout << "O valor total em vendas: R$ "
        << valor_total << endl;
        for (auto x : historico_vendas){
            cout << " ID: " << x.getId()
            << " | Valor: R$ " << x.getValor()
            << " | Quantidade vendida: " << x.getQuantidade();
        }
        cout << endl;
    }
}

bool Maquina::realizarVenda(int id, int quantidade, int valor_pago){
    if(estoque->getQuantidadeProduto(id) == 0){
        return false;
    }
    Produto *p = estoque->getProduto(id);
    if(p == nullptr){
        return false;
    }else{
        double v_somado = p->getValor()*quantidade;
        if(valor_pago < v_somado){
            cout << "Compra não efetuada, dinheiro insuficiente" << endl;
            return false;
        }else{ 
            if(valor_pago > v_somado){
                cout << setprecision(2);
                cout << "Troco recebido: R$"
                << valor_pago - v_somado << endl; 
            }
            p = estoque->removeProduto(id, quantidade);
            this->historico_vendas.push_back(*p);
            this->valor_total += p->getValor()*p->getQuantidade();
            return true;
        }
    }
}

void Maquina::inicializaEstoque(){
    default_random_engine generator;
    uniform_int_distribution<int> ids(10, 30);
    uniform_int_distribution<int> qtds(1, 30);
    uniform_real_distribution<double> precos(1.0, 10.0);
    int t = ids(generator);
    vector<Produto *> v_p; 
    for (int i = 1; i <= t; i++){
        v_p.push_back(new Produto(i, precos(generator), qtds(generator)));
    }
}