#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;

bool my_compare(float a, float b);

int main(){
    std::vector<float> nums;
    nums.push_back(10.5);
    nums.push_back(4.0);
    // é o _ do python
    for(auto& e: nums)
        cout << e << "\t";
    sort(nums.begin(), nums.end(), my_compare); //ordenando por referencia 
    cout << "\n ORDENADO: " << "\n";

    for(auto& e: nums)
        cout << e << "\t";
    return 0;
}

bool my_compare(float a, float b){
    return a < b;
}