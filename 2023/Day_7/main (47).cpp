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
  vector<pair<string, int>> datos; // Recogida de datos
  while (getline(archivo, linea)) {
    pair<string, int> p;
    string comb = "", num = "";
    bool primero = true;
    for (int i = 0; i < linea.size(); i++) {
      if (linea[i] == ' ') {
        primero = false;
        p.first = comb;
      } else {
        if (primero) {
          comb.PB(linea[i]);
        } else {
          num.PB(linea[i]);
        }
      }
    }

    p.second = stoi(num);
    datos.PB(p);
  }

  // Clasificamos los datos en función de que son
  vector<pair<string, int>> five;
  vector<pair<string, int>> four;
  vector<pair<string, int>> full;
  vector<pair<string, int>> three;
  vector<pair<string, int>> two_pair;
  vector<pair<string, int>> one_pair;
  vector<pair<string, int>> high_card;

  for (int i = 0; i < datos.size(); i++) {
    pair<string, int> p = datos[i];
    ord(p.first);
    if (p.first[0] == p.first[4]) {
      five.PB(datos[i]);
    } else if (p.first[0] == p.first[3] || p.first[1] == p.first[4]) {
      four.PB(datos[i]);
    } else if ((p.first[0] == p.first[2] && p.first[3] == p.first[4]) ||
               (p.first[0] == p.first[1] && p.first[2] == p.first[4])) {
      full.PB(datos[i]);
    } else if (p.first[0] == p.first[2] || p.first[1] == p.first[3] ||
               p.first[2] == p.first[4]) {
      three.PB(datos[i]);
    } else if ((p.first[0] == p.first[1]) + (p.first[1] == p.first[2]) +
                   (p.first[2] == p.first[3]) + (p.first[3] == p.first[4]) ==
               2) {
      two_pair.PB(datos[i]);
    } else if (p.first[0] == p.first[1] || p.first[1] == p.first[2] ||
               p.first[2] == p.first[3] || p.first[3] == p.first[4]) {
      one_pair.PB(datos[i]);
    } else {
      high_card.PB(datos[i]);
    }
  }
  ord(five);
  ord(four);
  ord(full);
  ord(three);
  ord(two_pair);
  ord(one_pair);
  ord(high_card);

  lli suma = 0, multi = datos.size();
  for (int i = 0; i < five.size(); i++) {
    suma += five[i].second * multi;
    multi--;
  }
  for (int i = 0; i < four.size(); i++) {
    suma += four[i].second * multi;
    multi--;
  }
  for (int i = 0; i < full.size(); i++) {
    suma += full[i].second * multi;
    multi--;
  }
  for (int i = 0; i < three.size(); i++) {
    suma += three[i].second * multi;
    multi--;
  }
  for (int i = 0; i < two_pair.size(); i++) {
    suma += two_pair[i].second * multi;
    multi--;
  }
  for (int i = 0; i < one_pair.size(); i++) {
    suma += one_pair[i].second * multi;
    multi--;
  }
  for (int i = 0; i < high_card.size(); i++) {
    suma += high_card[i].second * multi;
    multi--;
  }

  return (suma);
}

int Part_2() {
  string nombreArchivo = "input2.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  vector<pair<string, int>> datos; // Recogida de datos
  while (getline(archivo, linea)) {
    pair<string, int> p;
    string comb = "", num = "";
    bool primero = true;
    for (int i = 0; i < linea.size(); i++) {
      if (linea[i] == ' ') {
        primero = false;
        p.first = comb;
      } else {
        if (primero) {
          comb.PB(linea[i]);
        } else {
          num.PB(linea[i]);
        }
      }
    }

    p.second = stoi(num);
    datos.PB(p);
  }

  // Clasificamos los datos en función de que son
  vector<pair<string, int>> five;
  vector<pair<string, int>> four;
  vector<pair<string, int>> full;
  vector<pair<string, int>> three;
  vector<pair<string, int>> two_pair;
  vector<pair<string, int>> one_pair;
  vector<pair<string, int>> high_card;

  for (int i = 0; i < datos.size(); i++) {
    pair<string, int> p = datos[i];
    ord(p.first);
    int jotas = 0;
    for (int j = 0; j < p.first.size(); j++) {
      if (p.first[j] == 'N') {
        jotas++;
      }
    }
    if (p.first[0] == p.first[4]) {
      five.PB(datos[i]);
    } else if (p.first[0] == p.first[3] || p.first[1] == p.first[4]) {
      if (jotas == 1 || jotas == 4) {
        five.PB(datos[i]);
      } else {
        four.PB(datos[i]);
      }
    } else if ((p.first[0] == p.first[2] && p.first[3] == p.first[4]) ||
               (p.first[0] == p.first[1] && p.first[2] == p.first[4])) {
      if (jotas == 3 || jotas == 2) {
        five.PB(datos[i]);
      } else {
        full.PB(datos[i]);
      }
    } else if (p.first[0] == p.first[2] || p.first[1] == p.first[3] ||
               p.first[2] == p.first[4]) {
      if (jotas == 3 || jotas == 1) {
        four.PB(datos[i]);
      } else {
        three.PB(datos[i]);
      }
    } else if ((p.first[0] == p.first[1]) + (p.first[1] == p.first[2]) +
                   (p.first[2] == p.first[3]) + (p.first[3] == p.first[4]) ==
               2) {
      if (jotas == 2) {
        four.PB(datos[i]);
      } else if (jotas == 1) {
        full.PB(datos[i]);
      } else {
        two_pair.PB(datos[i]);
      }
    } else if (p.first[0] == p.first[1] || p.first[1] == p.first[2] ||
               p.first[2] == p.first[3] || p.first[3] == p.first[4]) {
      if (jotas == 2 || jotas == 1) {
        three.PB(datos[i]);
      } else {
        one_pair.PB(datos[i]);
      }
    } else {
      if (jotas == 1) {
        one_pair.PB(datos[i])
      } else {
        high_card.PB(datos[i]);
      }
    }
  }
  ord(five);
  ord(four);
  ord(full);
  ord(three);
  ord(two_pair);
  ord(one_pair);
  ord(high_card);

  lli suma = 0, multi = datos.size();
  for (int i = 0; i < five.size(); i++) {
    suma += five[i].second * multi;
    multi--;
  }
  for (int i = 0; i < four.size(); i++) {
    suma += four[i].second * multi;
    multi--;
  }
  for (int i = 0; i < full.size(); i++) {
    suma += full[i].second * multi;
    multi--;
  }
  for (int i = 0; i < three.size(); i++) {
    suma += three[i].second * multi;
    multi--;
  }
  for (int i = 0; i < two_pair.size(); i++) {
    suma += two_pair[i].second * multi;
    multi--;
  }
  for (int i = 0; i < one_pair.size(); i++) {
    suma += one_pair[i].second * multi;
    multi--;
  }
  for (int i = 0; i < high_card.size(); i++) {
    suma += high_card[i].second * multi;
    multi--;
  }

  return (suma);
}

int main() {
  // Cambiamos el input para más comodidad, nuevo input:
  /*
    A --> A
    K --> B
    Q --> C
    J --> D
    T --> E
    9 --> F
    8 --> G
    7 --> H
    6 --> I
    5 --> J
    4 --> K
    3 --> L
    2 --> M
  */
  // Para la parte 2 la J será N
  cout << Part_1() << endl;
  cout << Part_2() << endl;

  return 0;
}