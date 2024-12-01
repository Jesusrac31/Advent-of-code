#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int part_1() {
  int calories = 0;
  int calories_max = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    // Lo vamos imprimiendo
    if (linea.compare("") != 0) {
      int a = stoi(linea);
      calories += a;
    } else {
      if (calories > calories_max) {
        calories_max = calories;
      }
      calories = 0;
    }
  }
  return (calories_max); // Solución parte 1
}
int part_2(int max) {
  int calories = 0;
  int calories_max = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    if (linea.compare("") != 0) {
      int a = stoi(linea);
      calories += a;
    } else {
      if (calories > calories_max && calories < max) {
        calories_max = calories;
      }
      calories = 0;
    }
  }
  return (calories_max); // Solución parte 2
}

int main() {
  int calories_1 = part_1();
  cout << calories_1 << endl; // Solución parte 1
  int calories_2 = part_2(calories_1);
  cout << calories_2 << endl;
  int calories_3 = part_2(calories_2);
  cout << calories_3 << endl;

  cout << calories_1 + calories_2 + calories_3 << endl; // Solución parte 2

  return 0;
}