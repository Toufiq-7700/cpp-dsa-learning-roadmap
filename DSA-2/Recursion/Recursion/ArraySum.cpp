#include<iostream>
#include<vector>
using namespace std;

int ArraySum(vector<int> arr, int idx){
    //compute the sum of the elements from index 0 to idx
    if( idx < 0 ) return 0;
    return ArraySum(arr, idx-1) + arr[idx];
}
int main(){
    vector<int> a = {3, 2, 5, 4};
    int n = a.size();
    int sum = ArraySum(a, n-1);
}
