#include <bits/stdc++.h>
using namespace std;
using std::cout, std::cin;

class Graph {
public:
    map<char, bool> visited;
    map<char, list<char>> adj;
    
    void addNode(char n);
    void addEdge(char v, char w);
    list<char> BFS(char v);
    bool allVisited();
    char findNotVisitedElement();
};

void Graph::addNode(char n){
    visited.insert({n, false});
    adj[n];
}

void Graph::addEdge(char v, char w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
list<char> Graph::BFS(char v)
{
    list<char> result;
    list<char> queue;
 
    visited[v] = true;
    queue.push_back(v);
 
    while (!queue.empty()) {
 
        v = queue.front();
        result.push_back(v);
        queue.pop_front();
 
        for (auto adjacent : adj[v]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }

    return result;
}

bool Graph::allVisited(){    
    for (const auto &pair : visited)
    {
        if (!pair.second)
        {
            return false;
        }
    }

    return true;
}

char Graph::findNotVisitedElement(){
    for (const auto &pair : visited)
    {
        if (!pair.second)
        {
            return pair.first;
        }
    }

    return ' ';
}
 
int main()
{

    int testCases;

    cin >> testCases;
    for(int t = 1; t <= testCases; t++){
        cout << "Case #" << t << ":\n";
        Graph g;
        int v, e;
        cin >> v >> e;

        for (int i = 0; i < v; i++){
            char n = i + 97;
            g.addNode(n);
        }

        for (int i = 0; i < e; i++){
            char u, w;
            cin >> u >> w;
            g.addEdge(u, w);
        }
        
        int it = 0;
        while(!g.allVisited()){
            it++;
            char n = g.findNotVisitedElement();
            auto bfs = g.BFS(n);
            bfs.sort();
            for (auto node : bfs){
                cout << node << ",";
            }
            cout << "\n";
        }

        cout << it << " connected components\n\n";
    } 
    return 0;
}
 