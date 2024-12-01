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

bool sort_func(lli a, lli b) {
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

lli Part_1() {
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  vi times;
  vi dist;
  int index = 0;
  while (getline(archivo, linea)) {
    if (index == 0) {
      string num = "";
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] == ' ') {
          times.PB(stoi(num));
          num = "";
        } else {
          num.PB(linea[i]);
        }
      }
      times.PB(stoi(num));
    } else {
      string num = "";
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] == ' ') {
          dist.PB(stoi(num));
          num = "";
        } else {
          num.PB(linea[i]);
        }
      }
      dist.PB(stoi(num));
    }
    index++;
  }

  // Empieza código
  lli p = 1;
  for (int i = 0; i < times.size(); i++) {
    lli sol1, sol2;
    sol1 = (times[i] - sqrt(times[i] * times[i] - 4 * dist[i])) / 2 + 1;
    sol2 = (times[i] + sqrt(times[i] * times[i] - 4 * dist[i])) / 2;
    p *= sol2 - sol1 + 1;
  }

  return (p);
}

lli Part_2() {
  string nombreArchivo = "input2.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  lli times = 53837288;
  lli dist = 333163512891532;

  // Empieza código
  lli sol1, sol2;
  sol1 = (times - sqrt(times * times - 4 * dist)) / 2 + 1;
  sol2 = (times + sqrt(times * times - 4 * dist)) / 2;

  return (sol2 - sol1 + 1);
}

int main() {
  cout << Part_1() << endl;
  cout << Part_2() << endl;

  return 0;
}