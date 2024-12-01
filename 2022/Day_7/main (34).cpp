#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int calc_peso(vector<vector<string>> h, int n, map<vector<string>, int> pesos) {
  int peso = pesos[h[n]];

  for (int indexe = n + 1; indexe < h.size(); indexe++) {
    bool comprobado = true;
    for (int j = 0; j < h[n].size(); j++) {
      if (h[n][j] != h[indexe][j]) {
        comprobado = false;
        break;
      }
    }
    if (comprobado) {
      peso += pesos[h[indexe]];
    } else {
      break;
    }
  }
  return (peso);
}

int part_1() {
  int suma = 0;

  vector<vector<string>> historial;
  vector<string> ruta;
  map<vector<string>, int> peso;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    string num = "";
    for (int i = 0; linea[i] != ' '; i++) {
      num += linea[i];
    }
    if (num != "$") {
      if (num != "dir") {
        cout << num << " archivo" << endl;
        peso[ruta] += stoi(num);
        cout << peso[ruta] << endl;
      }
    } else {
      if (linea[2] == 'c') {
        if (linea[5] == '.') {
          ruta.erase(ruta.begin() + ruta.size() - 1);
        } else {
          ruta.push_back("");
          for (int i = 5; i < linea.size(); i++) {
            ruta.back() += linea[i];
          }
          peso[ruta] = 0;
        }
      } else {
        historial.push_back(ruta);
        for (int i = 0; i < ruta.size(); i++) {
          cout << ruta[i] << "|";
        }
        cout << endl;
      }
    }
  }
  cout << endl;
  for (int i = 0; i < historial.size(); i++) {
    peso[historial[i]] = calc_peso(historial, i, peso);
    cout << peso[historial[i]] << " " << i << endl;
  }
  cout << endl;

  for (int i = 0; i < historial.size(); i++) {
    for (int j = 0; j < historial[i].size(); j++) {
      cout << historial[i][j] << "|";
    }
    cout << " <-- " << peso[historial[i]] << endl;
    if (peso[historial[i]] <= 100000) {
      suma += peso[historial[i]];
    }
  }
  cout << endl;
  return (suma); // Solución parte 1
}

int part_2() {
  int resp = -1;

  vector<vector<string>> historial;
  vector<string> ruta;
  map<vector<string>, int> peso;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    string num = "";
    for (int i = 0; linea[i] != ' '; i++) {
      num += linea[i];
    }
    if (num != "$") {
      if (num != "dir") {
        cout << num << " archivo" << endl;
        peso[ruta] += stoi(num);
        cout << peso[ruta] << endl;
      }
    } else {
      if (linea[2] == 'c') {
        if (linea[5] == '.') {
          ruta.erase(ruta.begin() + ruta.size() - 1);
        } else {
          ruta.push_back("");
          for (int i = 5; i < linea.size(); i++) {
            ruta.back() += linea[i];
          }
          peso[ruta] = 0;
        }
      } else {
        historial.push_back(ruta);
        for (int i = 0; i < ruta.size(); i++) {
          cout << ruta[i] << "|";
        }
        cout << endl;
      }
    }
  }
  cout << endl;
  for (int i = 0; i < historial.size(); i++) {
    peso[historial[i]] = calc_peso(historial, i, peso);
    cout << peso[historial[i]] << " " << i << endl;
  }
  cout << endl;

  for (int i = 0; i < historial.size(); i++) {
    for (int j = 0; j < historial[i].size(); j++) {
      cout << historial[i][j] << "|";
    }
    cout << " <-- " << peso[historial[i]] << endl;
    if (peso[historial[i]] > 30000000 - (70000000 - 46592386) &&
        (peso[historial[i]] < resp || resp == -1)) {
      resp = peso[historial[i]];
    }
  }
  cout << endl;
  return (resp); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1
  cout << endl;
  cout << part_2() << endl; // Solución parte 2

  return 0;
}