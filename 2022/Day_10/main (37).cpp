#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part_1() {
  int X = 1;
  int sum = 0;
  int i = 1;
  vector<vector<int>> espera;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    if (linea[0] == 'a') {
      string num = "";
      int incremento;
      for (int j = 5; j < linea.size(); j++) {
        num += linea[j];
      }
      incremento = stoi(num);
      espera.push_back({2, incremento});
    } else if (linea[0] == 'n') {
      espera.push_back({1, 0});
    }
    while (espera.size() != 0) {
      i++;
      for (int j = 0; j < espera.size(); j++) {
        espera[j][0]--;
        if (espera[j][0] == 0) {
          X += espera[j][1];
          espera.erase(espera.begin() + j);
          j--;
        }
      }
      if ((i - 20) % 40 == 0 && i <= 220) {
        sum += X * i;
      }
    }
  }
  return (sum); // Solución parte 1
}
int part_2() {
  int X = 1;
  int sum = 0;
  int i = 1;
  vector<vector<int>> espera;
  string mapa = "........................................"
                "........................................"
                "........................................"
                "........................................"
                "........................................"
                "........................................";

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    if (linea[0] == 'a') {
      string num = "";
      int incremento;
      for (int j = 5; j < linea.size(); j++) {
        num += linea[j];
      }
      incremento = stoi(num);
      espera.push_back({2, incremento});
    } else if (linea[0] == 'n') {
      espera.push_back({1, 0});
    }
    while (espera.size() != 0) {
      if (i - 1 < mapa.size()) {
        if (abs(((i - 1) % 40) - (X % 40)) <= 1) {
          mapa[i - 1] = '#';
        }
      }
      for (int j = 0; j < espera.size(); j++) {
        espera[j][0]--;
        if (espera[j][0] == 0) {
          X += espera[j][1];
          espera.erase(espera.begin() + j);
          j--;
        }
      }
      i++;
    }
  }
  for (int j = 0; j < 6; j++) {
    for (int n = 0; n < 40; n++) {
      if (mapa[j * 40 + n] == '.') {
        cout << " ";
      } else {
        cout << "#";
      }
    }
    cout << endl;
  }
  return (0); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1
  part_2();                 // Solución parte 2

  return 0;
}