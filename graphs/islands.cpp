/*
An island is a small piece of land surrounded by water .
A group of islands is said to be connected if we can reach from any given
island to any other island in the same group . Given N islands
(numbered from 1 to N) and two lists of size M (u and v) denoting island u[i]
is connected to island v[i] and vice versa . Can you count the number of
connected groups of islands.
*/

#include<iostream>
#include<vector>
#include <queue>
using namespace std;


void bfs(int **edges, int n, int sv, int *visited){
    queue<int> q;

    q.push(sv);

    visited[sv] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();


        for(int i = 0; i < n; i++){
            if(t == i)
                continue;

            if(edges[t][i] == 1){
                if(visited[i] == 1)
                    continue;
                else{

                    q.push(i);
                    visited[i] = 1;
                }

            }
        }
    }

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

    int count = 0;
    for(int i = 0; i < V; i++){
        if(visited[i]==0){
            bfs(edges, V, i, visited);
            count++;
        }


    }
    return count;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
