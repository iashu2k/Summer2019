/*
Its Gary's birthday today and he has ordered his favourite square cake
consisting of '0's and '1's . But Gary wants the biggest piece of
'1's and no '0's . A piece of cake is defined as a part which consist of
only '1's, and all '1's share an edge with eachother on the cake.
Given the size of cake N and the cake , can you find the size of the biggest
piece of '1's for Gary ?
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define NMAX 55


int findsize(char cake[NMAX][NMAX], int n, int row, int col, int** visited){
    if(row>=n||col>=n||row<0||col<0)
        return 0;

    int up, down, left, right;
    if(cake[row][col]=='1'&&visited[row][col]==0){
        visited[row][col]=1;
        up = findsize(cake, n, row-1, col, visited);
        down = findsize(cake, n, row+1, col, visited);
        left = findsize(cake, n, row, col-1, visited);
        right = findsize(cake, n, row, col+1, visited);
        return up+down+right+left+1;
    }
    return 0;

}

int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    int maxi = INT_MIN;

    int** visited = new int*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new int[n];
        for(int j = 0; j < n; j++)
            visited[i][j] = 0;

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j]=='1'){
                maxi = max(findsize(cake, n, i, j, visited), maxi);
            }

        }
    }

    return maxi;
}

char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
