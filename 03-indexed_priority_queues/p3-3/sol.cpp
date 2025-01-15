/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "IndexPQ.h"

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct priority {
  int mentions;  // cuantas citas ha tenido o dejado de tener
  int arrival;   // orden de llegada (queremos los mas recientes antes)

  priority operator+=(const priority other) {
    mentions += other.mentions;
    arrival = other.arrival;
    return *this;
  }

  priority operator-=(const priority other) {
    mentions -= other.mentions;
    arrival = other.arrival;
    return *this;
  }

  bool operator<(priority const& other) const {
    return mentions > other.mentions ||
           (mentions > other.mentions && arrival > other.arrival);
  }
};

bool resuelveCaso() {
  // leer los datos de la entrada
  int num_consultas;
  cin >> num_consultas;
  if (!std::cin)  // fin de la entrada
    return false;

  IndexPQ<string, less<priority>> trending(num_consultas);

  int num_max = 3;
  string command;
  string topic;
  int num_topics = 0;
  int mentions;
  for (int i = 0; i < num_consultas; ++i) {
    cin >> command;
    if (command == "C") {
      cin >> topic >> mentions;
      trending.push();
    } else if (command == "E") {
    } else {
      int j = 0;
      IndexPQ<int, greater<int>> aux(trending);
      while (j < num_max && !trending.empty()) {
        cout << j << ' ' << trending.top().elem;
        trending.pop();
        ++j;
      }
      trending = aux;
    }
  }
  // resolver el caso posiblemente llamando a otras funciones

  // escribir la solución

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
