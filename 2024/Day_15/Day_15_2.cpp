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

void Imprime_set(unordered_set<int> s) {
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

void Imprime_vs(vector<string> vect){
  for (int i = 0; i<vect.size(); i++){
    cout << vect[i] << endl;
  }
}

unordered_set<int> pos_movimiento = {};
int edge_value = 100;

bool move(int direccion, int pos1, int pos2, vector<string>& mapa){
  int pos_f1 = direccion+pos1;
  int pos_f2 = direccion+pos2;
  bool posible = true;
  if (mapa[pos_f1/edge_value][pos_f1%edge_value] == '#' || mapa[pos_f2/edge_value][pos_f2%edge_value] == '#'){
    return false;
  }
  if (mapa[pos_f1/edge_value][pos_f1%edge_value] == ']' && direccion != 1){
    posible = move(direccion, pos_f1-1, pos_f1, mapa) & posible;
  }
  if (mapa[pos_f1/edge_value][pos_f1%edge_value] == '[' && direccion != -1){
    posible = move(direccion, pos_f1, pos_f1+1, mapa) & posible;
  }
   if (mapa[pos_f2/edge_value][pos_f2%edge_value] == ']' && direccion != 1){
    posible = move(direccion, pos_f2-1, pos_f2, mapa) & posible;
  }
  if (mapa[pos_f2/edge_value][pos_f2%edge_value] == '[' && direccion != -1){
    posible = move(direccion, pos_f2, pos_f2+1, mapa) & posible;
  }
  if ((mapa[pos_f1/edge_value][pos_f1%edge_value] == '.' && mapa[pos_f2/edge_value][pos_f2%edge_value] == '.') || posible){
    pos_movimiento.insert(pos1);
    pos_movimiento.insert(pos2);
    return true;
  }
  return posible;
}

vi locate(char obj, vector<string>& mapa){
  vi sol;
  for (int i = 0; i<mapa.size(); i++){
    for (int j = 0; j<mapa[i].size(); j++){
      if (mapa[i][j] == obj){
        sol.PB(i*edge_value+j);
      }
    }
  }
  return sol;
}

vector<string> transforma(vector<string> mapa){
  vector<string> sol;
  for (int i = 0; i<mapa.size(); i++){
    sol.PB("");
    for (int j = 0; j<mapa[i].size(); j++){
      if (mapa[i][j] == '#'){
        sol[i]+="##";
      } else if (mapa[i][j] == 'O'){
        sol[i]+="[]";
      } else if (mapa[i][j] == '.'){
        sol[i]+="..";
      } else {
        sol[i]+="@.";
      }
    }
  }
  return sol;
}

void reset(vector<string>& mapa){
  for (auto it = pos_movimiento.begin(); it!=pos_movimiento.end(); it++){
    mapa[(*it)/edge_value][(*it)%edge_value] = '.';
  }
}

int solve() {
  // Code aquí
  vector<string> mapa;
  string instrucciones = "";
  string el;

  while(cin >> el){
    if (el[0] != '#'){
      instrucciones += el;
    } else {
      mapa.PB(el);
    }
  }
  mapa = transforma(mapa);
  vector<string> mapa_copy;
  copia(mapa, mapa_copy)
  /*Imprime_vs(mapa);
  cout << endl;*/
  int pos_robot = locate('@', mapa)[0];
  bool movimiento;
  map<char, int> indice = {{'^',edge_value*(-1)}, {'v',edge_value}, {'<',-1}, {'>',1}};
  for (int i = 0; i<instrucciones.size(); i++){
    pos_movimiento.clear();
    movimiento = move(indice[instrucciones[i]], pos_robot, pos_robot, mapa);
    if (movimiento){
      pos_robot = pos_robot+indice[instrucciones[i]];
      reset(mapa);
      for (auto it = pos_movimiento.begin(); it!=pos_movimiento.end(); it++){
        mapa[((*it)+indice[instrucciones[i]])/edge_value][((*it)+indice[instrucciones[i]])%edge_value] = mapa_copy[(*it)/edge_value][(*it)%edge_value];
      }
    }
    mapa_copy.clear();
    copia(mapa, mapa_copy);
    /*cout << instrucciones[i] << " " << movimiento << endl;
    Imprime_vs(mapa);
    cout << endl;*/
  }
  vi cajas = locate('[', mapa);
  int sol = 0;
  for (int i = 0; i<cajas.size(); i++){
    sol += cajas[i];
    if (sol<0){
      cout << "###overflow###" << endl;
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