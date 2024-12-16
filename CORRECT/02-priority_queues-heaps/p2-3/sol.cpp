/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas DA43
 *
 *@ </answer> */

#include <fstream>
#include <iostream>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

struct t_cash_reg{
  int time;
  int num;
};

// own comparator if caja1 is "smaller than" caja2
bool operator<(const t_cash_reg &cash_reg1, const t_cash_reg &cash_reg2) {
  return cash_reg1.time < cash_reg2.time || (cash_reg2.time == cash_reg1.time && cash_reg1.num < cash_reg2.num);
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
  int num_cash_reg, num_clients;
  cin >> num_cash_reg >> num_clients;
  if (num_cash_reg == 0 && num_clients == 0) return false;

  PriorityQueue<t_cash_reg> cash_reg;

  for(int i = 0; i < num_cash_reg; ++i)
    cash_reg.push({0, i + 1}); // Ponemos i + 1 porque las cajas van de 1 a num_cash_registers

  for(int i = 0; i < num_clients; ++i){
    int secs;
    cin >> secs;
    t_cash_reg free = cash_reg.top(); // La caja que se queda libre es la que va primera (la que tiene menor tiempo) 
    cash_reg.pop();
    free.time += secs;  
    cash_reg.push(free);
  }

  cout << cash_reg.top().num << '\n';
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
