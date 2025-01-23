#include <iostream>
#include <vector>

#include <sstream>
#include <fstream>

#include <string>
#include <climits>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &graf, int inicio)
{
    // variables
    int n = graf.size();
    vector<bool> visited(n, false);
    queue<int> kyu;

    // acciones
    visited[inicio] = true;
    kyu.push(inicio);
    // distancias[0] = 0;
    cout << "bfs" << endl;

    while (!kyu.empty())
    {
        int nodo = kyu.front();
        kyu.pop();
        cout << nodo << endl;
        for (int i = 0; i < n; ++i)
        {
            if (graf[nodo][i] != 0 && !visited[i])
            {
                visited[i] = true;
                kyu.push(i);
            }
        }
    }
}

int menorDistanci(vector<int> &caminos, vector<bool> &visited)
{

    int menor = INT_MAX;
    int menorIndex = -1;

    for (int i = 0; i < caminos.size(); ++i)
    {
        if (!visited[i] && caminos[i] <= menor)
        {
            menor = caminos[i];
            menorIndex = i;
        }
    }
    return menorIndex;
}

pair<vector<int>, int> dijkstra(vector<vector<int>> &graf, int desitno)
{
    int n = graf.size();

    vector<int> caminosRec(n, -1); // follow da way
    vector<bool> visited(n, false);
    vector<int> distancias(n, INT_MAX);

    distancias[0] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        // elegir nodo con la distacia menor
        int u = menorDistanci(distancias, visited);
        visited[u] = true;
        if (u == -1)
            break; // si ya se visitaron todos los nodos

        if (u == desitno)
        { // si alcanza el nodo destino
            break;
        }
        // actuaizar las distancias de los nodos adyacentes no visitaddos
        for (int k = 0; k < n; ++k)
        {
            if (!visited[k] && graf[u][k] && distancias[u] != INT_MAX && distancias[u] + graf[u][k] < distancias[k])
            {

                distancias[k] = distancias[u] + graf[u][k];

                caminosRec[k] = u;
            }
        }
    }

    if (distancias[desitno] == INT_MAX)
        return {{}, -1};

    vector<int> caminosTomados;
    // chantar caminos recorridos
    for (int actual = desitno; actual != -1; actual = caminosRec[actual])
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
    return {caminoOrdenado, distancias[desitno]};
}

void printCaminosDestino(vector<int>& caminos)
{

    cout << "Camino: ";
            for (char nodo : caminos) {
                cout << char('A' + nodo) << " -> ";
            }
            cout<<"fin"<<endl;
}

bool esNumeroValido(string& entrada) {
    // Verificar si toda la entrada son 
    for (char c : entrada) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> leerGrafoDesdeArchivo(string &nombreArchivo)
{

    vector<vector<int>> matrix;

    ifstream arch(nombreArchivo);
    string linea;

    if (getline(arch, linea))
    {
        int n = stoi(linea);

        while (getline(arch, linea))
        {
            vector<int> fila;
            stringstream ss(linea);

            string valopos;
            while (getline(ss, valopos, ' '))
            {
                fila.push_back(stoi(valopos));
            }
            matrix.push_back(fila);
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return matrix;
}

int chartoInt(char nodo)
{
    return nodo -'A';
}
void buscarNodos(vector<vector<int>> &grafo)
{
    int n = grafo.size();
    char x; // char nodo letra
    int continuar;
    string entrada;

    do
    {
        cout << "ingrese nodo destino(A -> " << char('A'+ n-1) << ") EN MAYUSCULA: ";
        cin >> x;
        int destino = chartoInt(x);
        if (destino < 0 || destino >= n)
        {
            cout<<"nodo invalio o no encontrado"<<endl;
            continue;
        }

        auto[camino,distancia] = dijkstra(grafo, destino);


        if (distancia == -1) {
            cout << "No hay un camino hacia el nodo " << x << endl;
        } else {
            printCaminosDestino(camino);
            cout<<endl;
            cout << "Distancia total: " << distancia << endl;
        }
       
       // Preguntar si desea continuar, con control de errores
        do {
            cout << "Desea buscar otro nodo? (1 = Si, 0 = No): ";
            cin >> entrada;
            if (esNumeroValido(entrada)) {
                continuar = stoi(entrada); // Convertir a entero
                if (continuar != 1 && continuar != 0) {
                    cout << "Entrada invalida. Ingrese un numero (1 para Si, 0 para No)"<<endl;
                }
            } else {
                cout << "Entrada invalida. Ingrese un numero (1 para Si, 0 para No)"<<endl;
                continuar = -1; // Forzar repetición del bucle
            }
        } while (continuar != 1 && continuar != 0);


        if (continuar == 0) {
            cout << "Finalizando programa"<<endl;
            break;
        }
       
    } while (true);
}
int main()
{
    string filename = "grafo_1.txt";
    vector<vector<int>> matrix = leerGrafoDesdeArchivo(filename);

    // Mostrar la matriz
    cout << "Matriz leida desde el archivo:"<<endl;
    for (auto fila : matrix)
    {
        for (int dato : fila)
        {
            cout << dato << " ";
        }
        cout << endl;
    }

    buscarNodos(matrix);


    return 0;
};