#include<bits/stdc++.h>
using namespace std;
struct Sub{
    int i,j,ans;
};

Sub cros(vector<int> arr,int low,int mid,int high){
    int cnt=0;
    Sub s;
    
    for (int k = mid; k>=low; k--)
    {
        if(arr[k] > 0){ // if arr[k]=0, means no profit, so it break the profit streak, count again first , so use arr[k]>0, not arr[k]>-1
            cnt++;
            s.i=k;
        }
        else break;
    }
    for (int k = mid+1; k <= high; k++)
    {
        if(arr[k]>0){
            cnt++;
            s.j=k;
        }
        else break;
    }
    s.ans = cnt;
    return s;
}


Sub func(vector<int> arr, int low, int high){
    
    if(low == high){
        if(arr[low] > 0){
            Sub s;
            s.ans = 1;
            s.i =low;
            s.j = high;
            return s;
        }
        else {
            Sub s;
            s.ans = 0;
            s.i =low;
            s.j = high;
            return s;
        }
    }
    int mid=(low+high)/2;
    Sub left = func(arr,low,mid);
    Sub right = func(arr,mid+1,high);

    Sub crs = cros(arr,low,mid,high);

    if(left.ans >= right.ans && left.ans >= crs.ans) return left;
    else if(right.ans >= left.ans && right.ans >= crs.ans) return right;
    else return crs;
}



int main(){
    vector<int> arr={3, -1, 9, -2, 4, 3, 1, -5, 3, 2};
    int low = 0;
    int high = arr.size();
    Sub Ans = func(arr,low,high-1);
 
    cout <<"Longest consecutive profit period " << Ans.ans << " months..!!" << endl;

    cout<<"Month Range :{ ";
    for(int k=Ans.i; k<=Ans.j; k++){

        cout<<"M"<<k<<", ";
    }
    cout<<"}"<<endl;

    return 0;
}
