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

    void dfs(int src) {
    }
}; 

int main() {
    graph g;
    int src = 2;
    g.addEdge(src , 3 , 1);
    g.addEdge(3 , 4 , 1);
    g.addEdge(4 , 2 , 1);
    g.dfs(src);
    return 0;
}
