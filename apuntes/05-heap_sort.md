# Heap Sort

Es un metodo de ordenacion que usa un monticulo (heap)

## Heap sort abstracto

Se utiliza una cola de prioridad en vez de un monticulo:

``` c++
 template <typename T>
 void heapsort_abstracto(vector<T> & v){
    PriorityQueue<T> colap;
    for(auto const& e : v) // recorremos el vector metiendolo en la cola de prio
        colap.push(e);
    for(int i = 0; i < v.size; ++i){ // vamos insertando en el vector segun el orden total establecido en el heap sort
        v[i] = colap.top();
        colap.pop();
 }

 /*
    El primer for es O(N log N) ya que push tiene complejidad log N y se hace N veces donde N es el tamaño del vector.
    El segundo for tambien es O(N log N) ya que pop() tambien es log N y el tamaño de la cola va disminuyendo de N a 0. 
    Tambien tiene un coste en espacio adicional ya que usamos una cola de prioridad que tiene coste O(N) en espacio.
*/
```

Nos podriamos ahorrar el coste adicional en espacio si utilizamos el mismo vector para representar el monticulo aux.

1. Primero convertimos el vector en un monticulo.
2. Despues vamos extrayendo sucesivamente el elemento mas prio para colocarlo al final. Vamos haciendo como si esa seccion final que ya esta ordenada "no existe".
