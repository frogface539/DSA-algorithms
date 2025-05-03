#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class graph {
    public:
    unordered_map<int , vector<int>> adjList;
    
    void addEdge(int u , int v , bool direction) {
        // undirected graph
        if(direction == 0) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        // directed graph
        if(direction == 1) {
            adjList[u].push_back(v);
        }
    }

    void bfs(int src) {
        queue<int> q;
        unordered_map<int , bool> visited;
        q.push(src);
        visited[src] = true;

        while(q.empty() != true){
            int front = q.front();
            q.pop();
            cout << front << " ";

            for(auto nbr : adjList[front]){
                int node = nbr;
                if(!visited[node]){
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
    }
}; 

int main() {
    graph g;
    int src = 2;
    g.addEdge(src , 3 , 1);
    g.addEdge(3 , 4 , 1);
    g.addEdge(4 , 2 , 1);
    g.bfs(src);
    return 0;
}
