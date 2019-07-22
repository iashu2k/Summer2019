/*
You are given with an array of integers that contain numbers in random order.
Write a program to find the longest possible sub sequence of consecutive
 numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order
 of elements in the output is not important.
Best solution takes O(n) time.
If two arrays are of equal length return the array whose index of smallest
 element comes first.
*/

#include<iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <climits>

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    unordered_map<int, bool> m;
    for(int i=0 ;i < n ; i++ ){
        if(m.count(arr[i])==0)
            m[arr[i]] = true;
    }

    int max = INT_MIN;
    int start;
    int idx;

    for(int i = 0 ; i < n ; i++){

        if(m[arr[i]]==true){
            int key = arr[i];
            int length = 0;
            while(m.count(key)!=0){
                length++;
                m[key]=false;
                key++;
            }

            key = arr[i]-1;
            while(m.count(key)!=0){
                length++;
                m[key] = false;
                key--;
            }

            if(max == length){
                int temp;
                for(int k =0 ; k < n ; k++){
                    if(arr[k]==key+1){
                        temp = k;
                        break;
                    }
                }
                if(temp < idx){
                    idx = temp;
                    start = key + 1;

                }
            }

            if(length > max){
                max = length;
                start = key+1;
                for(int k =0 ; k < n ; k++){
                    if(arr[k]==key+1){
                        idx = k;
                        break;
                }
            }
        }
    }
    }

    vector<int> v;
    for(int k = start ; k < max+start ; k++)
        v.push_back(k);


    return v;

}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	vector<int> output = longestSubsequence(input, n);
	for(int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}
