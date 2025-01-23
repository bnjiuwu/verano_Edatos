Benjamin Vega 21648877-6
# Algoritmo de Dijkstra para Encontrar Caminos Mínimos

El codigo implementa el algoritmo de Dijkstra para encontrar el camino más corto desde un nodo de origen (en este caso, el nodo 'A') hasta cualquier nodo destino en un grafo dirigido y ponderado. El programa lee una matriz de adyacencia desde un archivo de texto, que representa el grafo, y permite al usuario seleccionar nodos destino para calcular el camino más corto y la distancia total.


## ¿Qué es el algoritmo de Dijkstra?
El algoritmo de Dijkstra es una técnica utilizada para resolver el problema del camino más corto en un grafo con pesos no negativos. Funciona explorando los nodos de manera iterativa, siempre seleccionando el nodo con la menor distancia acumulada desde el origen y actualizando las distancias de sus nodos vecinos.

Pasos básicos del algoritmo:

- Inicializar las distancias de todos los nodos como "infinito" (INT_MAX), excepto el nodo origen, que se inicializa con 0.
- Usar una lista de nodos visitados para evitar recalcular caminos ya procesados.
- Iterar sobre los nodos no visitados y actualizar las distancias de los nodos adyacentes si se encuentra un camino más corto.
- Repetir hasta que todos los nodos hayan sido procesados o hasta que se alcance el nodo destino.

## Runear el codigo
Compilar el codigo utilizando el siguiente comando en la terminal: g++ nombreDelArchivo.cpp -o nombreX 

(*) Comppilar con modo depuracion (opcional)(util para debugging): g++ nombreDelArchivo.cpp -o nombreX -g

Para runear una vez compilado: ./nombreX



## Archivos txt
En la carpeta output hay 6 archivos .txt con diferentes grafos. Para probarlos cambiar el nombre del archivo en la linea 195 en el main().

## Para runear el codigo con el archivo txt seleccionado.
### En codespace
- tener el archivo txt en la misma carpeta que el archivo.cpp

### en visual studio code
- tener el archivo txt en la carpeta output donde esta el ejecutable.

### Archivos.
- adyMatriz.txt
- grafo_1.txt
- grafo_2.txt
- grafo_3.txt
- grafo_4.txt
- grafo_5.txt

el archivo adyMatriz.txt se representa asi.
![adyMatriz](https://github.com/user-attachments/assets/e86a0b6e-b08c-439e-9c24-3e744626ca9d)




