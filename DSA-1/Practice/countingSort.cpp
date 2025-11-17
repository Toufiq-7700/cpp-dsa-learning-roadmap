#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define long long ll;
using namespace std;

void countingSort(int arr[],int n, int range){
    vector<int> cnt(range+1, 0);
    //vector<int> freq(range+1, 0);
    vector<int> ans(n);

    for (size_t i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }
    
    //cnt[0] = cnt[0];
    for (size_t i = 1; i <= range; i++)
    {
        cnt[i] = cnt[i-1] + cnt[i];
    }

    for(int i = n-1; i>=0; i--){
        ans[--cnt[arr[i]]] = arr[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
       
}


int main(){
    int n, range;
    cin>>n>>range;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    countingSort(arr,n,range);

    for(auto x : arr){
        cout<<x<<" ";
    }


    return 0;
}