#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
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

int menorDistanci(vector<int>&caminos, vector<bool>& visited){

    int menor = INT_MAX;
    int menorIndex = -1;

    for(int i = 0; i < caminos.size(); ++i){
        if(!visited[i] && caminos[i] <= menor){
            menor = caminos[i];
            menorIndex = i;
        }
    }
    return menorIndex;
}

pair<vector<int>,int> dikstra(vector<vector<int>>& graf, int desitno)
{
    int n = graf.size();
    
    vector<int> caminosRec(n,-1); // follow da way
    vector<bool> visited(n, false);
    vector<int> distancias(n,INT_MAX);

    distancias[0] = 0;

    for(int i = 0;i < n - 1; ++i){
        //elegir nodo con la distacia menor
        int u = menorDistanci(distancias,visited);
        visited[u] = true;
        if(u == -1) break; // si ya se visitaron todos los nodos
        
        if(u == desitno){ // si alcanza el nodo destino
            break;

        }
        // actuaizar las distancias de los nodos adyacentes no visitaddos
        for (int k = 0; k < n; ++k)
        {
            if(!visited[k] && graf[u][k] && distancias[u] != INT_MAX && distancias[u] + graf[u][k] < distancias[k]){

                distancias[k] = distancias[u] + graf[u][k];
                
                caminosRec[k] = u;
            }
        }
    }


    if(distancias[desitno] == INT_MAX) return {{},-1};

    vector<int> caminosTomados;
    // chantar caminos recorridos
    for (int actual = desitno; actual != -1; actual = caminosRec[actual]) {
        caminosTomados.push_back(actual);
    }

    // Invertir el camino 
    vector<int> caminoOrdenado(caminosTomados.size());
    for (int i = 0; i < caminosTomados.size(); ++i) {
        caminoOrdenado[caminosTomados.size() - 1 - i] = caminosTomados[i];
    }

    return {caminoOrdenado,distancias[desitno]};
}

int chartoInt(char nodo)
{

    // A - Z == 65 - 90
    int nodo_int = nodo;
    if(nodo_int < 65 || nodo_int > 90){
        cout <<"nodo no permitido. (solo A -> Z) :v "<<endl;
        return -1;
    }
    return nodo_int - 65;
}


void printCaminosDestino(vector<int>& caminos){

    for(int i = 0; i < caminos.size(); i++){
        char x = caminos[i] + 65;
        cout<<x<<" -> ";
    }
    cout<<endl;

}

vector<vector<int>> leerGrafoDesdeArchivo(string& nombreArchivo) {
    ifstream arch(nombreArchivo);

    string linea;
    vector<vector<int>> matrix;


    cout<<nombreArchivo<<endl;

    if(getline(arch,linea)){
        int n = stoi(linea);

        while(getline(arch,linea)){
            vector<int> fila;
            stringstream ss(linea);

            string valopos;
            while(getline(ss,valopos,' ')){
                fila.push_back(stoi(valopos));
            }
            matrix.push_back(fila);
        }
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }

    return matrix;
}

int main()
{

     string filename = "adyMatriz.txt";  // Asegúrate de usar una ruta relativa válida
    vector<vector<int>> matrix = leerGrafoDesdeArchivo(filename);

    // Mostrar la matriz
    cout << "Matriz leida desde el archivo:\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }


    char x;
    cout<<"ingrese destino(A -> Z):  ";
    cin>>x;

    int destino = chartoInt(x);
    cout<<destino<<endl;

    vector<vector<int>> adj = {
        {0, 2, 3, 0, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 2, 0},
        {0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0}

    };
   auto result =  dikstra(adj,destino);




    cout<<"camino tomado para llegar al destino"<<endl;
   printCaminosDestino(result.first);

    cout<<"distancia total "<<result.second<<endl;
    
    return 0;
};