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
  int suma = 0;
  while (getline(archivo, linea)) {
    // cout << linea << endl;
    vector<int> win;
    string num = "";
    int pos = 0;
    int puntos = -1;
    if (linea[0] == ' ') {
      pos++;
    }
    for (int i = pos; win.size() < 10; i++) {
      if (linea[i] == ' ') {
        // cout << num << endl;
        win.PB(stoi(num));
        num = "";
      } else {
        num.PB(linea[i]);
      }
      pos = i;
    }
    for (int i = pos + 1; i < linea.size(); i++) {
      if (linea[i] == ' ') {
        // cout << num << endl;
        for (int j = 0; j < win.size(); j++) {
          if (win[j] == stoi(num)) {
            puntos++;
            break;
          }
        }
        num = "";
      } else {
        num.PB(linea[i]);
      }
    }
    cout << puntos << " " << suma << endl;
    if (puntos != -1) {
      suma = suma + pow(2, puntos);
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
  int suma = 0;
  vi copias;
  for (int i = 0; i < 219; i++) {
    copias.PB(1);
  }
  int index = 0;
  while (getline(archivo, linea)) {
    // cout << linea << endl;
    vector<int> win;
    string num = "";
    int pos = 0;
    int puntos = -1;
    if (linea[0] == ' ') {
      pos++;
    }
    for (int i = pos; win.size() < 10; i++) {
      if (linea[i] == ' ') {
        // cout << num << endl;
        win.PB(stoi(num));
        num = "";
      } else {
        num.PB(linea[i]);
      }
      pos = i;
    }
    for (int i = pos + 1; i < linea.size(); i++) {
      if (linea[i] == ' ') {
        // cout << num << endl;
        for (int j = 0; j < win.size(); j++) {
          if (win[j] == stoi(num)) {
            puntos++;
            break;
          }
        }
        num = "";
      } else {
        num.PB(linea[i]);
      }
    }
    puntos++;
    for (int i = 0; i < puntos; i++){
      copias[index+i+1]=copias[index+i+1] + copias[index];
    }
    suma = suma + copias[index];
    index++;
  }

  return (suma);
}

int main() {
  cout << Part_1() << endl;
  cout << Part_2() << endl;

  return 0;
}