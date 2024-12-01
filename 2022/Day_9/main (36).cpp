#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part_1() {
  int piezas;
  cout << "Introduce numero de piezas: ";
  cin >> piezas;
  cout << endl;
  vector<vector<int>> pos_t;
  for (int i = 0; i < piezas; i++) {
    pos_t.push_back({0, 0});
  }
  vector<vector<int>> historial = {{0, 0}};

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {

    string num = "";
    int pasos = 0;
    for (int i = 2; i < linea.size(); i++) {
      num += linea[i];
    }
    pasos = stoi(num);
    for (int i = 0; i < pasos; i++) {
      if (linea[0] == 'U') {
        pos_t[0][0]++;
      } else if (linea[0] == 'R') {
        pos_t[0][1]++;
      } else if (linea[0] == 'D') {
        pos_t[0][0]--;
      } else {
        pos_t[0][1]--;
      }

      // Movimiento restante
      for (int j = 1; j < pos_t.size(); j++) {
        if (pos_t[j - 1][0] - pos_t[j][0] == 2) { // Up
          pos_t[j][0]++;
          pos_t[j][1] += min(max(pos_t[j - 1][1] - pos_t[j][1], -1), 1);
        } else if (pos_t[j - 1][0] - pos_t[j][0] == -2) { // Down
          pos_t[j][0]--;
          pos_t[j][1] += min(max(pos_t[j - 1][1] - pos_t[j][1], -1), 1);
        } else if (pos_t[j - 1][1] - pos_t[j][1] == 2) { // Right
          pos_t[j][1]++;
          pos_t[j][0] += min(max(pos_t[j - 1][0] - pos_t[j][0], -1), 1);
        } else if (pos_t[j - 1][1] - pos_t[j][1] == -2) { // Left
          pos_t[j][1]--;
          pos_t[j][0] += min(max(pos_t[j - 1][0] - pos_t[j][0], -1), 1);
        }
      }

      bool insertar = true;
      for (int j = 0; j < historial.size(); j++) {
        if (pos_t.back()[0] == historial[j][0] &&
            pos_t.back()[1] == historial[j][1]) {
          insertar = false;
          break;
        }
      }
      if (insertar) {
        historial.push_back(pos_t.back());
      }
    }
  }
  return (historial.size()); // Solución
}

int main() {
  cout << part_1() << endl; // Solución

  return 0;
}