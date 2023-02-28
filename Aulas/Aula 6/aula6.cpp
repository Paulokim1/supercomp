#include <random>
#include <iostream>
#include <cstring>
#include <vector>
using std::cout;
using std::cin;


int main() {
  std::default_random_engine generator(1055);
  std::binomial_distribution<int> distribution(0.75,0.25);

  std::vector<int> mochila;

  for (int i=0; i<5; i++)
    mochila.push_back(0);
  
  for (int i=0; i<5; i++)
    mochila[i] = distribution(generator);

  return 0;
}




