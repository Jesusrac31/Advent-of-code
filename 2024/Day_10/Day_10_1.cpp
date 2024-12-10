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

set<int> nueves = {};
int filas = 0;
int columnas = 0;
vector<string> mapa;

int par2int(int x, int y){
    return x*columnas+y;
}

int recorre(int x, int y){
    cout << x << " " << y << " ";
    if (mapa[x][y] == '9'){
        cout << "Es 9" << endl;
        nueves.insert(par2int(x,y));
        return 0;
    }
    if (x+1<filas){
        if (stoi(mapa[x].substr(y,1))+1 == stoi(mapa[x+1].substr(y,1))){
            cout << "ABAJO" << endl;
            recorre(x+1,y);
        }
    }
    if (x-1>=0){
        if (stoi(mapa[x].substr(y,1))+1 == stoi(mapa[x-1].substr(y,1))){
            cout << "ARRIBA" << endl;
            recorre(x-1,y);
        }
    }
    if (y+1<columnas){
        if (stoi(mapa[x].substr(y,1))+1 == stoi(mapa[x].substr(y+1,1))){
            cout << "DERECHA" << endl;
            recorre(x,y+1);
        }
    }
    if (y-1>=0){
        if (stoi(mapa[x].substr(y,1))+1 == stoi(mapa[x].substr(y-1,1))){
            cout << "IZQUIERDA" << endl;
            recorre(x,y-1);
        }
    }
    cout << "Sale" << endl;
    return 0;
}

int solve() {
  // Code aquí
  mapa.clear();
  string el;
  while(cin >> el){
    mapa.PB(el);
  }
  filas = mapa.size();
  columnas = mapa[0].size();
  int sol = 0;
  for (int i = 0; i<mapa.size(); i++){
    for (int j = 0; j<mapa[i].size(); j++){
        cout << i << " " << j << endl;
        if (mapa[i][j] == '0'){
            cout << "Entra" << endl;
            recorre(i, j);
            sol += nueves.size();
            nueves.clear();
        }
    }
  }
  cout << sol << endl;
  
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr); 
  solve();
  return 0;
}