#include <bits/stdc++.h> 
using namespace std; 

struct Edge{
    int v;
    int u;
    int weight;
};

class UnionFind { 
    int* parent; 
    int* rank; 
  
public: 
    UnionFind(int n);
    int find(int i);  
    void unite(int x, int y);
}; 

UnionFind::UnionFind(int n){ 
    parent = new int[n]; 
    rank = new int[n]; 

    for (int i = 0; i < n; i++) { 
        parent[i] = -1; 
        rank[i] = 1; 
    } 
} 

int UnionFind::find(int i){ 
    if (parent[i] == -1) 
        return i; 
    
    parent[i] = find(parent[i]);
    return parent[i]; 
}

void UnionFind::unite(int x, int y) 
{ 
    int s1 = find(x); 
    int s2 = find(y); 

    if (s1 != s2) { 
        if (rank[s1] < rank[s2]) { 
            parent[s1] = s2; 
        } 
        else if (rank[s1] > rank[s2]) { 
            parent[s2] = s1; 
        } 
        else { 
            parent[s2] = s1; 
            rank[s1] += 1; 
        } 
    } 
}

class Graph { 
    list<Edge> adj; 
    int V; 
  
public: 
    Graph(int V);      
    void addEdge(int v, int u, int weight);  
    int mst_kruskal();
    int savings(int minCost);
}; 

Graph::Graph(int V){
    this->V = V;
}

void Graph::addEdge(int v, int u, int weight) 
{ 
    adj.push_back({v, u, weight}); 
} 

int Graph::mst_kruskal()
{
    adj.sort([](Edge const &u, Edge const &v ){ return u.weight < v.weight; }); 

    UnionFind unionFind(V);
    int cost = 0; 

    for (auto edge : adj) { 
        int v = edge.v;
        int u = edge.u; 
        int w = edge.weight; 


        if (unionFind.find(v) != unionFind.find(u)) { 
            unionFind.unite(v, u); 
            cost += w;
        } 
    } 
    return cost;
} 


// Driver code 
int main() 
{ 
    while(true){
        int m, n, totalCost = 0;
        cin >> m >> n;

        if (m == 0 && n == 0)
            break;
        
        Graph g(m);

        for(int i = 0; i < n; i++){
            int x, y, z;
            cin >> x >> y >> z;            
            g.addEdge(x, y, z);

            totalCost += z;
        }
        
        int c = g.mst_kruskal();
        cout << totalCost - c << "\n";
    }

    return 0; 
}