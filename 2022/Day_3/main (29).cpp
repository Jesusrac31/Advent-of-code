#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int priority(char s) {
  string guia = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < 52; i++) {
    if (guia[i] == s) {
      return (i + 1);
    }
  }
  return (0);
}

int part_1() {
  int prioridad = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    // Lo vamos imprimiendo
    int tamano = linea.size() / 2;
    for (int i = 0; i < tamano; i++) {
      for (int j = tamano; j < tamano * 2; j++) {
        if (linea[i] == linea[j]) {
          prioridad += priority(linea[i]);
          i = tamano;
          break;
        }
      }
    }
  }
  return (prioridad); // Solución parte 1
}
int part_2() {
  int prioridad = 0;
  vector<string> lineas;
  int index = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    // Lo vamos imprimiendo
    lineas.push_back(linea);
    index += 1;
    if (index == 3) {
      index = 0;
      for (int i = 0; i < lineas[0].size(); i++) {
        for (int j = 0; j < lineas[1].size(); j++) {
          for (int n = 0; n < lineas[2].size(); n++) {
            if (lineas[0][i] == lineas[1][j] && lineas[1][j] == lineas[2][n]) {
              prioridad += priority(lineas[0][i]);
              i = lineas[0].size();
              j = lineas[1].size();
              n = lineas[2].size();
            }
          }
        }
      }
      lineas.clear();
    }
  }
  return (prioridad); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1

  cout << part_2() << endl; // Solución parte 2

  return 0;
}