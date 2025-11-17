#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;


int main(){

    vector<double> v={4.5,2.3,4.5,6.8};
    v.push_back(5.9);
    v.push_back(6.9);
    int n = v.size();
    cout<<n<<endl;

    for(double x: v){
        cout<<x<< " ";
    }
    cout<<endl;

    sort(v.begin(), v.end());

    //sort(v.rbegin(), v.rend());

    for(double x: v){
        cout<<x<< " ";
    }
    cout<<endl;

    //gives 1 or 0
    cout<<"Binary search val : "<<binary_search(v.begin(),v.end(),5)<<endl;

    cout<<"Find the val at 1 based index: "<<(find(v.begin(),v.end(),6.8)-v.begin())<<endl;


    return 0;
}

