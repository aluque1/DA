/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>

using namespace std;

#include "TreeSet_AVL.h"

bool resuelveCaso() {
  int num_val;
  std::cin >> num_val;
  if (num_val == 0) return false;

  Set<int> set;
  int elem;
  for (int i = 0; i < num_val; i++) {
    std::cin >> elem;
    set.insert(elem);
  }

  int queries;
  cin >> queries;
  int k_th;
  for (int i = 0; i < queries; i++) {
    cin >> k_th;
    try {
      cout << set.kesimo(k_th) << '\n';
    } catch (InvalidKException e) {
      cout << "??" << '\n';
    }
  }
  std::cout << "---" << '\n';

  return true;
}

int main() {
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (resuelveCaso());

  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}