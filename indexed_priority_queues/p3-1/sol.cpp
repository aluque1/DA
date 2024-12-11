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

bool resuelveCaso() {
  // leer los datos de la entrada
  int first_age, num_pairs;
  cin >> first_age >> num_pairs;
  if (first_age == 0 && num_pairs == 0) return false;

  priority_queue<int> pq_younger;
  // El top de este heap contendra nuestra mitad
  priority_queue<int, vector<int>, greater<int>> pq_older;

  pq_older.push(first_age);

  int age;
  for (int i = 0; i < 2 * num_pairs; ++i) {
    cin >> age;
    if (age < first_age) {
      pq_younger.push(age);
      // rebalanceamos si hay demasiados en menores
      if (pq_younger.size() - pq_older.size() > 0) {
        pq_older.push(first_age);
        first_age = pq_younger.top();
        pq_younger.pop();
      }
    } else {
      pq_older.push(age);
      // rebalanceamos si hay demasiados en mayores siempre va a haber uno mas
      // que en menores
      if (pq_older.size() - pq_younger.size() > 1) {
        pq_younger.push(first_age);
        first_age = pq_older.top();
        pq_older.pop();
      }
    }
    if (i % 2 == 1) cout << first_age << ' ';
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
