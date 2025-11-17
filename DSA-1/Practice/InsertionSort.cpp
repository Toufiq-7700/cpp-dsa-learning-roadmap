#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define long long ll;

using namespace std;


void insertion_sort(int arr[], int n){
    int cnt = 0;

    for (size_t i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] < key)
        {
            cnt++;
            arr[j+1] = arr[j];
            j--;
            for(int i = 0; i<5; i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
        arr[j+1] = key;
    }
    cout<<cnt<<"   ";
    
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    insertion_sort(arr,n);

    for(auto x : arr){
        cout<<x<<" ";
    }


    return 0;
}