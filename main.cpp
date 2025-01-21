#include <fstream>
#include <sstream>
#include <string>

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*class Ady{
    public:
    Ady* sig;
    Ady* ref;
    Ady(){}

};
class Nodo{
public:
    char dato;
    Nodo* sig;
    Ady* ady;
    Nodo(char dato){
        this->dato = dato;
        sig = nullptr;
    }

};


class Arco{
public:
    int peso;
    Arco* sig;
    Nodo* first;
    Nodo* second;
    Arco(){}
};
*/
void bfs(vector<vector<int>>& graf,int inicio)
{
    // variables
    int n = graf.size();
    vector<bool> visited(n, false);
    queue<int> kyu;
    //vector<int> caminosMenores(n,INT_MAX);


    // acciones
    visited[inicio] = true;
    kyu.push(inicio);
    //caminosMenores[0] = 0;


    while(!kyu.empty()){
        int nodo = kyu.front();
        kyu.pop();

        for(int i = 0; i < n; ++i){
            if(graf[nodo][i] != 0 && !visited[i]){
                visited[i] = true;
                kyu.push(i);
            }
        }

    }

    
}

void dikstra(vector<vector<int>>& graf, int source)
{
    int n = graf.size();
    vector<bool> visited(n, false);
    vector<int> sumaCaminos;
    queue<int> kyu;
    visited[source] = true;
    sumaCaminos.push_back(0);
}


int main()
{

    bool flag = true;
    while (flag)
    {
        char x;
        cin >> x;

        int nodo = x;

        cout << "nodo " << nodo << " " << x << endl;
        if (nodo < 65 || nodo > 90)
        {
            flag = false;
            break;
        }
    }

    std::ifstream file("matriz_N.txt");
    if (!file.is_open()) {
        cout << "Error al abrir el archivo" << std::endl;
        return 1;
    }

    string line;
    while (getline(file,line)) { // Read line by line
        
        cout<<line<<endl;
    }

    file.close(); // Close the file
    return 0;
};