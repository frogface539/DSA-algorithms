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

    bool cycleDetection(int src){
        unordered_map<int , int> parent;
        unordered_map<int , bool> visited;
        queue<int>q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr:adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }

                //cycle
                if(visited[nbr] == true && nbr != parent[frontNode]){
                    return true;
                }
            }

        }
        return false;
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
