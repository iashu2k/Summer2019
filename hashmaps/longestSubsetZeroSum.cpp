/*
Given an array consisting of positive and negative integers,
find the length of the longest continuous subset whose sum is zero.
*/

#include<iostream>
#include <climits>
#include <unordered_map>
#include <iostream>

using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int size){

  // Write your code here
    unordered_map<int, int> m;
    int sum = 0;
    int max = 0;

    for(int i = 0 ; i < size ; i++){
        sum+=arr[i];
        if(sum==0 && max == 0)
            max = i+1;
        if(m.count(sum)==0){
            m[sum] = i;
        }
        else{
            if((i - m[sum]) > max)
                max = i - m[sum];
        }
    }
  // Write your code here
    return max;

}



int main(){
  int size;

  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}
