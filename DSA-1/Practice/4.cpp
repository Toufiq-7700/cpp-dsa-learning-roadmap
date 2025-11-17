#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

void Selection_Sort(int arr[],int n){

    for (size_t i = 0; i < n; i++)
    {
        int min = i;

        for (size_t j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min]) min = j;
        }
        swap(arr[i],arr[min]);
    }  
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i = 0; i<n; i++)cin>>arr[i];

    Selection_Sort(arr,n);

    for(int i = 0; i<n; i++)cout<<arr[i]<<" ";

    return 0;
}