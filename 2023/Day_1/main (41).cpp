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
  int sum = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    char num1, num2;
    string numero;
    bool primero = false;

    for (auto i : linea) {
      if (!primero) {
        if (i == '0') {
          num1 = '0';
          num2 = '0';
          primero = true;
        }
        if (i == '1') {
          num1 = '1';
          num2 = '1';
          primero = true;
        }
        if (i == '2') {
          num1 = '2';
          num2 = '2';
          primero = true;
        }
        if (i == '3') {
          num1 = '3';
          num2 = '3';
          primero = true;
        }
        if (i == '4') {
          num1 = '4';
          num2 = '4';
          primero = true;
        }
        if (i == '5') {
          num1 = '5';
          num2 = '5';
          primero = true;
        }
        if (i == '6') {
          num1 = '6';
          num2 = '6';
          primero = true;
        }
        if (i == '7') {
          num1 = '7';
          num2 = '7';
          primero = true;
        }
        if (i == '8') {
          num1 = '8';
          num2 = '8';
          primero = true;
        }
        if (i == '9') {
          num1 = '9';
          num2 = '9';
          primero = true;
        }
      } else {
        if (i == '0') {
          num2 = '0';
        }
        if (i == '1') {
          num2 = '1';
        }
        if (i == '2') {
          num2 = '2';
        }
        if (i == '3') {
          num2 = '3';
        }
        if (i == '4') {
          num2 = '4';
        }
        if (i == '5') {
          num2 = '5';
        }
        if (i == '6') {
          num2 = '6';
        }
        if (i == '7') {
          num2 = '7';
        }
        if (i == '8') {
          num2 = '8';
        }
        if (i == '9') {
          num2 = '9';
        }
      }
    }
    numero = "";
    numero.PB(num1);
    numero.PB(num2);
    sum = sum + stoi(numero);
  }

  return (sum);
}

int Part_2() {
  int sum = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    char num1, num2;
    string numero;
    bool primero = false;
    string spelt3 = "---";
    string spelt4 = "----";
    string spelt5 = "-----";
    for (auto i : linea) {
      if (!primero) {
        if (i == '0') {
          num1 = '0';
          num2 = '0';
          primero = true;
        } else if (i == '1') {
          num1 = '1';
          num2 = '1';
          primero = true;
        } else if (i == '2') {
          num1 = '2';
          num2 = '2';
          primero = true;
        } else if (i == '3') {
          num1 = '3';
          num2 = '3';
          primero = true;
        } else if (i == '4') {
          num1 = '4';
          num2 = '4';
          primero = true;
        } else if (i == '5') {
          num1 = '5';
          num2 = '5';
          primero = true;
        } else if (i == '6') {
          num1 = '6';
          num2 = '6';
          primero = true;
        } else if (i == '7') {
          num1 = '7';
          num2 = '7';
          primero = true;
        } else if (i == '8') {
          num1 = '8';
          num2 = '8';
          primero = true;
        } else if (i == '9') {
          num1 = '9';
          num2 = '9';
          primero = true;
        } else {
          spelt3.erase(0, 1);
          spelt4.erase(0, 1);
          spelt5.erase(0, 1);
          spelt3.PB(i);
          spelt4.PB(i);
          spelt5.PB(i);
          if (spelt3.compare("one") == 0) {
            num1 = '1';
            num2 = '1';
            primero = true;
          }
          if (spelt3.compare("two") == 0) {
            num1 = '2';
            num2 = '2';
            primero = true;
          }
          if (spelt5.compare("three") == 0) {
            num1 = '3';
            num2 = '3';
            primero = true;
          }
          if (spelt4.compare("four") == 0) {
            num1 = '4';
            num2 = '4';
            primero = true;
          }
          if (spelt4.compare("five") == 0) {
            num1 = '5';
            num2 = '5';
            primero = true;
          }
          if (spelt3.compare("six") == 0) {
            num1 = '6';
            num2 = '6';
            primero = true;
          }
          if (spelt5.compare("seven") == 0) {
            num1 = '7';
            num2 = '7';
            primero = true;
          }
          if (spelt5.compare("eight") == 0) {
            num1 = '8';
            num2 = '8';
            primero = true;
          }
          if (spelt4.compare("nine") == 0) {
            num1 = '9';
            num2 = '9';
            primero = true;
          }
        }
      } else {
        if (i == '0') {
          num2 = '0';
        } else if (i == '1') {
          num2 = '1';
        } else if (i == '2') {
          num2 = '2';
        } else if (i == '3') {
          num2 = '3';
        } else if (i == '4') {
          num2 = '4';
        } else if (i == '5') {
          num2 = '5';
        } else if (i == '6') {
          num2 = '6';
        } else if (i == '7') {
          num2 = '7';
        } else if (i == '8') {
          num2 = '8';
        } else if (i == '9') {
          num2 = '9';
        } else {
          spelt3.erase(0, 1);
          spelt4.erase(0, 1);
          spelt5.erase(0, 1);
          spelt3.PB(i);
          spelt4.PB(i);
          spelt5.PB(i);
          if (spelt3.compare("one") == 0) {
            num2 = '1';
          }
          if (spelt3.compare("two") == 0) {
            num2 = '2';
          }
          if (spelt5.compare("three") == 0) {
            num2 = '3';
          }
          if (spelt4.compare("four") == 0) {
            num2 = '4';
          }
          if (spelt4.compare("five") == 0) {
            num2 = '5';
          }
          if (spelt3.compare("six") == 0) {
            num2 = '6';
          }
          if (spelt5.compare("seven") == 0) {
            num2 = '7';
          }
          if (spelt5.compare("eight") == 0) {
            num2 = '8';
          }
          if (spelt4.compare("nine") == 0) {
            num2 = '9';
          }
        }
      }
    }
    numero = "";
    numero.PB(num1);
    numero.PB(num2);
    sum = sum + stoi(numero);
  }

  return (sum);
}

int main() {
  cout << Part_1() << endl;
  cout << Part_2() << endl;

  return 0;
}