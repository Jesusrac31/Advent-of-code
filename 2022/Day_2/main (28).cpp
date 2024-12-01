#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int part_1() {
  int puntos = 0;
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    // Lo vamos imprimiendo
    if (linea[0] == 'A') {
      if (linea[2] == 'X') {
        puntos += 1;
        puntos += 3;
      } else if (linea[2] == 'Y') {
        puntos += 2;
        puntos += 6;
      } else {
        puntos += 3;
      }
    } else if (linea[0] == 'B') {
      if (linea[2] == 'X') {
        puntos += 1;
      } else if (linea[2] == 'Y') {
        puntos += 2;
        puntos += 3;
      } else {
        puntos += 3;
        puntos += 6;
      }
    } else {
      if (linea[2] == 'X') {
        puntos += 1;
        puntos += 6;
      } else if (linea[2] == 'Y') {
        puntos += 2;
      } else {
        puntos += 3;
        puntos += 3;
      }
    }
  }
  return puntos;
}

int part_2() {
  int puntos = 0;
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    // Lo vamos imprimiendo
    if (linea[0] == 'A') {
      if (linea[2] == 'X') {
        puntos += 3;
      } else if (linea[2] == 'Y') {
        puntos += 1;
        puntos += 3;
      } else {
        puntos += 2;
        puntos += 6;
      }
    } else if (linea[0] == 'B') {
      if (linea[2] == 'X') {
        puntos += 1;
      } else if (linea[2] == 'Y') {
        puntos += 2;
        puntos += 3;
      } else {
        puntos += 3;
        puntos += 6;
      }
    } else {
      if (linea[2] == 'X') {
        puntos += 2;
      } else if (linea[2] == 'Y') {
        puntos += 3;
        puntos += 3;
      } else {
        puntos += 1;
        puntos += 6;
      }
    }
  }
  return puntos;
}

int main() {
  cout << part_1() << endl;
  cout << part_2() << endl;

  return 0;
}