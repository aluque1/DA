
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

#include "peaje.h"
#include "graph.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{

  // leer los datos de la entrada
  int numVert, numAr, vertAlex, vertLucas, vertTrabajo;

  cin >> numVert >> numAr >> vertAlex >> vertLucas >> vertTrabajo;

  if (!std::cin) // fin de la entrada
    return false;

  // resolver el caso posiblemente llamando a otras funciones
  Grafo g(numVert);

  for (int i = 0; i < numAr; i++)
  {
    int v, w;
    cin >> v >> w;
    g.ponArista(v, w);
  }

  Peaje peajeAlex(g, vertAlex);
  Peaje peajeLucas(g, vertLucas);
  Peaje peajeTrabajo(g, vertTrabajo);

  int minDist = INT_MAX;

  for(int i = 0; i < numVert; ++i){
    int totalDist = peajeAlex.distancia(i) + peajeLucas.distancia(i) + peajeTrabajo.distancia(i);
    minDist = min(minDist, totalDist);
  }
  
  // escribir la solución

  cout << minDist << '\n'; 

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
