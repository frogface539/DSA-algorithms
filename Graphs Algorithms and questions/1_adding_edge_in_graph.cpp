#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class graph{
    public:
    unordered_map<int , vector<int>> adjList;
    void addEdge(int u , int v , bool direction){
        //undirected graph
        if(direction == 0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        //directed graph
        if(direction == 1){
            adjList[u].push_back(v);
        }
    }
};

//weighted graph
// class wtdGraph{
//     public:
//     unordered_map<int , vector<int , int>> adjList;
//     void addEdge(int u , int v , int weight , bool direction){
//         //undirected graph
//         if(direction == 0){
//             adjList[u].push_back({v,weight});
//             adjList[v].push_back({u,weight});
//         }
//         //directed graph
//         if(direction == 1){
//             adjList[u].push_back({v.weight});
//         }
//     }
// };

int main(){
    graph g;
    g.addEdge(2 , 3 , 1);
    g.addEdge(3 , 4 , 1);
    g.addEdge(4 , 2 , 1);

}

