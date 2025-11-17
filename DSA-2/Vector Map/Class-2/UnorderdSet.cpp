#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
int main(){
    unordered_set<int> us;
    us.insert(1);
    us.insert(10);
    us.insert(20);
    us.insert(10);
    us.insert(30);
    us.insert(15);

    for(auto it : us) cout<<it<<" ";

    return 0;
}
