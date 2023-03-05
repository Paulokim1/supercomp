#include <iostream>
#include <vector>
using namespace std;

struct Object {
    int id; // id do objeto
    int w; // peso
    int v; // valor
};

bool my_compare(Object a, Object b){
    return a.v > b.v; // ordena do maior para o menor
}

int main(){

    // leitura do numero de objetos e da capacidade da mochila
    int n, W;
    cin >> n >> W;

    // vetor de objetos
    vector<Object> objects;
    vector<int> bag;
    
    // leitura dos objetos
    for (int i = 0; i < n; i++){
        Object obj;
        cin >> obj.w >> obj.v;
        obj.id = i;
        objects.push_back(obj);
    }

    // ordena os objetos pelo valor
    sort(objects.begin(), objects.end(), my_compare);

    // insere os objetos na mochila a partir da heuristica do mais caro primeiro
    int total_w = 0;
    int total_v = 0;
    for (int i = 0; i < n; i++){
        if (total_w + objects[i].w <= W){
            bag.push_back(objects[i].id);
            total_w += objects[i].w;
            total_v += objects[i].v;
        }
    }
    sort(bag.begin(), bag.end());

    // imprime a solucao
    cout << total_w << "\t";
    cout << total_v << "\t";
    cout << 0 << "\n";

    for (int i=0; i < bag.size(); i++){
        cout << bag[i] << " ";
    }
    cout << "\n";
    return 0;
}