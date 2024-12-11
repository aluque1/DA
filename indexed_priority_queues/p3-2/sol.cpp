/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>
#include <queue>

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

  int flight_hours = 0;
  while(!nine_V.empty() && !one_five_V.empty()){
    int nine_elem_temp = nine_V.top().elem;
    int nine_prio_temp = nine_V.top().prioridad;
    int one_elem_temp = one_five_V.top().elem;
    int one_prio_temp = one_five_V.top().prioridad;
    
    if(one_prio_temp < nine_prio_temp){
      flight_hours += one_prio_temp;
      nine_V.update(nine_elem_temp, nine_prio_temp - one_prio_temp);
      one_five_V.pop();
    }
    else{
      flight_hours += nine_prio_temp;
      one_five_V.update(one_elem_temp, one_prio_temp - nine_prio_temp);
      nine_V.pop();
    }
  }

  cout << flight_hours << '\n';

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
