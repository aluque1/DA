# Priority queues

La diferencia principal con las colas "al uso" es que no se sigue un orden FIFO, se atiende segun la prioridad que le demos a los elementos. Cada elemento tiene una prioridad que determina quien va a ser el primero en ser atendido. Hace fatla un **orden total** entre los elementos.

En una cola de prioridad de minimos se atiende primero los elementos de menor valor. Ocurre viceversa con las colas de prioridad de maximos

El TAD de las colas de prioridad cuenta con las siguientes operaciones:

``` c++
 void push(T const& e) // Inserta un elemento : O(log N) Ya que se usan monticulo binarios para codificar las colas de prioridad
 T const& top() const // Consultar el elemento mas prioritario : O(1)
 void pop() // Eliminar el primer elemento : O(log N)
 bool empty() const // Determinar si la cola de prioridad es vacia : O(1)
 int size() const // Consultar el numero de elementos de la cola : O(1)
```

## Priority queues en la STL de C++

La libreria queue de la STL contiene la clase priority_queue que implementa colas de prioridad de maximos -> cuando hacemos top() nos va a devolver el mayor elemento. La inicializacion por defecto de la STL es la siguiente:

``` c++
 std::priority_queue pq;
 // ≡
 std::priority_queue<int, std::vector<int>, std::less<int>> pq;

 /* 
    std::priority_queue<1, 2, 3>
    
    1. the type the queue is going to be composed of
    2. the underlying container that the priority queue will use for the elements
    3. the comparator that is going to be used to mantain the order
 */

```

Si queremos hacer una cola de minimos con la STL deberiamos hacer lo siguiente : 

``` c++
 std::priority_queue<int, std::vector<int>, std::greater<int>>
```

Si queremos crear nuestra propio orden podemos hacer lo siguiente (seguimos usando la STL para esto)

``` c++
 struct registro {
    int momento; // Cuando le toca
    int id; // identificador (se usa en caso de empate)
    int periodo; // tiempo entre consultas
 };

 struct comp_registro{
    bool operator()(registro const& a, registro const& b) {
        return b.momento < a.momento ||
               (a.momento == b.momento && b.id < a.id);
    }
 };

 // vamos a tener una cola de prioridad de structs de tipo registro
 std::priority_queue<registro, std::vector<registro>, comp_registro>
```
