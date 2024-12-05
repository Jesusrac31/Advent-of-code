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

void Imprime(vector<string> vect) {
  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i] << endl;
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

int busca(int filas, int columnas, vector<string> d_1, vector<string> d_2, string el){
    string el_rev;
    copia(el, el_rev);
    reverse(el_rev.begin(), el_rev.end());
    vector<pii> posiciones, posiciones_verified;
    pii el_pair;
    for (int i = 0; i<d_1.size(); i++){
        for (int j = el.size()-1; j<d_1[i].size(); j++){
            if(d_1[i].substr(j-el.size()+1, el.size()) == el || d_1[i].substr(j-el.size()+1, el.size()) == el_rev){
                el_pair.first = 2*(j-1)+abs(i-filas+1)-filas+1;
                cout << el_pair.first << endl;
                el_pair.second = (filas-1-(i-filas+1)-abs(el_pair.first))/2;
                cout << i << " " << j-1 << endl;
                el_pair.first+=filas-1;
                posiciones.PB(el_pair);
            }
        }
    }
    for (int i = 0; i<posiciones.size(); i++){
        if (d_2[posiciones[i].first].substr(posiciones[i].second-1, el.size()) == el || d_2[posiciones[i].first].substr(posiciones[i].second-1, el.size()) == el_rev){
            posiciones_verified.PB(posiciones[i])
        }
        cout << posiciones[i].first << " " << posiciones[i].second << " " << d_2[posiciones[i].first][posiciones[i].second]<< endl;
    }

    return posiciones_verified.size();
}

int solve() {
  // Code aquí
  vector<string> data_h;
  string el;
  int sol = 0;
  while( cin>> el){
    data_h.PB(el);
  }
  int filas, columnas;
  filas = data_h.size();
  columnas = data_h[0].size();
  vector<string> data_d;
  int off_f, off_c;
  off_f = 0;
  off_c = columnas;
  for (int i = 0; i<filas+columnas-1; i++){
    data_d.PB("");
    
    if (off_c>0){
        off_c--;
    } else {   
        off_f++;
    }

    for (int j=0; j+off_f<filas && j+off_c<columnas; j++){
        data_d[i]+=data_h[j+off_f][j+off_c];
    }
  }

  vector<string> data_d_2;
  off_f = 0;
  off_c = -1;
  for (int i = 0; i<filas+columnas-1; i++){
    data_d_2.PB("");
    
    if (off_c<columnas-1){
        off_c++;
    } else {   
        off_f++;
    }
    for (int j=0; j+off_f<filas && off_c-j>=0; j++){
        data_d_2[i]+=data_h[j+off_f][off_c-j];
    }
  }
  reverse(data_d.begin(), data_d.end());
  Imprime(data_h);
  Imprime(data_d);
  Imprime(data_d_2);
  sol += busca(filas, columnas, data_d, data_d_2,"MAS");

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
