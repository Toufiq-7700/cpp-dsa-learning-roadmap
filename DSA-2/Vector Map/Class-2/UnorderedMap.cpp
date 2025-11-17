#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<map>

using namespace std;


int main(){
    unordered_map<string,int> m;

    
    m.insert(make_pair("Toufiq",555));
    m.insert(make_pair("Toufiq",52));
    m.insert(make_pair("Imroz",5));
    m.insert(make_pair("Topu",444));

    for(auto  p : m){
        cout<<p.first << " -> " << p.second<<endl;
    }


    
    return 0;
}
