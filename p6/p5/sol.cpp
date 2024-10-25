#include <iostream>
#include <fstream>

#include <PriorityQueue.h>
#include <ConjuntosDisjuntos.h>

using namespace std;

template <typename Valor>
class Tarzan
{
private:
  int max;
  bool conexo = true;

public:
  int maxCoste() const
  {
    return max;
  }

  bool esConexo() const{
    return conexo;
  }

  Tarzan(GrafoValorado<Valor> const &g) : max(0)
  {
    PriorityQueue<Arista<Valor>> pq(g.aristas());
    ConjuntosDisjuntos cjtos(g.V());
    while (!pq.empty())
    {
      auto a = pq.top();
      pq.pop();
      int v = a.uno(), w = a.otro(v);
      if (!cjtos.unidos(v, w))
      {
        cjtos.unir(v, w);
        if (coste > max)
          max = coste;
        if (cjtos.ncjtos > 1)
        { // Si hay mas de un cjto disjunto es que no es conexo
          conexo = false;
          break;
        }
      }
    }
  }
};

int main(int argc, char const *argv[])
{
 /* queda toda la lecutra de datos y demases */
 int n, m;
  return 0;
}
