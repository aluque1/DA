
# Arboles AVL

Son arboles de busqueda binarios con una codicion de equilibrio: Todos los nodos del arbol cumples que la diferencia de alturas de sus 2 hijos es como mucho 1. Por esto la altura de una arbol AVL con N nodos esta en O(log N).

## Autoequilibrado

La insecion o borrado de un nodo puede provocar que deje de cumplirse la condicion de equilibrio.

### Rotaciones simples

![desequilibrio al insertar por la izquierda](imagenes/avl/arbol1_desequilibrado.png)

En este caso podemos ver como la insercion de un 6 provocaria un desequilibrio en el nodo α ya que tendria una altura de 0 en el nodo derecho y 2 en el nodo izquierdo. Al tener un desequilibrio en el hijo izquierdo vamos solucionar este problema se emplea una rotacion simple a la derecha entonces nos quedariamos con el siguiente arbol

![rotacion simple a la derecha](imagenes/avl/rotacion_simple_derecha.png){: style="width: 49%"} ![arbol rotado derecha](imagenes/avl/arbol1_rotado.png){: style="width: 49%"}

En el caso que ocurra al insertar y que se desiquilibre el arbol a la derecha como en la siguiente imagen tendremos que solucionar haciendo una rotacion simple a la izquierda.

![desequilibrio al insertar por la derecha](imagenes/avl/arbol2_desequilibrado.png)

Como se ha comentado mas arriba ahora se ha desequilibrado por la derecha el nodo α. La rotacion a la izquierda seria de la siguiente manera:

![rotacion simple a la izquierda](imagenes/avl/rotacion_simple_izquierda.png){: style="width: 49%"} ![arbol rotado izquierda](imagenes/avl/arbol2_rotado.png){: style="width: 49%"}

### Rotaciones dobles

#### Rotacion doble izquierda-derecha

Hay casos en que las rotaciones simples no son suficientes, por ejemplo si tenemos el siguiente arbol y queremos insertar un 7 vemos que se inserta en el hijo derecho del nodo 6.

![desequilibrio del arbol 3](imagenes/avl/arbol3_desequilibrado.png)

Rotamos para la izquierda y despues para la derecha => dejamos un arbol parecido al arbol que teniamos con el desequilibrio por rotacion por la izquierda.

Despues de esto rotamos para la derecha para que el arbol acabe de manera equilibrada

![rotamos a la izquierda](imagenes/avl/arbol3_rot1.png){: style="width: 49%"} ![rotamos a la derecha](imagenes/avl/arbol3_rot2.png){: style="width: 49%"}

#### Rotacion doble derecha-izquierda

En el siguiente caso queremos insertar el 8 en el hijo derecho del nodo 9

![desequilibrio del arbol 4](imagenes/avl/arbol4_desequilibrado.png)
Rotamos para la izquierda y despues para la derecha => dejamos un arbol parecido al arbol que teniamos con el desequilibrio por rotacion por la izquierda.

Despues de esto rotamos para la derecha para que el arbol acabe de manera equilibrada

![rotamos a la izquierda](imagenes/avl/arbol4_rot1.png){: style="width: 49%"} ![rotamos a la derecha](imagenes/avl/arbol4_rot2.png){: style="width: 49%"}
