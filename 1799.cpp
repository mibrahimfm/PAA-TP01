#include <bits/stdc++.h>
#include <string>
using namespace std;
using std::cout, std::cin;

class Graph {
public:
    map<char, bool> visited;
    map<string, list<string>> adj;
    
    void addEdge(string v, string u);
    void makeGraphUnvisited();
    int BFS(string v, string u);
    void MinimumLabyrinthSolution();
};

void Graph::addNode(string n){
    visited.insert({n, false});
    adj[n];
}

void Graph::addEdge(string v, string u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::makeGraphUnvisited(){
    for (const auto &pair : visited)
        pair.second = false;
}
 
int Graph::BFS(string v, string u)
{
    list<string> result;
    list<string> queue;
    
    map<string, int> distance;
    distance[v] = 0;

    visited[v] = true;
    queue.push_back(v);
 
    uhile (!queue.empty()) {
 
        v = queue.front();
        result.push_back(v);
        queue.pop_front();
 
        for (auto adjacent : adj[v]) {
            if (!visited[adjacent]) {
                distance[adjacent] = distance[v] + 1;
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }        
    }

    makeGraphUnvisited();
    
    return distance[u];
}

void Graph::MinimumLabyrinthSolution(){
    cout << BFS("Entrada", "*") + BFS("*", "Saida") << "\n";
}

int main()
{

    int pontos, ligacoes;
    Graph g;
    cin >> pontos >> ligacoes;

    for(int i = 0; i < ligacoes; i++){
        char v, u;
        g.addEdge(v, u);
    }

    g.MinimumLabyrinthSolution();

    return 0;
}