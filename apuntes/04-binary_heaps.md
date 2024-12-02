# Binary heaps

Antes de ver que es un monticulo binario tenemos que ver que son los arboles completos y semicompletos.

## Arboles completos y semicompletos

Un arbol binario de altura h es completo cuando todos sus nodos internos tienes 2 hijos no vacios, y todas sus hojas estan en el nivel h.

Un arbol binario de altura h es semicompleto bien si es completo o bien tiene vacantes una serie de posiciones consecutivas del nivel h empezando por la izquierda

### Propiedades

- Un arbin completo de altura h >= 1 tiene 2^{i-1} nodos en el nivel i, ∀ i : 1 <= i <= h
- Un arbin completo de altura h >= 1 tiene 2^{i-1} hojas
- Un arbin completo de altura h >= 0 tiene 2^{h} - 1 nodos
- La altura de un arbin semicompleto formado por n nodos es ⌊log n⌋ + 1

## Monticulos binarios

Un monticulo binario de minimos es un arbol binario semicompleto donde el elemento de la raiz <= que todos los elems del hijo dr y del hijo iz y a su vez los hijos derecho e izquierdo son monticulos binarios de minimos

Un monticulo binario de maximos es lo mismo pero el elemento de la raiz es >= y los hijos derecho e izquierdo son a su vez monticulos de maximos
