
/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Luque Villegas
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "PriorityQueue.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void resolver(PriorityQueue<int, greater<int>> iz, PriorityQueue<int> dr, int p1, int p2){
  int primero = dr.top(); // cogemos el pajaro que va primero
  int aux;                // variable auxiliar para mover elementos

  if(p1 < primero && p2 < primero){
    // Los 2 pajaros son mas jovenes que el primero entonces los ponemos a la iz
    iz.push(p1);
    iz.push(p2);
    // reequilibramos ya que tenemos mas pajaros en iz que dr
    aux = iz.top();
    iz.pop();
    dr.push(aux);
  } else if(p1 > primero && p2 > primero){
    // Los 2 pajaros son mayores que el primero entonces los ponemos a la dr
    dr.push(p1);
    dr.push(p2);
    // reequilibramos ya que tenemos mas pajaros en dr que en iz
    aux = dr.top();
    dr.pop();
    iz.push(aux);
  } else if(p1 < primero && p2 > primero){
    // p1 es menor que el primero => colocamos iz. p2 > primero => colocamos dr
    iz.push(p1);
    dr.push(p2);
  } else {
    dr.push(p1);
    iz.push(p2);
  }
}

bool resuelveCaso()
{

  // leer los datos de la entrada
  int primero, numParejas;

  cin >> primero >> numParejas;
  if (primero == 0 && numParejas == 0)
    return false;

  // resolver el caso posiblemente llamando a otras funciones
  int p1, p2;                          // variables para almacenar
  PriorityQueue<int, greater<int>> iz; // Cola para guardar pajaros a la iz del primero
  PriorityQueue<int> dr;               // Cola para guardar pajaros a la dr y el primero
  dr.push(primero);                    // Metemos primero, como ord de menor a mayor primero elem será el primer pajaro
  for(int i = 0; i< numParejas; ++i){
    cin >> p1 >> p2;
    resolver(iz, dr, p1, p2);
    cout << dr.top() << " ";  
  }
  cout << '\n';
  

  return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (resuelveCaso())
    ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // system("PAUSE");
#endif
  return 0;
}
