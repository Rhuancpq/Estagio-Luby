#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;


int CalcularFatorial(int n){
    int res = 1;
    for (int i = 2; i < n; i++)
        res *= i;
    
    return res;
}

double CalcularPremio(double v, string tipo){
    double res = v;
    if(tipo == "special")
        res *= 2.0;
    else if (tipo == "deluxe")
        res *= 1.8;
    else if (tipo == "premium")
        res *= 1.5;
    else if (tipo == "vip")
        res *= 1.2;

    return res;
}

// optei por usar sobrecargar para caso for fornecido o parâmetro p
double CalcularPremio(double v, string tipo, double p){
    return v*p;
}

// Usei a função totiente de euler para calcular a quantidade de números primos até n
int ContarNumerosPrimos(int n){
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

bool ChecaVogal(char a){
    return a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u';
}

int CalcularVogais(string s){
    int res = 0;
    for(auto x: s)
        res += ChecaVogal(x) ? 1 : 0;

    return res;
}

string CalcularValorComDescontoFormatado(string val, string p){
    string valT(val.begin()+2, val.end());
    string per(p);
    size_t per_t = per.size()-1; 
    double percent = stod(per);
    valT.erase(remove(valT.begin(), valT.end(), '.'), valT.end());
    replace(valT.begin(), valT.end(), ',', '.');
    double valor = stod(valT);
    valor *= (1-percent/100);
    string res = to_string(valor);
    replace(res.begin(), res.end(), '.', ',');
    res = "R$ " + string(res.begin(), res.begin() + 3 + res.find(','));
    return res;
}

int CalcularDiferencaData(string a, string b){
    int ano1, ano2, mes1, mes2, dia1, dia2, res = 0;
    tm t1, t2;
    ano1 = stoi(string(a.begin()+4, a.end()));
    ano2 = stoi(string(b.begin()+4, b.end()));
    mes1 = stoi(string(a.begin()+2, a.begin()+4));
    mes2 = stoi(string(b.begin()+2, b.begin()+4));
    dia1 = stoi(string(a.begin(), a.begin()+2));
    dia2 = stoi(string(b.begin(), b.begin()+2));
    res = max(dia1, dia2) - min(dia1, dia2);
    res += (max(mes1, mes2) - min(mes1, mes2))*30;
    res += (max(ano1, ano2) - min(ano1, ano2))*30;
    return res;
}


vector<int> ObterElementosPares(vector<int> vetor){
    vector<int> res;
    for(auto x : vetor){
        if(!x%2)
            res.push_back(x);
    }

    return res;
}

vector<string> BuscarPessoa(vector<string> vetor, string busca){
    vector<string> res;
    for(auto x: vetor){
        if(x.find(busca) != string::npos)
            res.push_back(x);
    }
    return res;
}

vector<vector<int>> TransformarEmMatriz(string a){
    string t(a);
    replace(t.begin(), t.end(), ',', ' ');
    stringstream ss(t);
    vector<vector<int>> res;
    vector<int> e;
    int count = 0;
    while(!ss.eof()){
        int a;
        ss >> a;
        e.push_back(a);
        if(count == 1){
            count = 0;
            res.push_back(e);
            e = vector<int>();
        }else
            count++;
    }

    return res;
}

vector<int> ObterElementosFaltantes(vector<int> vetor1, vector<int> vetor2){
    set<int> a(vetor1.begin(), vetor1.end());
    set<int> b(vetor2.begin(), vetor2.end());
    set<int> temp1, temp2, temp3;
    set_difference(a.begin(), a.end(), b.begin(), b.end(),
            inserter(temp1, temp1.end()));
    set_difference(b.begin(), b.end(), a.begin(), a.end(),
            inserter(temp2, temp2.end()));
    set_union(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(),
            inserter(temp3, temp3.end()));

    return vector<int>(temp3.begin(), temp3.end());
}