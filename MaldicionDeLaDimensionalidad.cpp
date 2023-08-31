#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
using namespace std;





void CrearPuntos(vector<vector<float>>& matriz, int dimension) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < dimension; y++) {
            matriz[x][y] = dis(gen);
        }
    }
}
void DistanciasPuntos(int dimension) {
    ofstream outputFile("datos.txt");
    vector<vector<float>> matriz(100, vector<float>(dimension, 0));  // #filas #columnas

    CrearPuntos(matriz, dimension);
    outputFile.is_open();
    for (int i = 0; i < 100; i++) {
        for (int x = i + 1; x < 99; x++) {
            float contador = 0;
            for (int y = 0; y < dimension; y++) {

                contador += pow(abs(matriz[x + 1][y] - matriz[x][y]), 2);




            }

            outputFile << pow(contador, 1.0 / 2) << std::endl;
            ///cout<<i<<"."<<x << "->" << pow(contador, 1.0 /2) << endl;

        }

    }
    outputFile.close();




}
int main()
{
    int dimension = 10;

    DistanciasPuntos(dimension);

}
