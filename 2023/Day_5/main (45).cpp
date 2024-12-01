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
  vector<string> input;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  int index = 0;
  vll semillas;
  vll semillas_copy;
  while (getline(archivo, linea)) {
    // cout << index << endl;
    if (index == 0) { // Obtiene las semillas de la primera línea
      string num = "";
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] == ' ') {
          semillas.PB(stol(num));
          num = "";
        } else {
          num.PB(linea[i]);
        }
      }
      semillas.PB(stol(num));
      copia(semillas, semillas_copy);
    } else if (linea != "") {
      // cout << "el " << index << endl;
      vll trans;
      string num = "";
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] == ' ') {
          trans.PB(stol(num));
          num = "";
        } else {
          num.PB(linea[i]);
        }
      }
      trans.PB(stol(num));
      // cout << trans[0] << " " << trans[1] << " " << trans[2] << endl;
      for (int i = 0; i < semillas.size(); i++) {
        if (semillas[i] >= trans[1] && semillas[i] < trans[1] + trans[2]) {
          cout << "semilla: " << i << endl;
          semillas_copy[i] = trans[0] + (semillas[i] - trans[1]);
        }
      }
    } else {
      cout << "change" << endl;
      semillas.clear();
      copia(semillas_copy, semillas);
      for (int i = 0; i < semillas.size(); i++) {
        cout << semillas[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < semillas_copy.size(); i++) {
        cout << semillas_copy[i] << " ";
      }
      cout << endl;
    }
    index++;
  }
  cout << "change" << endl;
  semillas.clear();
  copia(semillas_copy, semillas);
  ord(semillas);
  for (int i = 0; i < semillas.size(); i++) {
    cout << semillas[i] << " ";
  }
  cout << endl;

  return (semillas[0]);
}

lli Part_2() {
  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  vector<string> input;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  int index = 0;
  vll semillas;
  vll semillas_copy;
  while (getline(archivo, linea)) {
    if (index == 0) { // Obtiene las semillas de la primera línea
      string num = "";
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] == ' ') {
          if (semillas.size() % 2 == 0) {
            semillas.PB(stol(num));
          } else {
            semillas.PB(stol(num) + semillas[semillas.size() - 1]);
          }
          num = "";
        } else {
          num.PB(linea[i]);
        }
      }
      semillas.PB(stol(num) + semillas[semillas.size() - 1]);

      copia(semillas, semillas_copy);
    } else if (linea != "") {
      cout << "el " << index << endl;
      vll trans;
      string num = "";
      for (int i = 0; i < linea.size(); i++) {
        if (linea[i] == ' ') {
          trans.PB(stol(num));
          num = "";
        } else {
          num.PB(linea[i]);
        }
      }
      trans.PB(stol(num));
      cout << trans[0] << " " << trans[1] << " " << trans[2] << endl;

      for (int i = 0; i < semillas.size(); i = i + 2) {
        if (trans[1] <= semillas[i] && trans[1] + trans[2] >= semillas[i + 1]) {
          cout << "semilla: " << i << " metodo cambio completo\n";
          semillas_copy[i] += trans[0] - trans[1];
          semillas_copy[i + 1] += trans[0] - trans[1];
          if (semillas_copy[i] < 0) {
            cout << semillas[i] << " error min " << trans[0] - trans[1] << " "
                 << semillas_copy[i] << endl;
          }
          if (semillas_copy[i + 1] < 0) {
            cout << semillas[i + 1] << " error max " << trans[0] - trans[1]
                 << " " << semillas_copy[i+1] << endl;
          }
        } else if (trans[1] <= semillas[i] &&
                   trans[1] + trans[2] > semillas[i] &&
                   trans[1] + trans[2] < semillas[i + 1]) {
          cout << "semilla: " << i << " metodo cambio izquierda\n";
          semillas_copy.PB(trans[1] + trans[2]);
          semillas_copy.PB(semillas[i + 1]);
          semillas.PB(trans[1] + trans[2]);
          semillas.PB(semillas[i + 1]);
          semillas[i + 1] = trans[1] + trans[2];
          semillas_copy[i] += trans[0] - trans[1];
          semillas_copy[i + 1] = trans[0] + trans[2];
          if (semillas_copy[i] < 0) {
            cout << "error " << trans[0] - trans[1] << endl;
          }
        } else if (trans[1] > semillas[i] &&
                   trans[1] + trans[2] < semillas[i + 1]) {
          cout << "semilla: " << i << " metodo cambio medio\n";
          semillas_copy.PB(semillas[i]);
          semillas_copy.PB(trans[1]);
          semillas_copy.PB(trans[1] + trans[2]);
          semillas_copy.PB(semillas[i + 1]);
          semillas.PB(semillas[i]);
          semillas.PB(trans[1]);
          semillas.PB(trans[1] + trans[2]);
          semillas.PB(semillas[i + 1]);
          semillas[i] = trans[1];
          semillas[i + 1] = trans[1] + trans[2];
          semillas_copy[i] = trans[0];
          semillas_copy[i + 1] = trans[0] + trans[2];
        } else if (trans[1] > semillas[i] && trans[1] < semillas[i + 1] &&
                   trans[1] + trans[2] >= semillas[i + 1]) {
          cout << "semilla: " << i << " metodo cambio derecha\n";
          semillas_copy.PB(semillas[i]);
          semillas_copy.PB(trans[1]);
          semillas.PB(semillas[i]);
          semillas.PB(trans[1]);
          semillas[i] = trans[1];
          semillas_copy[i] = trans[0];
          semillas_copy[i + 1] += trans[0] - trans[1];
          if (semillas_copy[i + 1] < 0) {
            cout << "error " << trans[0] - trans[1] << endl;
          }
        }
      }
    } else {
      string pause;
      cout << "change" << endl;
      // ord(semillas_copy);
      semillas.clear();
      copia(semillas_copy, semillas);
      for (int i = 0; i < semillas.size(); i += 2) {
        cout << "Semilla: " << i << " -->\t" << semillas[i] << "\n\t\t\t\t"
             << semillas[i + 1] << endl;
      }
      cin >> pause;
    }
    index++;
  }
  cout << "change" << endl;
  semillas.clear();
  copia(semillas_copy, semillas);
  ord(semillas);
  /*for (int i = 0; i < semillas.size(); i += 2) {
        cout << "Semilla: " << i << " --> " << semillas[i] << " " << semillas[i
     + 1]
             << endl;
      }*/

  return (semillas[0]);
}

int main() {
  // cout << Part_1() << endl;
  cout << Part_2() << endl;

  return 0;
}