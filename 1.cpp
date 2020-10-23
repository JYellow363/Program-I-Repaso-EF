// Link documento: https://bit.ly/3oiYcmg

#include <iostream>
#include <vector>
#include <locale>

using namespace std;

struct Estudiante {
    string codigo;
    string nombre;
    float PC1;
    float EP;
    float EF;
    float TF;
    float PA;
    float NF;
};

float hallar_promedio_NF(vector<Estudiante> estudiantes){
    float aux = 0;
    for(int i = 0; i < estudiantes.size(); i++){
        aux += estudiantes[i].NF;
    }
    return aux / estudiantes.size();
}

string estudiante_max_nota(vector<Estudiante> estudiantes){
    int aux_i;
    int max = 0;
    for(int i = 0; i < estudiantes.size(); i++){
        if (estudiantes[i].NF > max) {
            max = estudiantes[i].NF;
            aux_i = i;
        }
    }
    return estudiantes[aux_i].nombre;
}

void calcular_NF(vector<Estudiante>& estudiantes) {
    for(int i = 0; i < estudiantes.size(); i++){
        estudiantes[i].NF = (estudiantes[i].PC1 + estudiantes[i].EP + estudiantes[i].EF
        + estudiantes[i].TF + estudiantes[i].PA) / 5;
    }
}

void imprimir_reporte_general(vector<Estudiante> estudiantes){
    cout << endl << "Reporte General:" << endl;
    cout << "COD\tNOMBRE\tPC1\tEP\tEF\tTF\tPA\tNF" << endl;
    for(int i = 0; i < estudiantes.size(); i++){
        cout << estudiantes[i].codigo << "\t" << estudiantes[i].nombre << "\t" << estudiantes[i].PC1 << "\t" <<
        estudiantes[i].EP << "\t" << estudiantes[i].EF << "\t" << estudiantes[i].TF << "\t" << estudiantes[i].PA << "\t" << estudiantes[i].NF << endl;
    }
}

float porcentaje_aprobados(vector<Estudiante> estudiantes){
    float cont = 0;
    for(int i = 0; i < estudiantes.size(); i++){
        if(estudiantes[i].NF >= 12.5) cont++;
    }
    return ((cont) / estudiantes.size()) * 100;
}

int main(){
    //locale::global(locale("spanish"));
    int n;
    cout << "Ingrese n: ";
    cin >> n;
    vector<Estudiante> estudiantes(n);
    for(int i = 0; i < n; i++){
        cout << "Ingrese cod del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].codigo;
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nombre;
        cout << "Ingrese PC1 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].PC1;
        cout << "Ingrese Ex. Parcial del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].EP;
        cout << "Ingrese Ex. Final del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].EF;
        cout << "Ingrese T. Final del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].TF;
        cout << "Ingrese Particip. del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].PA;
        cout << endl;
    }
    calcular_NF(estudiantes);
    cout << "RESULTADOS: " << endl;
    cout << "El " << porcentaje_aprobados(estudiantes) << "% son aprobados y " <<  100 - porcentaje_aprobados(estudiantes) << "% desaprobados" << endl;
    cout << estudiante_max_nota(estudiantes) << " es el que tiene la max nota" << endl;
    cout << "El promedio de la nota final es " << hallar_promedio_NF(estudiantes) << endl;
    imprimir_reporte_general(estudiantes);

    return 0;
}