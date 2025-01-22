#include <fstream>
#include <sstream>
#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <stack>
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

int dikstra(vector<vector<int>>& graf, int desitno)
{
    int n = graf.size();
    vector<bool> visited(n, false);
    vector<int> distancias(n,INT_MAX);

    distancias[0] = 0;

    for(int i = 0;i < n - 1; ++i){
        //elegir nodo con la distacia menor
        int u = menorDistanci(distancias,visited);
        visited[u] = true;
        // si alcanza el nodo destino
        if(u == desitno){
            return distancias[u];
        }
        // actuaizar las distancias de los nodos adyacentes no visitaddos
        for (int k = 0; k < n; ++k)
        {
            if(!visited[k] && graf[u][k] && distancias[u] != INT_MAX && distancias[u] + graf[u][k] < distancias[k]){
                distancias[k] = distancias[u] + graf[u][k];
            }
        }
    }

    return distancias[desitno] == INT_MAX ? -1 : distancias[desitno];
    
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

int main()
{
    char x;
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
   int result =  dikstra(adj,destino);

   cout<< result <<endl;
    
    return 0;
};