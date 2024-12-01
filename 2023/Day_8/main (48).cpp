#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<long int> vll;
typedef long int lli;
typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef map<int, vector<int>> miv;

// Funciones vector
#define PB(a) push_back(a);

bool sort_func(lli a, lli b) {
  if (a < b) {
    return true;
  } else {
    return false;
  }
}
#define ord(vect) sort(vect.begin(), vect.end());

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

lli maximo_comun_divisor(lli a, lli b) {
  int temporal; // Para no perder b
  while (b != 0) {
    temporal = b;
    b = a % b;
    a = temporal;
  }
  return a;
}

lli minimo_comun_multiplo(lli a, lli b) {
  return (a * b) / maximo_comun_divisor(a, b);
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
  // Obtener línea de archivo, y almacenar contenido en "linea"
  int index = 0;
  string instrucciones;
  map<string, pair<string, string>> diccionario;
  while (getline(archivo, linea)) {
    if (index == 0) {
      instrucciones = linea;
    } else {
      string el = "";
      vector<string> elementos;
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] != ' ') {
          el.PB(linea[i])
        } else {
          elementos.PB(el);
          el = "";
        }
      }
      elementos.PB(el);
      diccionario[elementos[0]] = make_pair(elementos[1], elementos[2]);
    }
    index++;
  }
  int indice = 0;
  string el_act = "AAA";
  while (true) {
    if (el_act == "ZZZ") {
      return (indice);
    }
    if (instrucciones[indice % instrucciones.size()] == 'L') {
      el_act = diccionario[el_act].first;
    } else {
      el_act = diccionario[el_act].second;
    }
    indice++;
  }
}

lli Part_2() {
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  int index = 0;
  string instrucciones;
  map<string, pair<string, string>> diccionario;
  vector<string> iniciales;
  while (getline(archivo, linea)) {
    if (index == 0) {
      instrucciones = linea;
    } else {
      string el = "";
      vector<string> elementos;
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] != ' ') {
          el.PB(linea[i])
        } else {
          elementos.PB(el);
          el = "";
        }
      }
      elementos.PB(el);
      diccionario[elementos[0]] = make_pair(elementos[1], elementos[2]);
      if (elementos[0][2] == 'A') {
        iniciales.PB(elementos[0]);
      }
    }
    index++;
  }

  vll ciclos;
  for (int i = 0; i < iniciales.size(); i++) {
    lli indice = 0;
    while (true) {
      if (iniciales[i][2] == 'Z') {
        ciclos.PB(indice);
        break;
      }
      if (instrucciones[indice % instrucciones.size()] == 'L') {
        iniciales[i] = diccionario[iniciales[i]].first;
      } else {
        iniciales[i] = diccionario[iniciales[i]].second;
      }
      indice++;
    }
  }
  lli sol = ciclos[0];
  cout << ciclos[0] << " ";
  for (int i = 1; i<ciclos.size(); i++) {
    cout << ciclos[i] << " ";
    sol = minimo_comun_multiplo(sol, ciclos[i]);
  }
  cout << endl;

  return (sol);
}

int main() {

  cout << Part_1() << endl;
  cout << Part_2() << endl;

  return 0;
}