#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;
using std::cin;
using std::vector;

bool my_compare(float a, float b);
void calcula_media(vector<float> &v);

int main(){
    float num = 0.0;
    vector<float> nums;

    while (cin >> num){
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end(), my_compare);
    cout << "Maior = " << nums[nums.size()-1] << "\n";
    cout << "Menor = " << nums[0] << "\n";
    calcula_media(nums);
    cout << "O tamanho do vetor é: " << nums.size() << "\n";
    return 0;
}  

bool my_compare(float a, float b){
    return a < b;
}

//se eu usasse v, estaria usando por valor
void calcula_media(std::vector<float> &v) {
    float m = 0.0;

    for(auto& e: v)
        m += e;
    cout << "Media = " << m/v.size() << "\n";
    v.push_back(0); //para testar a referencia. 

}