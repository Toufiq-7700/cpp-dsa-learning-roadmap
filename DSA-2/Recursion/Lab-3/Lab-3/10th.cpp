#include<bits/stdc++.h>
using namespace std;
//Array Sum

int even(int n){
   if(n%2 ==0) return n;

   return 0;

}

int arrsum(vector<int> arr, int idx){

    if(idx < 0) return 0;
    return arrsum(arr,idx-1) + even(arr[idx]);
}

int main(){

    vector<int> arr ={1,2,3,4,5,6,7,8};
    int idx = arr.size()-1;

    cout<<arrsum(arr, idx);


    return 0;
}


