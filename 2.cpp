//Link documento: https://bit.ly/3oiYcmg

#include <iostream>
#include <time.h>

using namespace std;

#define filas 6
#define columnas 6 // En realidad son 5, la sexta es del subtotal

void generar_aleatorios(int matriz[filas][columnas]){
    int random;
    for(int i = 0; i < filas; i++){
        // El último espacio de la fila
        matriz[i][5] = 0;
        // Restamos uno por el subtotal
        for(int j = 0; j < columnas - 1; j++){
            random = rand() % (7001) + 3000;
            matriz[i][j] = random;
            // Calculando el subtotal
            matriz[i][5] += random;
        }
    }
}

void imprimir_matriz(int matriz[filas][columnas]){
    cout << "\tLun\tMar\tMie\tJue\tVie\tSubtotal" << endl;
    for (int i = 0; i < filas; i++){
         cout << i + 1;
        for(int j = 0; j < columnas; j++){
            cout << "\t" << matriz[i][j];
        }
        cout << endl;
    }
}

string pais_max(int matriz[filas][columnas]){
    int max = 0;
    int aux_i = 0;
    for (int i = 0; i < filas; i++){
        if(matriz[i][5] > max) {
            max = matriz[i][5];
            aux_i = i;
        }
    }
    aux_i++;
    switch (aux_i) {
        case 1: return "Perú";
        case 2: return "Brasil";
        case 3: return "Argentina";
        case 4: return "Chile";
        case 5: return "Uruguay";
        case 6: return "Colombia";
        default: break;
    }
    return "";
}


int main(){
    int matriz[filas][columnas];
    srand (time(NULL));

    generar_aleatorios(matriz);
    imprimir_matriz(matriz);
    cout << endl;
    cout << "Deposit. max: " << pais_max(matriz) << endl;

    return 0;
}