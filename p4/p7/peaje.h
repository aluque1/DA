#include <vector>
#include <queue>
#include "graph.h"

using namespace std;

class Peaje
{
public:
  Peaje(Grafo const &g, int s): visit(g.V(), false), ant(g.V()), dist(g.V()), s(s){
    peaje(g);
  }

  bool hayCamino(int v) const{
    return visit[v];
  }

  int distancia(int v) const{
    return dist[v];
  }

private:
  vector<bool> visit; // Existe camino de s a v
  vector<int> ant;    // Ultimo vertice antes de llegar a v
  vector<int> dist;   // Aristas en el camino s-v más corto
  int s;              // El nodo origen

  void peaje(Grafo const &g){
    queue<int> q;

    dist[s] = 0; visit[s] = true;
    q.push(s);

    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int w : g.ady(v)){
        if(!visit[v]){
          ant[w] = v;
          dist[w] = dist[v + 1];
          visit[w] = true;
          q.push(w);
        }
      }
    }
  }
};