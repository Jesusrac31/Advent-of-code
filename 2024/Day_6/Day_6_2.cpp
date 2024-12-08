//Librerías incluidas en #include<bitstdc++.h>
#include<algorithm>
#include<array>
#include<atomic>
#include<bitset>
#include<ccomplex>
#include<cerrno>
#include<cfenv>
#include<cfloat>
#include<chrono>
#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<complex>
#include<condition_variable>
#include<csetjmp>
#include<csignal>
#include<cstdalign>
#include<cstdarg>
#include<cstdbool>
#include<cstddef>
#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctgmath>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<forward_list>
#include<fstream>
#include<functional>
#include<future>
#include<initializer_list>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<mutex>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<random>
#include<ratio>
#include<regex>
#include<scoped_allocator>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<system_error>
#include<thread>
#include<tuple>
#include<type_traits>
#include<typeindex>
#include<typeinfo>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<valarray>
#include<vector>
#include <stdlib.h>
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
  cout << "\n";
}

void Imprime2d(vector<vi> vect) {
  for (int j = 0; j<vect.size(); j++){
    for (int i = 0; i < vect[j].size(); i++) {
        cout << vect[j][i] << " ";
    }
    cout << "\n";
  }
}

void Imprime_set(set<int> s) {
  copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

int maximo_comun_divisor(int a, int b) {
  int temporal; // Para no perder b
  while (b != 0) {
    temporal = b;
    b = a % b;
    a = temporal;
  }
  return a;
}

int minimo_comun_multiplo(int a, int b) {
  return (a * b) / maximo_comun_divisor(a, b);
}

bool isNumeric(string const &str) {
  auto it = str.begin();
  while (it != str.end() && isdigit(*it)) {
    it++;
  }
  return !str.empty() && it == str.end();
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

int solve() {
  // Code aquí
  vector<string> mapa, mapa_copy;
  string el;
  while(cin >> el){
    mapa.PB(el);
  }
  pii coords_act, coords_init;
  set<pii> coords_visited;
  int dir;
  vector<pii> suma = {{-1, 0}, {0,1}, {1,0}, {0,-1}};
  vector<char> caracter = {'^', '>', 'v', '<'};
  for (int i = 0; i<mapa.size(); i++){
    for(int j = 0; j<mapa[i].size(); j++){
        if(mapa[i][j] == '^'){
            coords_act.first = i;
            coords_act.second = j;
            dir = 0;
            break;
        }
        if(mapa[i][j] == '>'){
            coords_act.first = i;
            coords_act.second = j;
            dir = 1;
            break;
        }
        if(mapa[i][j] == 'v'){
            coords_act.first = i;
            coords_act.second = j;
            dir = 2;
            break;
        }
        if(mapa[i][j] == '<'){
            coords_act.first = i;
            coords_act.second = j;
            dir = 3;
            break;
        }
    }
  }
  coords_init = coords_act;
  copia(mapa, mapa_copy);
  while(true){
    //cout << coords_act.first << " " << coords_act.second << endl;
    coords_visited.insert(coords_act);
    if ((coords_act.first == 0 &&  dir == 0) || (coords_act.first == mapa.size()-1 && dir == 2) || (coords_act.second == 0 && dir == 3) || (coords_act.second == mapa[0].size()-1 && dir == 1)){
        break;
    } else {
        if (mapa[coords_act.first+suma[dir].first][coords_act.second+suma[dir].second] == '.'){
            mapa[coords_act.first+suma[dir].first][coords_act.second+suma[dir].second] = mapa[coords_act.first][coords_act.second];
            mapa[coords_act.first][coords_act.second] = '.';
            coords_act.first+=suma[dir].first;
            coords_act.second+=suma[dir].second;
        } else {
            dir++;
            dir = dir%4;
            mapa[coords_act.first][coords_act.second] = caracter[dir];
        }
    }
    /*for (int i = 0; i<mapa.size(); i++){
        cout << mapa[i] << endl;
    }
    cout<<endl;*/
  }
  // Candidatos a ser la casilla que loopea
  for (auto it = coords_visited.begin(); it != coords_visited.end(); it++){
    cout << "(" << (*it).first << ", " << (*it).second << ") , ";
  }
  cout << endl;
  cout << coords_visited.size() << endl;
  cout << endl;
  
  int sol = 0, counter = 0;
  pii coords_obstacle, coords_loop;
  for (auto it = coords_visited.begin(); it != coords_visited.end(); it++){
    counter++;
    cout << counter << endl;
    mapa.clear();
    copia(mapa_copy, mapa);
    coords_obstacle = *it;
    mapa[coords_obstacle.first][coords_obstacle.second] = 'O';
    bool iniciado = false;
    dir = 0;
    coords_act = coords_init;
    //cout << "NEW" << endl;
    /*for (int i = 0; i<mapa.size(); i++){
        cout << mapa[i] << endl;
    }
    cout<<endl;*/
    int aumento = 0;
    while(true){
        aumento++;
      //cout << coords_act.first << " " << coords_act.second << endl;
      if (aumento >=99999){
        sol++;
        break;
      }
      if ((coords_act.first == 0 &&  dir == 0) || (coords_act.first == mapa.size()-1 && dir == 2) || (coords_act.second == 0 && dir == 3) || (coords_act.second == mapa[0].size()-1 && dir == 1)){
          //cout << "NO LOOP" << endl;
          break;
      } else {
          if (mapa[coords_act.first+suma[dir].first][coords_act.second+suma[dir].second] == '.'){
              mapa[coords_act.first+suma[dir].first][coords_act.second+suma[dir].second] = mapa[coords_act.first][coords_act.second];
              mapa[coords_act.first][coords_act.second] = '.';
              coords_act.first+=suma[dir].first;
              coords_act.second+=suma[dir].second;
          } else {
              if (mapa[coords_act.first+suma[dir].first][coords_act.second+suma[dir].second] == 'O'){
                  //cout << "Interacción con obstaculo" << "(" << coords_act.first << ", " << coords_act.second << ")" << endl;
                  if (!iniciado){
                      coords_loop = coords_act;
                      //cout << "(" << coords_loop.first << ", " << coords_loop.second << ")" << endl;
                      iniciado = true;
                  } else {
                    //cout << "Interacción con obstaculo" << "(" << coords_act.first << ", " << coords_act.second << ")" << endl;
                      if (coords_loop == coords_act){
                          // Loop detected
                          //cout << "###  LOOP  ###" << endl;
                          sol++;
                          break;
                      }
                  }
              }
              dir++;
              dir = dir%4;
              mapa[coords_act.first][coords_act.second] = caracter[dir];
          }
      }
      /*for (int i = 0; i<mapa.size(); i++){
          cout << mapa[i] << endl;
      }
      cout<<endl;*/
    }
    mapa[coords_obstacle.first][coords_obstacle.second] = '.';
    //cout << "-----------------------" << endl;
  }
  cout << sol << endl;

  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr); 
  solve();
  return 0;
}
