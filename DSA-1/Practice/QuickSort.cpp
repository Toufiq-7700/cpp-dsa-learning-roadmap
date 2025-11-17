#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define long long ll;
using namespace std;

int Partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int i = lb, j = ub;
    while(i<j){
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;

        if(i<j)swap(arr[i], arr[j]);
    }
    swap(arr[lb],arr[j]);

    return j;
}

void QuickSort(int arr[],int lb, int ub){
    if (lb<ub)
    {
        int j = Partition(arr,lb,ub);
        QuickSort(arr,lb,j-1);
        QuickSort(arr,j+1,ub);
    }
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    QuickSort(arr,0,n-1);

    for(auto x : arr){
        cout<<x<<" ";
    }


    return 0;
}