#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part_1() {
  int suma = 0;
  vector<vector<string>> parejas = {};
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  int space = 0;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    space++;
    if (space % 3 != 0) {
      parejas.push_back({});
      string content = "";
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] == ',') {
          parejas.back().push_back(content);
          content = "";
        } else {
          content += linea[i];
        }
      }
    }
  }
  // 4 sublistas max
  int nivel = 0;
  for (int i = 0; i < parejas.size(); i += 2) {
    vector<vector<vector<vector<int>>>> l1 = {};
    for (int j = 0; j < parejas[i].size(); j++) {
      cout << parejas[i][j] << " ";
      if (parejas[i][j] == "[") {
        if (nivel == 1) {
          l1.push_back({});
        } else if (nivel == 2) {
          l1.back().push_back({});
        } else if (nivel == 3) {
          l1.back().back().push_back({});
        } else if (nivel == 4) {
          l1.back().back().back().push_back({});
        }
        nivel++;
      } else if (parejas[i][j] == "]") {
        nivel--;
      } else {
        if (nivel == 1) {
          l1.push_back({{{stoi(parejas[i][j])}}});
        } else if (nivel == 2) {
          l1.back().push_back({{stoi(parejas[i][j])}});
        } else if (nivel == 3) {
          l1.back().back().push_back({stoi(parejas[i][j])});
        } else if (nivel == 4) {
          l1.back().back().back().push_back(stoi(parejas[i][j]));
        }
      }
    }
    cout << endl;
    vector<vector<vector<vector<int>>>> l2 = {};
    for (int j = 0; j < parejas[i + 1].size(); j++) {
      cout << parejas[i + 1][j] << " ";
      if (parejas[i + 1][j] == "[") {
        if (nivel == 1) {
          l2.push_back({});
        } else if (nivel == 2) {
          l2.back().push_back({});
        } else if (nivel == 3) {
          l2.back().back().push_back({});
        } else if (nivel == 4) {
          l2.back().back().back().push_back({});
        }
        nivel++;
      } else if (parejas[i + 1][j] == "]") {
        nivel--;
      } else {
        if (nivel == 1) {
          l2.push_back({{{stoi(parejas[i + 1][j])}}});
        } else if (nivel == 2) {
          l2.back().push_back({{stoi(parejas[i + 1][j])}});
        } else if (nivel == 3) {
          l2.back().back().push_back({stoi(parejas[i + 1][j])});
        } else if (nivel == 4) {
          l2.back().back().back().push_back(stoi(parejas[i + 1][j]));
        }
      }
    }
    cout << endl;
    // comparamos
    bool sol = false;
    int resp; // 0 = mal 1 = bien
    for (int j = 0; j < min(l1.size(), l2.size()); j++) {
      for (int n = 0; n < min(l1[j].size(), l2[j].size()); n++) {
        for (int m = 0; m < min(l1[j][n].size(), l2[j][n].size()); m++) {
          for (int l = 0; l < min(l1[j][n][m].size(), l2[j][n][m].size());
               l++) {
            if (sol) {
              break;
            } else {
              if (l1[j][n][m][l] < l2[j][n][m][l]) {
                resp = 1;
                cout << 1 << "l" << endl;
                sol = true;
              } else if (l1[j][n][m][l] > l2[j][n][m][l]) {
                resp = 0;
                cout << 0 << "l" << endl;
                sol = true;
              }
            }
          }
          if (sol) {
            break;
          } else {
            if (l1[j][n][m].size() < l2[j][n][m].size()) {
              resp = 1;
              cout << 1 << "m" << endl;
              sol = true;
            } else if (l1[j][n][m].size() > l2[j][n][m].size()) {
              resp = 0;
              cout << 0 << "m" << endl;
              sol = true;
            }
          }
        }
        if (sol) {
          break;
        } else {
          if (l1[j][n].size() < l2[j][n].size()) {
            resp = 1;
            cout << 1 << "n" << endl;
            sol = true;
          } else if (l1[j][n].size() > l2[j][n].size()) {
            resp = 0;
            cout << 0 << "n" << endl;
            sol = true;
          }
        }
      }
      if (sol) {
        break;
      } else {
        if (l1[j].size() < l2[j].size()) {
          resp = 1;
          cout << 1 << "j " << l1[j].size() << " " << l2[j].size() << endl;
          sol = true;
        } else if (l1[j].size() > l2[j].size()) {
          resp = 0;
          cout << 0 << "j " << l1[j].size() << " " << l2[j].size() << endl;
          sol = true;
        }
      }
    }
    if (!sol) {
      if (l1.size() > l2.size()) {
        resp = 0;
        cout << 0 << "i" << endl;
        sol = true;
      } else {
        resp = 1;
        cout << 1 << "i" << endl;
        sol = true;
      }
    }
    if (resp == 1) {
      suma += i / 2 + 1;
    }
    cout << i / 2 + 1 << endl
         << "--------------------------------------------------------" << endl;
  }
  return (suma); // Solución parte 1
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