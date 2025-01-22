#include <vector>
#include <iostream>
#include <climits>
#include <string>
#include <fstream>
#include <sstream>
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

    vector<int> fianlcam;

    for (int actual = desitno; actual != -1; actual = caminosRec[actual]) {
        fianlcam.push_back(actual);
    }

    // Invertir el camino manualmente
    vector<int> caminoOrdenado(fianlcam.size());
    for (int i = 0; i < fianlcam.size(); ++i) {
        caminoOrdenado[fianlcam.size() - 1 - i] = fianlcam[i];
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

vector<vector<int>> leerGrafoDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
   
    string linea;
    vector<vector<int>> graf;

    if(getline(archivo,linea)){
        int n = stoi(linea);
        while(getline(archivo,linea)){
            vector<int> fila;
            stringstream ss(linea);
            string valpos;

            while(getline(ss,valpos)){
                fila.push_back(stoi(valpos)); // char to int segun [fila][col]
            }
            graf.push_back(fila);
        }
    }
    else{
        cout<<"no esta el arch"<<endl;
    }
    return graf;
}
int main()
{

    string nombreArchivo = "adyMariz.txt";
    vector<vector<int>> grafo = leerGrafoDesdeArchivo(nombreArchivo);

    cout << "Matriz de adyacencia:" << endl;
    for (const auto& fila : grafo) {
        for (int valor : fila) {
            cout << valor << " ";
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
   auto result =  dikstra(grafo,destino);




    cout<<"camino tomado para llegar al destino"<<endl;
   printCaminosDestino(result.first);

    cout<<"distancia total "<<result.second<<endl;
    
    return 0;
};