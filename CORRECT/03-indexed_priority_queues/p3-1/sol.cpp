/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>
#include <queue>

#include "PriorityQueue.h"

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

void colocar_pajaros(PriorityQueue<int, greater<int>> &left,
                     PriorityQueue<int> &right, int age1, int age2) {
  int first = right.top();
  int aux;
  // Los 2 nuevos tienen menos edad que el que va primero
  if (age1 < first && age2 < first) {
    left.push(age1);
    left.push(age2);
    // hay mas pajaros a la iz que a la dr => reequilibramos
    aux = left.top();
    left.pop();
    right.push(aux);
  }
  else if (age1 > first && age2 > first) {
    right.push(age1);
    right.push(age2);
    // hay mas pajaros a la iz que a la dr => reequilibramos
    aux = right.top();
    right.pop();
    left.push(aux);
  }
  // El primer pajaro es mas joven y el segundo mas viejo
  else if (age1 < first && age2 > first) {
    left.push(age1);
    right.push(age2);
  }
  // El primer pajaro es mas viejo y el segundo mas joven
  else if (age1 > first && age2 < first) {
    right.push(age1);
    left.push(age2);
  }
}

bool resuelveCaso() {
  // leer los datos de la entrada
  int first_age, num_pairs;
  cin >> first_age >> num_pairs;
  if (first_age == 0 && num_pairs == 0) return false;

  PriorityQueue<int, greater<int>> left;  // pajaros mas jovenes
  // El top de este heap contendra nuestra mitad
  PriorityQueue<int> right;  // pajaros mas viejos
  right.push(first_age);

  int age1, age2;
  for (int i = 0; i < num_pairs; ++i) {
    cin >> age1 >> age2;
    colocar_pajaros(left, right, age1, age2);
    cout << right.top() << ' ';
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
