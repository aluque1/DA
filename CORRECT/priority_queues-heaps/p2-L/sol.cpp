/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>
#include <queue>

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

struct t_job {
  int time_start;
  int time_end;
  int periodic;  // -1 means it is not periodic
};

struct comp_t_job {
  bool operator()(t_job const& job1, t_job const& job2) {
    return job1.time_start >
           job2.time_start;  // will make a min_heap of time_start
  }
};

bool resuelveCaso() {
  // leer los datos de la entrada
  int unique, periodic, time;
  cin >> unique >> periodic >> time;
  if (!std::cin)  // fin de la entrada
    return false;

  bool conflict = false;

  priority_queue<t_job, vector<t_job>, comp_t_job> pq;

  int time_start, time_end;
  while (unique--) {
    cin >> time_start >> time_end;
    pq.push({time_start, time_end, -1});
  }

  int time_periodic;
  while (periodic--) {
    cin >> time_start >> time_end >> time_periodic;
    pq.push({time_start, time_end, time_periodic});
  }

  int final_time = 0;

  while (pq.size() > 1 && !conflict && final_time < time) {
    t_job temp1 = pq.top();
    pq.pop();
    t_job temp2 = pq.top();

    if (temp1.time_end > time) temp1.time_end = time;

    final_time = temp1.time_end;
    if (temp1.time_end > temp2.time_start) conflict = true;

    if (temp1.periodic != -1)
      pq.push({temp1.time_start + temp1.periodic, temp1.time_end + temp1.periodic, temp1.periodic});
  }

  conflict ? cout << "SI\n" : cout << "NO\n";
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
