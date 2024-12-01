#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part_1() {
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
  }
  return (0); // Solución parte 1
}
int part_2() {
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
  }
  return (0); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1
  cout << part_2() << endl; // Solución parte 2

  return 0;
}