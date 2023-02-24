#include <iostream>
#include <vector>
#include <algorithm>

struct item{
  int id;
  double weight;
  double value;
};

bool compare_value (item a,item b){
  return a.value>b.value;
}


int main(){

   std::vector<item> itens;
   int N;
   double W;

   // LEITURA DA QUANTIDADE DE ITENS E CAPACIDADE DA MOCHILA
   std::cin >> N >> W;

   // LEITURA DOS ITENS
   for (int i=0;i<N;i++){
      item obj;
      std::cin >> obj.weight >> obj.value;
      itens.push_back(obj);
   }

   // ORDENA EM RELAĆÃO AO VALOR
   std::sort(itens.begin(), itens.end(),compare_value);


   return 0;

}
