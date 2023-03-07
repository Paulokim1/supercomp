#include<iostream>
using std::cout;

int sqrt_it(int &x); //assinatura da funcao

int main() {
    int t = 10;
    cout << "endereco de t = " << &t << '\n';
    cout << sqrt_it(t) << '\n';
    cout << "valor de t = " << t << '\n';
    return 0;
}

//Se fosse apenas int x, haveria uma espaco de memoria nova onde sera alocada o valor desse variavel parametro.
// nao estamos trabalhando com copia de valor mas referencia 
int sqrt_it(int &x){
    cout << "endereco de x = " << &x << '\n';
    return x*x;
}