#include <iostream>
#include <string>
#include "Maquina.hpp"
using namespace std;

void exibeMenu(){
    cout << "Opções: " << endl;
    cout << "1. Visualizar produtos no estoque" << endl;
    cout << "2. Visualizar histórico de compras" << endl;
    cout << "3. Visualizar quantidade produtos no estoque" << endl;
    cout << "4. Comprar algum produto" << endl;
    cout << "5. Sair" << endl;
}

void redireciona(){
    cout << "\n\nPressione qualquer tecla para voltar o menu anterior";
    cin.get();  
}

void fazerCompra(Maquina* m){
    cout << "\033[2J\033[1;1H";
    m->visualizarEstoque();
    cout << "\n\nDigite o id do produto escolhido:" << endl;
    int id, qtd, f;
    double valor;
    cin >> id;
    cin.ignore();
    while (!m->verificaProduto(id)){
        cout << "Produto não existente, escolha um id válido" << endl;
        cin >> id;
        cin.ignore();
    }
    cout << "\nDigite agora a quantidade desejada desta bebida" << endl;
    cin >> qtd;
    cin.ignore();
    cout << "\nDigite também o valor que será pago" << endl;
    cin >> valor;
    cin.ignore();
    f = m->realizarVenda(id, qtd, valor);
    while(f != 1){
        cout << "Revise a quantidade e tente novamente..." << endl;
        string entrada;
        cout << "Você deseja continuar a compra? S ou N" << endl;
        cin >> entrada;
        if(entrada != "S")
            break;
        cout << "Digite a quantidade:" << endl;
        cin >> qtd;
        cin.ignore();
        cout << "Digite o valor:" << endl;
        cin >> valor;
        cin.ignore();
        f = m->realizarVenda(id, qtd, valor);
    }
}

int main(){
    cout << "Bem vindo a máquina de venda de bebidas em lata!!\n\n" << endl;
    Maquina *maquina = new Maquina();
    while(true){
        int entrada;
        exibeMenu();
        cin >> entrada;
        cin.ignore();
        while(entrada > 5 or entrada < 1){
            cout << "Opção indisponível!! Digite novamente:" << endl;
            cin >> entrada;
            cin.ignore();
        }
        switch (entrada){
        case 1:
            maquina->visualizarEstoque();
            redireciona();
            break;
        
        case 2:
            maquina->visualizarHistorico();
            redireciona();
            break;
        
        case 3:
            maquina->visualizarQuantidadeEstoque();
            redireciona();
            break;
        
        case 4:
            fazerCompra(maquina);
            redireciona();
            break;

        case 5:
            cout << "\n\nMuito obrigado!! Até mais!!" << endl;
            return 0;
            break;
        }
    }
    
    return 0;
}