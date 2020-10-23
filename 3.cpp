//Link documento: https://bit.ly/3oiYcmg

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

void dibujar_matriz(int matriz[30][30]){
    COORD dwPos;  
    dwPos.X = 0;  
    dwPos.Y= 0;
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleCursorPosition(hcon, dwPos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    for(int i = 0; i <= 31; i++){
        cout << char(219);
    }
    cout << endl;
    for(int i = 0; i < 30; i++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        cout << char(219);
        for(int j = 0; j < 30; j++) {
            switch (matriz[i][j]){
                case 0: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); cout << ' '; break;
                case 1: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); cout << "&"; break; 
                case 2: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); cout << "%"; break; 
                case 3: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); cout << "$"; break; 
                case 4: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); cout << "#"; break;
                case 5: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); cout << "+"; break;
                case 6: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cout << "O"; break; 
                default: break;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        cout << char(219);
        cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    for(int i = 0; i <= 31; i++){
        cout << char(219);
    }
    SetConsoleCursorPosition(hcon, dwPos);
}

void iniciar_matriz(int matriz[30][30]){
    int random;
    int aux;
    for(int i = 1; i <= 5; i ++){
        // Número de símbolos en la fila
        random = rand() % 30 + 1;
        // Para calcular la posición donde debe empezar a imprimir (centrado)
        aux = (30 - random) / 2;
        // Cuántos se debe imprimir
        for(int j = aux; j < aux + random; j++){
            switch (i)
            {
            case 1:
                matriz[2][j] = 1;
                matriz[3][j] = 1;
                matriz[4][j] = 1;
                break;
            case 2:
                matriz[5][j] = 2;
                matriz[6][j] = 2;
                matriz[7][j] = 2;
                break;
            case 3:
                matriz[8][j] = 3;
                break;
            case 4:
                matriz[9][j] = 4;
                matriz[10][j] = 4;
                break;
            case 5:
                matriz[11][j] = 5;
                matriz[12][j] = 5;
                break;
            default:
                break;
            }
        }
    }
}

int main(){

    int x = 0, y = 0;
    srand (time(NULL));
    int matriz[30][30];
    
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++) {
            matriz[i][j] = 0;
        }
    }

    while(!(y > 3 && y < 27)){
        cout << "Ingrese x (3 < x < 27): ";
        cin >> y;
    }
    while(!(x > 15 && x < 27)){
        cout<<"Ingrese y (15 < y < 27): ";
        cin >> x;
    }
    cout << endl;
    matriz[x][y] = 6;
    matriz[x][y+1] = 6;
    matriz[x-1][y+1] = 6;
    matriz[x][y+2] = 6;

    iniciar_matriz(matriz);
    dibujar_matriz(matriz);   
    
    char a;

    while(true){
        matriz[x][y] = 0;
        matriz[x][y+1] = 0;
        matriz[x-1][y+1] = 0;
        matriz[x][y+2] = 0;
        a = getch();
        if(a == 77) y++;
        if(a == 75) y--;
        matriz[x][y] = 6;
        matriz[x][y+1] = 6;
        matriz[x-1][y+1] = 6;
        matriz[x][y+2] = 6;
        dibujar_matriz(matriz);
    }

    _getch();
    return 0;
}