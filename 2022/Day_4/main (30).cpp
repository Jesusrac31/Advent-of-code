#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int part_1() {
  int pareja = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    string input = "";
    vector<int> places(4);
    int index = 0;
    for (int i = 0; i < linea.size(); i++) {
      if (linea[i] == ' ') {
        places[index] = stoi(input);
        input = "";
        index++;
      } else {
        input += linea[i];
      }
    }
    places[index] = stoi(input);
    if (places[0] > places[2]) {
      if (places[1] <= places[3]) {
        pareja++;
      }
    } else if (places[0] < places[2]) {
      if (places[1] >= places[3]) {
        pareja++;
      }
    } else {
      pareja++;
    }
  }
  return (pareja); // Solución parte 1
}
int part_2() {
  int pareja = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    string input = "";
    vector<int> places(4);
    int index = 0;
    for (int i = 0; i < linea.size(); i++) {
      if (linea[i] == ' ') {
        places[index] = stoi(input);
        input = "";
        index++;
      } else {
        input += linea[i];
      }
    }
    places[index] = stoi(input);

    if (places[0] <= places[3] && places[1] >= places[3]) {
      pareja++;
    } else if (places[0] <= places[2] && places[1] >= places[2]) {
      pareja++;
    } else if (places[2] <= places[0] && places[3] >= places[0]) {
      pareja++;
    } else if (places[2] <= places[1] && places[3] >= places[1]) {
      pareja++;
    }
  }
  return (pareja); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1

  cout << part_2() << endl; // Solución parte 2

  return 0;
}