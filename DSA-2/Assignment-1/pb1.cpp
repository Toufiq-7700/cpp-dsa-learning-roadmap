#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

struct xx
{
    int i,j,sum;
};

xx cross(vector<int> arr, int low,int mid, int high){
    int li,ri,cnt=0;

    for(int i=mid; i>=low; i--){
        if(arr[i] > 0){
            li=i;
            cnt++;
        }
        else break;
    }
    for(int i=mid+1; i<=high; i++){
        if(arr[i] > 0){
            ri=i;
            cnt++;
        }
        else break;
    }
    xx s;
    s.sum = cnt;
    s.i=li;
    s.j=ri;
    return s;
}

xx func(vector<int> arr, int low, int high){
    if(low == high){
        if(arr[low]){
            xx s;
            s.sum = 1;
            s.i = low;
            s.j = high;
            return s;
        }
        else{
            xx s;
            s.sum = 0;
            s.i = low;
            s.j = high;
            return s;
        }
    }
    int mid = (low+high)/2;

    xx left = func(arr, low, mid);
    xx right = func(arr, mid+1, high);

    xx crs = cross(arr,low,mid,high);

    if(left.sum >= right.sum && left.sum >= crs.sum) return left;
    if(right.sum >= left.sum && right.sum >= crs.sum) return right;
    else return crs;
}


int main(){
    vector<int> arr = {3, -1, 9, -2, 4, 3, 1, -5, 3, 2 };
    int low=0;
    int high=arr.size();

    xx ans = func(arr,low,high-1);

    cout<<ans.sum<<endl;


    return 0;
}