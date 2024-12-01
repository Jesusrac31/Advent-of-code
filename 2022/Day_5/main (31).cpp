#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string part_1() {
  vector<vector<char>> crates = {{'F', 'T', 'C', 'L', 'R', 'P', 'G', 'Q'},
                                 {'N', 'Q', 'H', 'W', 'R', 'F', 'S', 'J'},
                                 {'F', 'B', 'H', 'W', 'P', 'M', 'Q'},
                                 {'V', 'S', 'T', 'D', 'F'},
                                 {'Q', 'L', 'D', 'W', 'V', 'F', 'Z'},
                                 {'Z', 'C', 'L', 'S'},
                                 {'Z', 'B', 'M', 'V', 'D', 'F'},
                                 {'T', 'J', 'B'},
                                 {'Q', 'N', 'B', 'G', 'L', 'S', 'P', 'H'}};

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    vector<int> paso;
    string numero = "";
    for (int i = 0; i < linea.size(); i++) {
      if (linea[i] == ' ') {
        paso.push_back(stoi(numero));
        numero = "";
      } else {
        numero += linea[i];
      }
    }
    paso.push_back(stoi(numero));
    for (int i = 0; i < paso[0]; i++) {
      crates[paso[2] - 1].push_back(crates[paso[1] - 1].back());
      crates[paso[1] - 1].erase(crates[paso[1] - 1].begin() +
                                crates[paso[1] - 1].size() - 1);
    }
  }
  string resp = "";
  resp += crates[0].back();
  resp += crates[1].back();
  resp += crates[2].back();
  resp += crates[3].back();
  resp += crates[4].back();
  resp += crates[5].back();
  resp += crates[6].back();
  resp += crates[7].back();
  resp += crates[8].back();
  return (resp); // Solución parte 1
}
string part_2() {
  vector<vector<char>> crates = {{'F', 'T', 'C', 'L', 'R', 'P', 'G', 'Q'},
                                 {'N', 'Q', 'H', 'W', 'R', 'F', 'S', 'J'},
                                 {'F', 'B', 'H', 'W', 'P', 'M', 'Q'},
                                 {'V', 'S', 'T', 'D', 'F'},
                                 {'Q', 'L', 'D', 'W', 'V', 'F', 'Z'},
                                 {'Z', 'C', 'L', 'S'},
                                 {'Z', 'B', 'M', 'V', 'D', 'F'},
                                 {'T', 'J', 'B'},
                                 {'Q', 'N', 'B', 'G', 'L', 'S', 'P', 'H'}};

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    vector<int> paso;
    string numero = "";
    for (int i = 0; i < linea.size(); i++) {
      if (linea[i] == ' ') {
        paso.push_back(stoi(numero));
        numero = "";
      } else {
        numero += linea[i];
      }
    }
    paso.push_back(stoi(numero));
    cout << linea << endl;
    for (int i = 0; i < paso[0]; i++) {
      crates[paso[2] - 1].push_back(
          crates[paso[1] - 1][crates[paso[1] - 1].size() - paso[0] + i]);
      crates[paso[1] - 1].erase(crates[paso[1] - 1].begin() +
                                crates[paso[1] - 1].size() - paso[0] + i);
    }
    for (int i = 0; i < crates.size(); i++) {
      for (int j = 0; j < crates[i].size(); j++) {
        cout << crates[i][j] << ", ";
      }
      cout << endl;
    }
    cout << endl;
  }
  string resp = "";
  resp += crates[0].back();
  resp += crates[1].back();
  resp += crates[2].back();
  resp += crates[3].back();
  resp += crates[4].back();
  resp += crates[5].back();
  resp += crates[6].back();
  resp += crates[7].back();
  resp += crates[8].back();
  return (resp); // Solución parte 1
}

int main() {
  cout << part_1() << endl;
  cout << part_2() << endl;

  return 0;
}