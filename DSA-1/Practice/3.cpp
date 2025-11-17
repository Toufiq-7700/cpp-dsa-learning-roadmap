#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

void Merge(int arr[],int l , int m, int h){
    int i,j,k;

    int nL = m-l+1;
    int nR = h-m;
    int leftarr[nL+1];
    int rightarr[nR+1];

    j = 0;
    for(i = l; i<=m; i++){
        leftarr[j++] = arr[i];
    }
    leftarr[j] = INT_MAX;

    j = 0;
    for(i = m+1; i<=h; i++){
        rightarr[j++] = arr[i];
    }
    rightarr[j] = INT_MAX;

    i = j = 0;

    for( k = l; k<=h;k++){

        if(leftarr[i] < rightarr[j]){
            arr[k] = leftarr[i];
            i++;
        }
        else{
            arr[k] = rightarr[j];
            j++;
        }
    }
}

void MergeSort(int arr[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        MergeSort(arr,lb,mid);
        MergeSort(arr,mid+1,ub);

        Merge(arr,lb,mid,ub);

    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    MergeSort(arr,0,n-1);

    for(auto x : arr){
        cout<<x<<"  ";
    }


    return 0;
}