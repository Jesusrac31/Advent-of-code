#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part_1() {
  vector<vector<int>> monos = {{64, 89, 65, 95},
                               {76, 66, 74, 87, 70, 56, 51, 66},
                               {91, 60, 63},
                               {92, 61, 79, 97, 79},
                               {93, 54},
                               {60, 79, 92, 69, 88, 82, 70},
                               {64, 57, 73, 89, 55, 53},
                               {62}};
  vector<int> condicion = {3, 13, 2, 11, 5, 17, 19, 7};
  vector<int> ifTrue = {4, 7, 6, 2, 1, 4, 0, 3};
  vector<int> ifFalse = {1, 3, 5, 6, 7, 0, 5, 2};
  int bored = 3;

  vector<int> inspection = {0, 0, 0, 0, 0, 0, 0, 0};
  int rondas = 20;
  while (rondas--) {
    for (int i = 0; i < monos.size(); i++) {
      for (int j = 0; j < monos[i].size(); j = 0) {
        if (i == 0) {
          monos[i][j] = monos[i][j] * 7;
        } else if (i == 1) {
          monos[i][j] = monos[i][j] + 5;
        } else if (i == 2) {
          monos[i][j] = monos[i][j] * monos[i][j];
        } else if (i == 3) {
          monos[i][j] = monos[i][j] + 6;
        } else if (i == 4) {
          monos[i][j] = monos[i][j] * 11;
        } else if (i == 5) {
          monos[i][j] = monos[i][j] + 8;
        } else if (i == 6) {
          monos[i][j] = monos[i][j] + 1;
        } else {
          monos[i][j] = monos[i][j] + 4;
        }
        monos[i][j] /= bored;
        inspection[i]++;

        if (monos[i][j] % condicion[i] == 0) {
          monos[ifTrue[i]].push_back(monos[i][j]);
        } else {
          monos[ifFalse[i]].push_back(monos[i][j]);
        }
        monos[i].erase(monos[i].begin());
      }
    }
  }
  int maxi1 = 0;
  int maxi2 = 0;
  int aux;
  for (int i = 0; i < inspection.size(); i++) {
    if (inspection[i] > maxi2) {
      maxi2 = inspection[i];
      if (maxi2 > maxi1) {
        aux = maxi1;
        maxi1 = maxi2;
        maxi2 = aux;
      }
    }
  }
  return (maxi1 * maxi2); // Solución parte 1
}
long long int part_2() {
  vector<vector<long long int>> monos = {{64, 89, 65, 95},
                                         {76, 66, 74, 87, 70, 56, 51, 66},
                                         {91, 60, 63},
                                         {92, 61, 79, 97, 79},
                                         {93, 54},
                                         {60, 79, 92, 69, 88, 82, 70},
                                         {64, 57, 73, 89, 55, 53},
                                         {62}};
  vector<long long int> condicion = {3, 13, 2, 11, 5, 17, 19, 7};
  vector<long long int> ifTrue = {4, 7, 6, 2, 1, 4, 0, 3};
  vector<long long int> ifFalse = {1, 3, 5, 6, 7, 0, 5, 2};
  long long int bored = 1;

  vector<long long int> inspection = {0, 0, 0, 0, 0, 0, 0, 0};
  int rondas = 10000;
  while (rondas--) {
    for (int i = 0; i < monos.size(); i++) {
      for (int j = 0; j < monos[i].size(); j = 0) {
        monos[i][j] = monos[i][j] % 9699690;

        if (i == 0) {
          monos[i][j] = monos[i][j] * 7;
        } else if (i == 1) {
          monos[i][j] = monos[i][j] + 5;
        } else if (i == 2) {
          monos[i][j] = monos[i][j] * monos[i][j];
        } else if (i == 3) {
          monos[i][j] = monos[i][j] + 6;
        } else if (i == 4) {
          monos[i][j] = monos[i][j] * 11;
        } else if (i == 5) {
          monos[i][j] = monos[i][j] + 8;
        } else if (i == 6) {
          monos[i][j] = monos[i][j] + 1;
        } else {
          monos[i][j] = monos[i][j] + 4;
        }
        monos[i][j] /= bored;
        inspection[i]++;

        if (monos[i][j] % condicion[i] == 0) {
          monos[ifTrue[i]].push_back(monos[i][j]);
        } else {
          monos[ifFalse[i]].push_back(monos[i][j]);
        }
        monos[i].erase(monos[i].begin());
      }
    }
  }
  long long int maxi1 = 0;
  long long int maxi2 = 0;
  long long int aux;
  for (int i = 0; i < inspection.size(); i++) {
    if (inspection[i] > maxi2) {
      maxi2 = inspection[i];
      if (maxi2 > maxi1) {
        aux = maxi1;
        maxi1 = maxi2;
        maxi2 = aux;
      }
    }
  }
  return (maxi1 * maxi2); // Solución parte 2
}

int main() {
  cout << part_1() << endl; // Solución parte 1
  cout << part_2() << endl; // Solución parte 2

  return 0;
}