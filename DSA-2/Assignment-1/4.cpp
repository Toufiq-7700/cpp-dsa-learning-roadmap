#include<bits/stdc++.h>
using namespace std;
struct sub
{
    int ans;
    int i,j;
};

sub cross(vector<int>arr, int low,int mid, int high){
    sub s;
    s.ans = INT_MIN;
    int sum=INT_MIN;
    if(mid-1 >= low && mid+1 <= high){
        int x = arr[mid-1]+arr[mid]+arr[mid+1];
        if(x>sum){
            sum = x;
            s.ans = sum;
            s.i = mid-1;
            s.j = mid+1;
        }
    }
    if(mid >= low && mid+2 <= high){
        int x = arr[mid-1]+arr[mid]+arr[mid+1];
        if(x>s.ans){
            sum = x;
            s.ans = sum;
            s.i = mid-1;
            s.j = mid+1;
        }
    }
    return s;
}

sub maxavgtemp(vector<int> arr, int low, int high){
    sub s;

    if(high-low < 2){
        sub s;
        s.ans = INT_MIN;
        s.i = -1;
        s.j = -1;
        return s;
    }
    if(high - low == 2){
        int x = arr[low]+arr[low+1]+arr[low+2];
        sub s;
        s.ans = x;
        s.i = low;
        s.j = low+2;
        return s;
    }
    int mid = (low+high)/2;

    sub temp1=maxavgtemp(arr,low,mid);
    sub temp2=maxavgtemp(arr,mid+1,high);
    sub temp3=cross(arr,low,mid,high);

    if(temp1.ans > temp2.ans && temp1.ans > temp3.ans) return temp1;
    else if(temp2.ans > temp1.ans && temp2.ans > temp3.ans) return temp2;
    else return temp3;
}

int main(){
    vector<int> temperature = {28, 31, 29, 34, 30, 33, 27, 35, 32};
    int low=0;
    int high = temperature.size();
    sub ans = maxavgtemp(temperature,low,high-1);
    int i = ans.i;
    int j = ans.j;

    cout<<"The 3-day subarray with the maximum total temperature is :[ ";
    for(int k=i; k<=j; k++){
        cout<<temperature[k]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"TOTAL : "<<ans.ans<<endl;

    return 0;
}
