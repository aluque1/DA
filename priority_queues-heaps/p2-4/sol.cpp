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
};

// own comparator if count1 is "greater than" count2
bool operator<(const t_count &count1, const t_count &count2) {
  float coeff1 = float(count1.votes) / (1 + count1.seats); 
  float coeff2 = float(count2.votes) / (1 + count2.seats); 
      
  return coeff1 > coeff2 || 
         (count2.seats == count1.seats && count1.votes > count2.votes) || 
         (count2.seats == count1.seats && count2.votes == count1.votes && count1.id_candidacy < count2.id_candidacy);
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
    count.push({i, votes, 0});
  }

  if(count.empty()){ // Si la cola es vacia
    cout << '\n';
    return true;
  }
    
  while(num_seats--)
  {
    t_count temp = count.top();
    count.pop();
    temp.seats += 1;
    count.push(temp);
  }

  // vector auxiliar para imprimir en orden de ID
  vector<int> sol(num_candidacy);
  for(int i = 0; i < num_candidacy; ++i){
    t_count aux = count.top();
    count.pop();
    sol[aux.id_candidacy] = aux.seats;
  }

  for(int i = 0; i < sol.size(); ++i)
    cout << sol[i] << ' ';
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
