#include <iostream>
#include <climits>
using namespace std;

int findmin(int* weight, bool* visited, int n){
    int minvertex = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i]&& (minvertex==-1 || weight[i] < weight[minvertex])){
            minvertex = i;
        }
    }
    return minvertex;
}

void prims(int** edges, int n){
    int *parent = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++){

        weight[i]=INT_MAX;
        visited[i] = false;
    }

    parent[0] = -1;
    weight[0] = 0;

        for(int i = 0; i < n; i++){
            int minvertex = findmin(weight, visited, n);
            visited[minvertex] = true;

            for(int j = 0; j < n; j++){
                if(edges[minvertex][j] != 0 && !visited[j]){
                    if(edges[minvertex][j] < weight[j]){
                        weight[j] = edges[minvertex][j];
                        parent[j] = minvertex;
                    }
                }
            }
        }

    for(int i = 1; i < n; i++){
        if(parent[i] < i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself

  */
     int** edges = new int*[V];
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
        for(int j = 0; j < V; j++)
            edges[i][j] = 0;

    }



    for(int i = 0; i < E; i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges[x][y] = w;
        edges[y][x] = w;
    }

    prims(edges, V);


  return 0;
}
