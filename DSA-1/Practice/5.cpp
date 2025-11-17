#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

void marge(int arr[],int lb,int mid,int ub){
    int i,j,k;
    int nL = mid-lb+1, rL = ub-mid;
    int leftarr[nL+1], rightarr[rL+1];

    j = 0;
    for(i = lb;i<=mid;i++){
        leftarr[j++] = arr[i];
    }
    leftarr[j] = INT_MAX;

    j = 0;
    for(i = mid+1;i<=ub;i++){
        rightarr[j++] = arr[i];
    }
    rightarr[j] = INT_MAX;

    i = j = 0;

    for (size_t k = lb; k <= ub; k++)
    {
        if (leftarr[i] < rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }   
    }
}



void margesort(int arr[],int lb, int ub){
    if(lb < ub){
        int mid = (lb+ub)/2;
        margesort(arr,lb,mid);
        margesort(arr,mid+1,ub);

        marge(arr,lb,mid,ub);
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    margesort(arr,0,n-1);

    for(auto x : arr){
        cout<<x<<" ";
    }

    return 0;
}