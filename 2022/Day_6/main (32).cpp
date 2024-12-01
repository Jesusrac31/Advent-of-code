#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int part_1() {
  int resp = 0;
  
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    for (int i = 3; i<linea.size(); i++){
      if (linea[i]!=linea[i-1]&&linea[i]!=linea[i-2]&&linea[i]!=linea[i-3]){
        if (linea[i-1]!=linea[i-2]&&linea[i-1]!=linea[i-3]){
          if (linea[i-2]!=linea[i-3]){
            resp = i;
            cout << linea[i-3] << linea[i-2] << linea[i-1] << linea[i] << endl;
            break;
          }
        }
      }
    }
  }
  return (resp+1); // Solución parte 1
}
int part_2() {
  int resp = 0;
  
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    for (int i = 13; i<linea.size(); i++){
      map<char,int> letra;
      bool ya = true;
      for (int j=0; j<=13;j++){
        if (letra[linea[i-13+j]] == 0){
          letra[linea[i-13+j]]=1;
        } else{
          ya = false;
          break;
        }
      }
      if (ya){
        resp=i;
        break;
      }
    }
  }
  return (resp+1); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1
  cout << part_2() << endl; // Solución parte 2

  return 0;
}