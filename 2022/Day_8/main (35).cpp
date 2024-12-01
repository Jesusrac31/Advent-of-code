#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part_1() {
  vector<vector<int>> mapa;
  int visibles = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    mapa.push_back({});
    for (int i = 0; i < linea.size(); i++) {
      string num = "";
      num += linea[i];
      mapa.back().push_back(stoi(num));
    }
  }
  for (int i = 0; i < mapa.size(); i++) {      // filas
    for (int j = 0; j < mapa[i].size(); j++) { // columnas
      vector<bool> vista = {true, true, true,
                            true};       // Arriba, izquierda, abajo, derecha
      for (int n = i - 1; n >= 0; n--) { // Arriba
        if (mapa[i][j] <= mapa[n][j]) {
          vista[0] = false;
        }
      }
      for (int n = j - 1; n >= 0; n--) { // Izquierda
        if (mapa[i][j] <= mapa[i][n]) {
          vista[1] = false;
        }
      }
      for (int n = i + 1; n < mapa.size(); n++) { // Abajo
        if (mapa[i][j] <= mapa[n][j]) {
          vista[2] = false;
        }
      }
      for (int n = j + 1; n < mapa[i].size(); n++) { // Derecha
        if (mapa[i][j] <= mapa[i][n]) {
          vista[3] = false;
        }
      }
      if (vista[0] || vista[1] || vista[2] || vista[3]) {
        visibles++;
      }
    }
  }

  return (visibles); // Solución parte 1
}
int part_2() {
  vector<vector<int>> mapa;
  int visibles = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    mapa.push_back({});
    for (int i = 0; i < linea.size(); i++) {
      string num = "";
      num += linea[i];
      mapa.back().push_back(stoi(num));
    }
  }
  for (int i = 0; i < mapa.size(); i++) {      // filas
    for (int j = 0; j < mapa[i].size(); j++) { // columnas
      vector<int> vista = {0, 0, 0, 0};  // Arriba, izquierda, abajo, derecha
      for (int n = i - 1; n >= 0; n--) { // Arriba
        vista[0]++;
        if (mapa[i][j] <= mapa[n][j]) {
          break;
        }
      }
      for (int n = j - 1; n >= 0; n--) { // Izquierda
        vista[1]++;
        if (mapa[i][j] <= mapa[i][n]) {
          break;
        }
      }
      for (int n = i + 1; n < mapa.size(); n++) { // Abajo
        vista[2]++;
        if (mapa[i][j] <= mapa[n][j]) {
          break;
        }
      }
      for (int n = j + 1; n < mapa[i].size(); n++) { // Derecha
        vista[3]++;
        if (mapa[i][j] <= mapa[i][n]) {
          break;
        }
      }
      if (visibles < vista[0] * vista[1] * vista[2] * vista[3]) {
        visibles = vista[0] * vista[1] * vista[2] * vista[3];
      }
    }
  }

  return (visibles); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1
  cout << part_2() << endl; // Solución parte 2

  return 0;
}