
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

struct item
{
    int id;
    double peso;
    double valor;
    
};

bool ord (item i,item j) { return (i.peso<j.peso); }

vector<item> knapsack(vector<item> items, int tries){

  int n=items.size();
  vector<item> mochila;
  vector<item> melhor;
  mochila.reserve(n);
  melhor.reserve(n);
  int q=0.75*n;
  double max=0.0;

  for (int i=0;i<q;i++){ //75% serão preenchidos com os elementos de menor peso
      mochila[i]=items[i];
  }

  for(int t=0;t<tries;t++){
    for(int i=q;i<n;i++){ //25% serão preenchidos com escolhas aleatórias
     if ((rand() % 2)==1)
        mochila[i]=items[i];
     else mochila[i].id=-1;
    }
    double valor=0; // calcula o valor da nova mochila
    for(int i=0;i<n;i++)
      if (mochila[i].id!=-1)
          valor+=mochila[i].valor;
    if (valor>max){
       melhor=mochila;
       max=valor;
    }
  }

  return melhor;

}

int main() {

    int n,W;
    cin >> n >> W; //numero de elementos e peso
    vector<item> items;
    vector<item> melhor;
    items.reserve(n);
    for(int i = 0; i < n; i++) {
        double peso, valor;
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }

    // Ordena mochila por peso

    std::sort (items.begin(), items.end(), ord); 
    
    // Invoca a estratégia de aleatorizacao com 100 tentativas

    melhor=knapsack(items,100);
  
    return 0;
}
