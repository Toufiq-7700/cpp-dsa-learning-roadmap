#include<bits/stdc++.h>
using namespace std;
struct sub
{
    int ans;
    int i,j;
};

sub cross(vector<int>arr, int low, int high){
    sub s;
    int sum=INT_MIN;

    for(int i=low+2; i<=high-2; i++){
        int tempsum = arr[i]+arr[i+1]+arr[i+2];
        if(tempsum>sum){
            sum = tempsum;
            s.ans = tempsum;
            s.i=i;
            s.j=i+2;
        }
    }
    return s;
}

sub maxavgtemp(vector<int> arr, int low, int high){
    int len = arr.size();
    int a = low + len/3; //one third
    int b = low + 2 * (len/3); //two third

    if(high-low +1 == 3){
        sub s;
        int x=arr[low];
        int y=arr[low+1];
        int z=arr[low+2];
        s.ans = (x+y+z);
        //maximum sum corresponds to maximum average so i think dividing by 3 is unnecessary for comparison, it makes unexpected result for some array
        s.i=low;
        s.j=high;
        return s;
    }

    sub temp1=maxavgtemp(arr,low,a-1);
    sub temp2=maxavgtemp(arr,a,b-1);
    sub temp3=maxavgtemp(arr,b,high);
    sub temp4=cross(arr,low,high);

    if(temp1.ans > temp2.ans && temp1.ans > temp3.ans && temp1.ans > temp4.ans) return temp1;
    else if(temp2.ans > temp1.ans && temp2.ans > temp3.ans && temp2.ans > temp4.ans) return temp2;
    else if(temp3.ans > temp1.ans && temp3.ans > temp2.ans && temp3.ans > temp4.ans) return temp3;
    else return temp4;
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