#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <climits>
#include <string>

using namespace std;

class Grafo {
private:
    vector<vector<int>> matrizAdyacencia;

    int menorDistancia(vector<int>& distancias, vector<bool>& visitados) {
        int menor = INT_MAX;
        int menorIndex = -1;

        for (int i = 0; i < distancias.size(); ++i) {
            if (!visitados[i] && distancias[i] <= menor) {
                menor = distancias[i];
                menorIndex = i;
            }
        }
        return menorIndex;
    }

public:
    // Constructor para cargar el grafo desde un archivo
    Grafo(const string& archivo) {
        ifstream arch(archivo);
        string linea;

        if (getline(arch, linea)) {
            int n = stoi(linea);

            while (getline(arch, linea)) {
                vector<int> fila;
                stringstream ss(linea);

                string valor;
                while (getline(ss, valor, ' ')) {
                    fila.push_back(stoi(valor));
                }
                matrizAdyacencia.push_back(fila);
            }
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }

    // Método deel algoritmo de Dijkstra
    pair<vector<int>, int> dijkstra(int destino) {
        int n = matrizAdyacencia.size();

        vector<int> caminosPrevios(n, -1); // Vector para reconstruir el camino
        vector<bool> visitados(n, false);
        vector<int> distancias(n, INT_MAX);

        distancias[0] = 0; // Nodo origen ('A')

        for (int i = 0; i < n - 1; ++i) {
            int u = menorDistancia(distancias, visitados);
            if (u == -1) break; // Si no hay mas nodos accesibles

            visitados[u] = true;

            if (u == destino) break; // Si llegamos al nodo destino

            for (int k = 0; k < n; ++k) {
                if (!visitados[k] && matrizAdyacencia[u][k] && distancias[u] != INT_MAX && distancias[u] + matrizAdyacencia[u][k] < distancias[k]) {
                    distancias[k] = distancias[u] + matrizAdyacencia[u][k];
                    caminosPrevios[k] = u;
                }
            }
        }

        if (distancias[destino] == INT_MAX) return {{}, -1};

           vector<int> caminosTomados;
    // chantar caminos recorridos
    for (int actual = destino; actual != -1; actual = caminosPrevios[actual])
    {
        caminosTomados.push_back(actual);
    }

    // ordenar el vector camino
    vector<int> caminoOrdenado(caminosTomados.size());
    for (int i = 0; i < caminosTomados.size(); ++i)
    {
        caminoOrdenado[caminosTomados.size() - 1 - i] = caminosTomados[i];
    }
    //retornar vector camino y distancia recorrida
    return {caminoOrdenado, distancias[destino]};
    }

    // Método para buscar nodos interactuando con el usuario
    void buscarNodos() {
        int n = matrizAdyacencia.size();
        char nodoDestino;
        string entrada;
        int continuar;

        do {
            cout << "Ingrese nodo destino (A -> " << char('A' + n - 1) << ") EN MAYUSCULA: ";
            cin >> nodoDestino;

            int destino = nodoDestino - 'A';
            if (destino < 0 || destino >= n) {
                cout << "Nodo invalido o no encontrado." << endl;
                continue;
            }

            auto [camino, distancia] = dijkstra(destino);

            if (distancia == -1) {
                cout << "No hay un camino hacia el nodo " << nodoDestino << endl;
            } else {
                cout << "Camino: ";
                for (int nodo : camino) {
                    cout << char('A' + nodo) << " -> ";
                }
                cout << "Fin" << endl;
                cout << "Distancia total: " << distancia << endl;
            }

            do {
                cout << "\nDesea buscar otro nodo? (1 = Si, 0 = No): ";
                cin >> entrada;

                try {
                    continuar = stoi(entrada);
                    if (continuar != 1 && continuar != 0) {
                        cout << "Entrada invalida. Ingrese 1 para Si o 0 para No." << endl;
                        continuar = -1;
                    }
                } catch (...) {
                    cout << "Entrada invalida. Ingrese un numero (1 para Si, 0 para No)." << endl;
                    continuar = -1;
                }
            } while (continuar != 1 && continuar != 0);

            if (continuar == 0) {
                cout << "Finalizando programa." << endl;
                break;
            }

        } while (true);
    }

    // Método para imprimir la matriz de adyacencia
    void imprimirMatriz() {
        cout << "Matriz de adyacencia del .txt:" << endl;
        for (auto fila : matrizAdyacencia) {
            for (int dato : fila) {
                cout << dato << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    string archivo = "grafo_1.txt";

    Grafo grafo(archivo);
    grafo.imprimirMatriz();
    grafo.buscarNodos();

    return 0;
}