#include<bits/stdc++.h>
using namespace std;
//Array Sum

int arrsum(vector<int> arr, int idx){
    if(idx < 0) return 0;

    return arrsum(arr,idx-1) + arr[idx];


}


int main(){

    vector<int> arr ={1,2,3,4,5};
    int idx = arr.size()-1;

    cout<<arrsum(arr, idx);




    return 0;
}


