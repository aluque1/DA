/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

struct t_count{
  int id_candidacy; // an id to know which one came first, 0..num_candidacy - 1 
  int votes;
  int seats;
  int coeff;        // coeff = votes / (1 + seats)
};

// own comparator if caja1 is "smaller than" caja2
bool operator<(const t_count &count1, const t_count &count2) {
  return count2.coeff < count1.coeff || 
         (count2.seats == count1.seats && count2.votes < count1.votes) || 
         (count2.seats == count1.seats && count2.votes == count1.votes && count2.id_candidacy < count1.id_candidacy);
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
  int num_candidacy, num_seats;
  cin >> num_candidacy >> num_seats;
  if (num_candidacy == 0 && num_seats == 0) return false;

  PriorityQueue<t_count> count;
  
  for(int i = 0; i < num_candidacy; ++i){
    int votes;
    cin >> votes;
    count.push({i + 1, votes, 0, (votes / 1)});
  }
    
  for (int i = 0; i < num_seats; ++i)
  {
    t_count temp = count.top();
    count.pop();
    ++temp.seats;
    temp.coeff = temp.votes / (1 + temp.seats);
    count.push(temp);
  }
  
  
  while(count.size()){ /* Asi no se imprime bien */
    cout << count.top().seats << ' ';
    count.pop();
  }
  
  cout <<'\n';
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
