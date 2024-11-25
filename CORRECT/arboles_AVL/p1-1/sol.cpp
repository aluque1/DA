/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>

using namespace std;

#include "bintree.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

  Escribe aquí un comentario general sobre la solución, explicando cómo
  se resuelve el problema y cuál es el coste de la solución, en función
  del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

template <typename T>
struct t_sol {
  bool avl;
  int height;
  T min_val, max_val;
};

template <typename T>
t_sol<T> is_avl(const BinTree<T> &tree) {
  if (tree.empty()) return {true, 0, T(), T()};

  t_sol<T> left = is_avl(tree.left());
  t_sol<T> right = is_avl(tree.right());
  t_sol<T> solution;

  solution.height = 1 + max(left.height, right.height);  // max height for the current node
  solution.min_val = tree.left().empty() ? 
                tree.root() : 
                left.min_val;  // by def. smaller value is going to be in the left
  solution.max_val = tree.right().empty() ? 
                tree.root() : 
                right.min_val;  // idem for bigger value

  // by def. https://en.wikipedia.org/wiki/AVL_tree
  solution.avl = left.avl && right.avl &&
               abs(left.height - right.height) < 2 &&
               (tree.left().empty() || left.max_val< tree.root()) &&
               (tree.right().empty() || right.min_val > tree.root());

  return solution;
}

bool resuelveCaso() {
  char type;
  // leer los datos de la entrada
  cin >> type;
  if (!std::cin)  // fin de la entrada
    return false;

  // resolver el caso posiblemente llamando a otras funciones
  bool sol;
  if (type == 'N') {
    BinTree<int> tree = read_tree<int>(cin);
    sol = is_avl(tree).avl;
  } else if (type == 'P') {
    BinTree<string> tree = read_tree<string>(cin);
    sol = is_avl(tree).avl;
  }
  // escribir la solución
  sol ? cout << "SI\n" : cout << "NO\n";

  return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
