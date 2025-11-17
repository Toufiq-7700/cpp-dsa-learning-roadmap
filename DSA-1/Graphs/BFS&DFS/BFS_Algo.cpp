//BFS
#include<bits/stdc++.h>
using namespace std;
#include<queue>
#include<vector>


vector<int> BFSGraph(int v, vector<int>adj[]){
    queue<int> q;
    vector<int> ans;
    vector<bool> visited(v,0);
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int i = 0; i< adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                visited[adj[node][i]] = 1;
                q.push(adj[node][i]);
            }
        }
    }

    return ans;
}

int main(){



    return 0;
}