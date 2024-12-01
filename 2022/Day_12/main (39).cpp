#include <fstream>
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int miniDist(int distance[], bool Tset[], int nodos) // finding minimum distance
{
  int minimum = INT_MAX, ind;

  for (int k = 0; k < nodos; k++) {
    if (Tset[k] == false && distance[k] <= minimum) {
      minimum = distance[k];
      ind = k;
    }
  }
  return ind;
}

int DijkstraAlgo(vector<vector<int>> graph, int src, int dest,
                 int nodos) // adjacency matrix
{
  int distance[nodos]; // // array to calculate the minimum distance for each
                       // node
  bool Tset[nodos]; // boolean array to mark visited and unvisited for each node

  for (int k = 0; k < nodos; k++) {
    distance[k] = INT_MAX;
    Tset[k] = false;
  }

  distance[src] = 0; // Source vertex distance is set 0

  for (int k = 0; k < nodos; k++) {
    int m = miniDist(distance, Tset, nodos);
    Tset[m] = true;
    for (int k = 0; k < nodos; k++) {
      // updating the distance of neighbouring vertex
      if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX &&
          distance[m] + graph[m][k] < distance[k])
        distance[k] = distance[m] + graph[m][k];
    }
  }
  return (distance[dest]);
}

int part_1() {
  vector<int> mapa;
  int pos_inicial;
  int pos_final;
  int nodos = 0;
  int tamano = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    tamano = linea.size();
    for (int i = 0; i < linea.size(); i++) {
      nodos++;
      if (linea[i] == 'S') {
        mapa.push_back(0);
        pos_inicial = nodos - 1;
      } else if (linea[i] == 'E') {
        mapa.push_back(25);
        pos_final = nodos - 1;
      } else {
        mapa.push_back((int)linea[i] - 97);
      }
    }
  }

  int resp = 0;

  // Dijkstra
  vector<vector<int>> graph =
      {}; // Fila es la distancia entre nodo fila y nodo columna (empieza fila)

  for (int i = 0; i < nodos; i++) {
    graph.push_back({});
    for (int j = 0; j < nodos; j++) {
      graph.back().push_back(0);
      if (i % tamano != 0) {
        if (i - j == 1 && mapa[i] >= mapa[j] - 1) { // Izquierda
          graph.back().back() = 1;
        }
      }
      if (i % tamano != tamano - 1) {
        if (j - i == 1 && mapa[i] >= mapa[j] - 1) { // Derecha
          graph.back().back() = 1;
        }
      }
      if (i >= tamano) {
        if (i - j == tamano && mapa[i] >= mapa[j] - 1) { // Arriba
          graph.back().back() = 1;
        }
      }
      if (i <= mapa.size() - 1) {
        if (j - i == tamano && mapa[i] >= mapa[j] - 1) { // Abajo
          graph.back().back() = 1;
        }
      }
    }
  }

  return (
      DijkstraAlgo(graph, pos_inicial, pos_final, nodos)); // Solución parte 1
}
int part_2() {
  vector<int> mapa;
  vector<int> pos_inicial;
  int pos_final;
  int nodos = 0;
  int tamano = 0;

  string nombreArchivo = "input.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
    tamano = linea.size();
    for (int i = 0; i < linea.size(); i++) {
      nodos++;
      if (linea[i] == 'S' || linea[i] == 'a') {
        mapa.push_back(0);
        pos_inicial.push_back(nodos - 1);
      } else if (linea[i] == 'E') {
        mapa.push_back(25);
        pos_final = nodos - 1;
      } else {
        mapa.push_back((int)linea[i] - 97);
      }
    }
  }

  int resp = 0;

  // Dijkstra
  vector<vector<int>> graph =
      {}; // Fila es la distancia entre nodo fila y nodo columna (empieza fila)

  for (int i = 0; i < nodos; i++) {
    graph.push_back({});
    for (int j = 0; j < nodos; j++) {
      graph.back().push_back(0);
      if (i % tamano != 0) {
        if (i - j == 1 && mapa[i] >= mapa[j] - 1) { // Izquierda
          graph.back().back() = 1;
        }
      }
      if (i % tamano != tamano - 1) {
        if (j - i == 1 && mapa[i] >= mapa[j] - 1) { // Derecha
          graph.back().back() = 1;
        }
      }
      if (i >= tamano) {
        if (i - j == tamano && mapa[i] >= mapa[j] - 1) { // Arriba
          graph.back().back() = 1;
        }
      }
      if (i <= mapa.size() - 1) {
        if (j - i == tamano && mapa[i] >= mapa[j] - 1) { // Abajo
          graph.back().back() = 1;
        }
      }
    }
  }
  int min = -1;
  int com;

  cout << pos_inicial.size() << endl;
  for (int i = 0; i < pos_inicial.size(); i++) {
    cout << pos_inicial[i] / tamano << endl;
    com = DijkstraAlgo(graph, pos_inicial[i], pos_final, nodos);
    if (min == -1 || com < min) {
      min = com;
    }
  }
  return (min); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1
  cout << part_2() << endl; // Solución parte 2

  return 0;
}