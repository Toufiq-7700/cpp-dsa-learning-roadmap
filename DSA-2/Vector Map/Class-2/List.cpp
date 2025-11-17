#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<list>

using namespace std;
int main(){
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(5);

    l.pop_back();
    l.pop_front();


    for(auto x : l){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto it = l.rbegin(); it != l.rend(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
