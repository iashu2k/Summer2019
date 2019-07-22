#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    int v1;
    int v2;
    int weight;

};

bool compareInterval(edge i1, edge i2)
{
    return (i1.weight < i2.weight);
}

int findparent(int v, int *parent){
    if(parent[v]==v)
        return v;

    return findparent(parent[v], parent);

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
    edge *arr = new edge[E];
    edge *output = new edge[V-1];

    for(int i = 0; i < E; i++){
        cin>>arr[i].v1;
        cin>>arr[i].v2;
        cin>>arr[i].weight;
    }

    int *parent = new int[V];
    for(int i = 0; i < V; i++){
        parent[i] = i;
    }

    sort(arr, arr+E, compareInterval);

    int count = 0,i = 0;
    while(count!=V-1){

        int v1parent = findparent(arr[i].v1, parent);
        int v2parent = findparent(arr[i].v2, parent);

        if(v1parent!=v2parent){
            parent[v2parent] = v1parent;
            output[count] = arr[i];
            count++;
        }

        i++;

    }

    for(int i = 0; i < V-1; i++){
        cout<<min(output[i].v1, output[i].v2)<<" "<<max(output[i].v2, output[i].v1)<<" "<<output[i].weight<<endl;
    }



  return 0;
}
