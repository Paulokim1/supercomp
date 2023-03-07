#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> matriz;

double square_root(double x) {
    return pow(x, 0.5);
}

void calcula_distancias(matriz &mat, std::vector<double> &x, std::vector<double> &y) {
    int n = x.size();
    mat.resize(n*n);

    for (int i = 0; i < n; i++) {
        std::vector<double> linha;
        for (int j = 0; j < n; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            double dist = square_root((dx*dx) + (dy*dy));
            std::vector<double> vec_dist;
            vec_dist.push_back(dist);
            mat[j * n + i] = vec_dist;
            mat[i * n + j] = vec_dist;
        }
    }
}

int main() {
    matriz mat;
    std::vector<double> x, y;
    int n;

    std::cin >> n;
    x.reserve(n);
    y.reserve(n);
    for (int i = 0; i < n; i++) {
        double xt, yt;
        std::cin >> xt >> yt;
        x.push_back(xt);
        y.push_back(yt);
    }

    calcula_distancias(mat, x, y);
    

    for (auto &linha : mat) {
        for (double el : linha) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    return 0;
}