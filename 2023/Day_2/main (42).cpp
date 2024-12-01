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
  int suma = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  int index = 0;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    index++;
    vector<string> s;
    string palabra = "";
    for (auto i : linea) {
      if (i != ' ') {
        palabra.PB(i);
      } else {
        s.PB(palabra);
        palabra = "";
      }
    }
    s.PB(palabra);
    int red = 12, green = 13, blue = 14;
    bool posible = true;
    for (int i = 0; i < s.size(); i = i + 2) {
      if (s[i + 1] == "R") {
        if (red < stoi(s[i])) {
          // cout << index << " R" << s[i] << endl;
          posible = false;
          break;
        }
      } else if (s[i + 1] == "G") {
        if (green < stoi(s[i])) {
          // cout << index << " G" << s[i] << endl;
          posible = false;
          break;
        }
      } else if (s[i + 1] == "B") {
        if (blue < stoi(s[i])) {
          // cout << index << " B" << s[i] << endl;
          posible = false;
          break;
        }
      }
    }
    if (posible) {
      suma += index;
    }
  }

  return (suma);
}

int Part_2() {
  int suma = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  int index = 0;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    index++;
    vector<string> s;
    string palabra = "";
    for (auto i : linea) {
      if (i != ' ') {
        palabra.PB(i);
      } else {
        s.PB(palabra);
        palabra = "";
      }
    }
    s.PB(palabra);
    int red = 0, green = 0, blue = 0;
    for (int i = 0; i < s.size(); i = i + 2) {
      if (s[i + 1] == "R") {
        red = max(stoi(s[i]), red);
      } else if (s[i + 1] == "G") {
        green = max(stoi(s[i]), green);
      } else if (s[i + 1] == "B") {
        blue = max(stoi(s[i]), blue);
      }
    }
    suma += red * green * blue;
  }

  return suma;
}

int main() {
  cout << Part_1() << endl;
  cout << Part_2() << endl;

  return 0;
}