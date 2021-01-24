#include "Maquina.hpp"
#include "Produto.hpp"
#include "Estoque.hpp"
#include <iostream>
#include <random>
#include <locale>
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
    setlocale(LC_ALL,"pt_BR.UTF-8");
    locale::global(locale());
    cout.imbue(locale());
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << '-';
    cout << " Produtos disponíveis no estoque\n" << endl;
    for (auto x : produtos){
        cout << " ID: "; 
        cout << setfill('0')
        << setw(2) << x.getId(); 
        cout << setprecision(3) 
        << showpoint
        << " | Valor: R$ " << x.getValor()
        << " | Quantidade: " << x.getQuantidade() << endl;
    }
    
}

void Maquina::visualizarQuantidadeEstoque(){
    cout << "\nAtualmente no estoque há " << this->estoque->getQuantidadeTotal()
    << " produtos ao todo!!\n" << endl;
}

void Maquina::visualizarHistorico(){
    if(historico_vendas.size() == 0){
        cout << "\nNão foi efetuada nenhuma venda ainda\n" << endl;
    }else{
        cout << endl;
        cout << "O valor total em vendas: R$ "
        << setprecision(3)
        << valor_total << endl;
        for (auto x : historico_vendas){
            cout << " ID: "; 
            cout << setfill('0')
            << setw(2) << x.getId();
            cout << setprecision(3)
            << showpoint
            << " | Valor: R$ " << x.getValor()
            << " | Quantidade vendida: " << x.getQuantidade() << endl;
        }
        cout << endl;
    }
}

int Maquina::realizarVenda(int id, int quantidade, int valor_pago){
    if(estoque->getQuantidadeProduto(id) < quantidade){
        cout << "\nQuantidade não disponível\n" << endl;
        return 0;
    }
    Produto *p = estoque->getProduto(id);
    if(p == nullptr){
        return -1;
    }else{
        double v_somado = p->getValor()*quantidade;
        if(valor_pago < v_somado){
            cout << "\nCompra não efetuada, dinheiro insuficiente" << endl;
            cout << "Faltam: R$ "
            << setprecision(3)
            << v_somado-valor_pago << '\n' << endl;
            return 2;
        }else{ 
            if(valor_pago > v_somado){
                cout << setprecision(3);
                cout << "\nTroco recebido: R$ "
                << valor_pago - v_somado << endl; 
            }
            p = estoque->removeProduto(id, quantidade);
            this->historico_vendas.push_back(*p);
            this->valor_total += p->getValor()*p->getQuantidade();
            cout << "Compra efetuada com sucesso!" << endl;
            return 1;
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
    this->estoque->insereProdutos(v_p);
}

bool Maquina::verificaProduto(int id){
    Produto *p = estoque->getProduto(id);
    return p == nullptr ? false : true;
}