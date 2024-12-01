#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int lli;
typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef map<int, vector<int>> miv;

// Funciones vector
#define PB(a) push_back(a);

bool sort_func(int a, int b) {
  if (a < b) {
    return true;
  } else {
    return false;
  }
}
#define ord(vect) sort(vect.begin(), vect.end(), sort_func);

#define borra_el(vect, el) vect.erase(vect.find(el));
#define borra_range(vect, a, b) vect.erase(a, b);
#define borra(vect, n) vect.erase(vect.begin() + n);
#define B begin();
#define E end();
#define copia(v1, v2)                                                          \
  ;                                                                            \
  copy(v1.begin(), v1.end(), back_inserter(v2));

// Funciones map
#define F first;
#define S second;

// Logaritmo de 2
double log_2 = log(2);
double log2(int a) { return (log(a) / log_2); }

void Imprime(vi vect) {
  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
  }
  cout << endl;
}

void Imprime_set(set<int> s) {
  copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

vi lee(int n) {
  int el;
  vi vect;
  for (int i = 0; i < n; i++) {
    cin >> el;
    vect.PB(el);
  }
  return (vect);
}

bool isNumeric(string const &str) {
  auto it = str.begin();
  while (it != str.end() && isdigit(*it)) {
    it++;
  }
  return !str.empty() && it == str.end();
}

/*
string nombreArchivo = "input.txt";
ifstream archivo(nombreArchivo.c_str());
string linea;
// Obtener línea de archivo, y almacenar contenido en "linea"
while (getline(archivo, linea)) {
  cout << linea << endl;
}
*/

int Part_1() {
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  vector<string> input;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    input.PB(linea);
  }
  vector<vector<string>> matriz;
  for (int i = 0; i < input.size(); i++) {
    vector<string> fila;
    string num = "";
    for (int j = 0; j < input[i].size(); j++) {
      string letra = "";
      letra.PB(input[i][j]);
      if (isNumeric(letra)) {
        num.PB(input[i][j]);
      } else {
        for (int k = 0; k < num.size(); k++) {
          fila.PB(num);
        }
        num = "";
        fila.PB(letra);
      }
    }
    for (int k = 0; k < num.size(); k++) {
      fila.PB(num);
    }
    matriz.PB(fila);
  }
  int suma = 0;
  for (int i = 0; i < matriz.size(); i++) {
    for (int j = 0; j < matriz[i].size(); j++) {
      if (matriz[i][j] != "." && !isNumeric(matriz[i][j])) {
        // Comprobamos arriba
        if (isNumeric(matriz[i - 1][j])) {
          suma += stoi(matriz[i - 1][j]);
        } else {
          if (isNumeric(matriz[i - 1][j - 1])) {
            suma += stoi(matriz[i - 1][j - 1]);
          }
          if (isNumeric(matriz[i - 1][j + 1])) {
            suma += stoi(matriz[i - 1][j + 1]);
          }
        }
        // Comprobamos izquierda
        if (isNumeric(matriz[i][j - 1])) {
          suma += stoi(matriz[i][j - 1]);
        }
        // Comprobamos derecha
        if (isNumeric(matriz[i][j + 1])) {
          suma += stoi(matriz[i][j + 1]);
        }
        // Comprobamos abajo
        if (isNumeric(matriz[i + 1][j])) {
          suma += stoi(matriz[i + 1][j]);
        } else {
          if (isNumeric(matriz[i + 1][j - 1])) {
            suma += stoi(matriz[i + 1][j - 1]);
          }
          if (isNumeric(matriz[i + 1][j + 1])) {
            suma += stoi(matriz[i + 1][j + 1]);
          }
        }
      }
    }
  }

  return (suma);
}

int Part_2() {
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  vector<string> input;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    input.PB(linea);
  }
  vector<vector<string>> matriz;
  for (int i = 0; i < input.size(); i++) {
    vector<string> fila;
    string num = "";
    for (int j = 0; j < input[i].size(); j++) {
      string letra = "";
      letra.PB(input[i][j]);
      if (isNumeric(letra)) {
        num.PB(input[i][j]);
      } else {
        for (int k = 0; k < num.size(); k++) {
          fila.PB(num);
        }
        num = "";
        fila.PB(letra);
      }
    }
    for (int k = 0; k < num.size(); k++) {
      fila.PB(num);
    }
    matriz.PB(fila);
  }
  int suma = 0;
  for (int i = 0; i < matriz.size(); i++) {
    for (int j = 0; j < matriz[i].size(); j++) {
      if (matriz[i][j] == "*") {
        int count = 0;
        int presum = 1;
        // Comprobamos arriba
        if (isNumeric(matriz[i - 1][j])) {
          presum *= stoi(matriz[i - 1][j]);
          count++;
        } else {
          if (isNumeric(matriz[i - 1][j - 1])) {
            presum *= stoi(matriz[i - 1][j - 1]);
            count++;
          }
          if (isNumeric(matriz[i - 1][j + 1])) {
            presum *= stoi(matriz[i - 1][j + 1]);
            count++;
          }
        }
        // Comprobamos izquierda
        if (isNumeric(matriz[i][j - 1])) {
          presum *= stoi(matriz[i][j - 1]);
          count++;
        }
        // Comprobamos derecha
        if (isNumeric(matriz[i][j + 1])) {
          presum *= stoi(matriz[i][j + 1]);
          count++;
        }
        // Comprobamos abajo
        if (isNumeric(matriz[i + 1][j])) {
          presum *= stoi(matriz[i + 1][j]);
          count++;
        } else {
          if (isNumeric(matriz[i + 1][j - 1])) {
            presum *= stoi(matriz[i + 1][j - 1]);
            count++;
          }
          if (isNumeric(matriz[i + 1][j + 1])) {
            presum *= stoi(matriz[i + 1][j + 1]);
            count++;
          }
        }
        if (count == 2) {
          suma += presum;
          cout << suma << endl;
        }
      }
    }
  }

  return (suma);
}

int main() {
  cout << Part_1() << endl;
  cout << Part_2() << endl;

  return 0;
}