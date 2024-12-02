/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 * Este ejercicio va a ser resuelto con la STL
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

struct t_event {
  int pacient_id;  // Will be used if there is the same severity for two
                   // different patients
  string name;
  int severity;
};

struct comp_t_event {
  bool operator()(t_event const& event1, t_event const& event2) {
    return event1.severity < event2.severity || // will make a max_heap of severity
           (event1.severity == event2.severity &&
            event1.pacient_id > event2.pacient_id); // but a min_heap of id
  }
};

bool resuelveCaso() {
  int num_eventos;  // Number of events we are going to work with
  char event_type;  // To know what we have to do next
  int i = 0;        // Going to be used to asign an id to each pacient
  
  priority_queue<t_event, vector<t_event>, comp_t_event> pq; // Priority queue using the priority established by the comp_t_event struct
  int severity;
  string name;

  cin >> num_eventos;
  
  if (num_eventos == 0) return false;

  while (num_eventos--) {
    cin >> event_type;
    if (event_type == 'I') {
      cin >> name >> severity;
      pq.push({i, name, severity});
    } else {
      cout << pq.top().name << '\n';
      pq.pop();
    }
    ++i;
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
  system("PAUSE");
#endif
  return 0;
}
