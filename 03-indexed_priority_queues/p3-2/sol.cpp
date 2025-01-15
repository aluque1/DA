/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>

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

bool resuelveCaso() {
  // leer los datos de la entrada
  int num_drones, num_9V, num_1_5V;
  cin >> num_drones >> num_9V >> num_1_5V;
  if (!std::cin)  // fin de la entrada
    return false;

  IndexPQ<int, greater<int>> nine_V(num_9V);
  IndexPQ<int, greater<int>> one_five_V(num_1_5V);
  int value;
  for (int i = 0; i < num_9V; ++i) {
    cin >> value;
    nine_V.push(i, value);
  }
  for (int i = 0; i < num_1_5V; ++i) {
    cin >> value;
    one_five_V.push(i, value);
  }
  // Mientras las colas no sean vacias
  while(!nine_V.empty() && !one_five_V.empty()) {
    int flight_hours = 0;
    int i = 0;
    vector<int> bat9v, bat1v;
    // Mientras queden drones o nos quedemos sin pilas
    while(!nine_V.empty() && !one_five_V.empty() && i < num_drones){
      int nine_elem_temp = nine_V.top().elem;
      int nine_prio_temp = nine_V.top().prioridad;
      int one_elem_temp = one_five_V.top().elem;
      int one_prio_temp = one_five_V.top().prioridad;

      int minimum = min(nine_prio_temp, one_prio_temp);

      flight_hours += minimum;
      nine_prio_temp -= minimum;
      one_prio_temp -= minimum;

      // Si todavia les queda carga a las pilas, las actualizamos
      if(nine_prio_temp != 0) nine_V.update(nine_elem_temp, nine_prio_temp);
      else nine_V.pop();
      
      if(one_prio_temp != 0) one_five_V.update(one_elem_temp, one_prio_temp);
      else one_five_V.pop();
      ++i;
    }
    cout << flight_hours << ' ';
  }
  cout << '\n';

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
