/*
You are given with an array of integers and an integer K.
Write a program to find and print all pairs which have difference K.
Best solution takes O(n) time. And take difference as absolute.
*/

#include<iostream>
using namespace std;
#include <unordered_map>
void printPairs(int *input, int n, int k) {
	// Write your code here
    unordered_map<int, int> m;
    for(int i =0 ; i < n ; i++){
        int key = input[i];
        if(m.count(key)>0){
            m[key]++;
        }
        else{
            m[key]=1;
        }

    }

    unordered_map<int, int> :: iterator it = m.begin();
    while(it!=m.end()){
        int key1 = it->first;
        if(k==0){
            for(int i=0 ; i < (m[key1]*(m[key1]-1))/2 ; i++)
                cout<<key1 << " "<<key1<<endl;
        }
        else{
        int key2 = key1 + k;
        if(m.count(key2)>0){
            for(int i=0 ; i < (it->second*m[key2]) ; i++)
                cout<<min(key1,key2)<<" "<<max(key1,key2)<<endl;



        }
        }
        it++;
    }

}


int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
