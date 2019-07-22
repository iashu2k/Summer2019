/*
Given a graph with N vertices and Two Lists (U,V) of size M where (U[i],V[i])
and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in
the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are
connected an edge.
*/



#include <queue>
#include <bits/stdc++.h>
using namespace std;
int bfs(int **edges, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i!=j && edges[i][j]==1){
                for(int k = 0; k < n; k++){
                    if(k!=j&&k!=i&&edges[j][k]==1&&edges[i][k]==1)
                        count++;
                }
            }

        }
    }
    return count/6;
}




int solve(int V,int E,vector<int>u,vector<int>v)
{
	// Write your code here .
     int** edges = new int*[V];
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
        for(int j = 0; j < V; j++)
            edges[i][j] = 0;

    }



    for(int i = 0; i < E; i++){

        edges[u[i]-1][v[i]-1] = 1;
        edges[v[i]-1][u[i]-1] = 1;
    }



    int* visited = new int[V];
    for(int i = 0; i < V; i++)
        visited[i] = 0;




        return bfs(edges, V);

}
