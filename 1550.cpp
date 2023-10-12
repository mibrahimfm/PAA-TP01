#include <bits/stdc++.h>
using namespace std;
using std::cout, std::cin;

int invertNumber(int n){
    int invertedNumber = 0;
    while (n > 0){
        invertedNumber = invertedNumber * 10 + n % 10;
        n /= 10;
    }

    return invertedNumber;
}

class Graph {
public:
    map<int, bool> visited;    
    int BFS(int v, int w);
};
 
int Graph::BFS(int v, int w)
{
    list<int> queue;

    map<int, int> distance;
    distance[v] = 0;
 
    visited[v] = true;
    queue.push_back(v);
 
    while (!queue.empty()) {
        v = queue.front();
        queue.pop_front();
        
        int increment, reverse;
        increment = v + 1;
        reverse = invertNumber(v);
        
        cout << "Increment: " << increment << " Reverse: " << reverse << "\n";
        cout << v << " " << w << "\n";
        for(auto &x : distance){
            cout << "Vertex:" << x.first << " Distance: " << x.second << ", ";
        }
        cout << "\n";
        if (increment == w || reverse == w)
            return ++distance[v];

        if (!visited[increment]){
            visited[increment] = true;
            cout << "Distance[v]+1: " << distance[v] + 1 << "\n";
            distance[increment] = distance[v] + 1;
            queue.push_back(increment);            
        }
        if (!visited[reverse]){
            visited[reverse] = true;
            distance[reverse] = distance[v] + 1;
            queue.push_back(reverse);
        }    
    }

    return -1;
}
 
int main()
{

    int testCases;

    cin >> testCases;
    for(int t = 1; t <= testCases; t++){
        Graph g;
        int a, b;
        cin >> a >> b;

        cout << g.BFS(a, b) << "\n";
    }
    
    return 0;
}
 