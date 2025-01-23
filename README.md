Benjamin Vega 21648877-6
# Algoritmo de Dijkstra para Encontrar Caminos Mínimos

El codigo implementa el algoritmo de Dijkstra para encontrar el camino más corto desde un nodo de origen (en este caso, el nodo 'A') hasta cualquier nodo destino en un grafo dirigido y ponderado. El programa lee una matriz de adyacencia desde un archivo de texto, que representa el grafo, y permite al usuario seleccionar nodos destino para calcular el camino más corto y la distancia total.


#¿Qué es el algoritmo de Dijkstra?
El algoritmo de Dijkstra es una técnica utilizada para resolver el problema del camino más corto en un grafo con pesos no negativos. Funciona explorando los nodos de manera iterativa, siempre seleccionando el nodo con la menor distancia acumulada desde el origen y actualizando las distancias de sus nodos vecinos.

Pasos básicos del algoritmo:

Inicializar las distancias de todos los nodos como "infinito" (INT_MAX), excepto el nodo origen, que se inicializa con 0.
Usar una lista de nodos visitados para evitar recalcular caminos ya procesados.
Iterar sobre los nodos no visitados y actualizar las distancias de los nodos adyacentes si se encuentra un camino más corto.
Repetir hasta que todos los nodos hayan sido procesados o hasta que se alcance el nodo destino.

#Runear el codigo
Compilar el codigo utilizando el siguiente comando en la terminal: g++ nombreDelArchivo.cpp -o nombreX \n
(*) Comppilar con modo depuracion (opcional)(util para debugging): g++ nombreDelArchivo.cpp -o nombreX -g
Para runear una vez compilado: ./nombreX






Hacer un dijkstra del camino más corto para la segunda prueba.

va a tener un txt con un archivo de texto con la anchura y altura de la matriz de n x n. Esa s la matriz de adyacencia.
La matriz tiene pesos.Va a pedir haste que nodo se quiere llegar. En la matriz, el nodo que está en el 0,0 va a ser el inicio según el profe. 
También va a ver una lista de todos los nodos que existen.  

- La impresión tiene que ser por el árbol. 

- Se debe imprimir como letras según los números. 

- Debe tener prevención de errores.

- Es un árbol dirigido.

Termina cuando dice "el camino más corto desde A a (nodo), es (distancia)."

- Debe funcionar en codespace.

El txt:

- primera linea = n: cant de nodos
- siguientes líneas : la matriz

Los saltos de línea van a estar dados por un enter

Github -> proyecto nuevo -> codespace.

- Generar el readme altiro cuando nuevo proyecto

- Boton verde de code y abrir codespace.

- Hay que eviarle el repositorio al profe.

- Si un nodo no tiene camino, el camino mas corto va a ser 0.

- Si un nodo se instancia a sí mismo y ese camino tiene peso, eso debería retornar 0.

Se puede hacer:

Se envía el repositorio por github.
