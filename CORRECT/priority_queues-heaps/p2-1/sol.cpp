/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using lli = long long int;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {
  // leer los datos de la entrada
  int num_elems;
  cin >> num_elems;
  if (num_elems == 0) return false;

  PriorityQueue<lli> pq;
  lli elem;
  for(int i = 0; i < num_elems; ++i){
    cin >> elem;
    pq.push(elem);
  }

  // resolver el caso posiblemente llamando a otras funciones
  lli work = 0;
  lli sum = 0;
  lli a, b;

  while(pq.size() > 1){
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();

    sum = a + b;
    work += sum;

    pq.push(sum);
  }
  pq.pop();
  // escribir la solución
  cout << work << '\n';
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
  // system("PAUSE");
#endif
  return 0;
}
