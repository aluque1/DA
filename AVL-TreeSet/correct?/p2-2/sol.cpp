/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

struct t_usr {
  int id;      // User ID
  int period;  // Period
  int time;    // Current time
};

// own comparator if usr2 is "smaller than" user 2
bool operator<(const t_usr &usr1, const t_usr &usr2) {
  return usr2.time > usr1.time || (usr2.time == usr1.time && usr2.id > usr1.id);
}

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
  int num_usrs;
  cin >> num_usrs;
  if (num_usrs == 0) return false;

  int usr_id;
  int period;
  int time;
  PriorityQueue<t_usr> pq;
  for (int i = 0; i < num_usrs; ++i) {
    cin >> usr_id >> period;
    pq.push({usr_id, period, period});
  }

  int intervals;
  cin >> intervals;
  // resolver el caso posiblemente llamando a otras funciones
  while (intervals--) {
    auto curr = pq.top();
    pq.pop();
    cout << curr.id << '\n';
    curr.time += curr.period;
    pq.push(curr);
  }
  cout << "---\n";
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
