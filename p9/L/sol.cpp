
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"          // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"    // propios o los de las estructuras de datos de clase
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }

private:

    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    IndexPQ<Valor> pq;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = (dist[v] + a.valor());
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {
  // leer los datos de la entrada
  int N, M; // n : numero de puntos importantes, m : numero de Carreteras transitables en ambos sentidos
  cin >> N >> M;
  if (!std::cin) // fin de la entrada
    return false;
  // leemos y creamos el grafo con las aristas
  DigrafoValorado<int> g(N);
  for (int i = 0; i < M; ++i) {
    int v, w, valor;
    cin >> v >> w >> valor;
    g.ponArista({v - 1, w - 1, valor});
    g.ponArista({w - 1, v - 1, valor});
  }

  // norte : 0 (1); sur n - 1 (N) : 
  Dijkstra<int> solNorte(g, 0);
  Dijkstra<int> solSur(g, N - 1);

  PriorityQueue<int> q;
  
  for(int i = 1; i < N - 2; ++i){
    // si es positivo el sur esta mas cerca, el sur esta mas cerca
    int diferencia = solNorte.distancia(i) - solSur.distancia(i);
    q.push(diferencia);
  }   
  
  // escribir la solución

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

  while (resuelveCaso())
    ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
