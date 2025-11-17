#include<bits/stdc++.h>
using namespace std;

class Island{
public:
    int n;
    bool dir;
    vector<int> parent, key, qu;
    vector<vector<int>> p;
    Island(int n, bool d): n(n), dir(d){
        p = vector<vector<int>>(n,vector<int>(n,0));
    }

    void addedge(int u, int v, int w){
        p[u][v] = w;
        if(!dir) p[v][u] = w;
    }

    bool isedge(int u, int v){
        if(p[u][v] == 0) return 0;
        return 1;
    }

    int extractmin(){
        int m = INT_MAX;
        int idx = -1;
        for(int i=0; i<n; i++){
            if(qu[i] == 1 && key[i] < m){
                m = key[i];
                idx = i;
            }
        }
        return idx;
    }

    void Prims(int src){
        qu = vector<int>(n, 1); // all are in queue
        key = vector<int>(n, INT_MAX);
        parent = vector<int>(n, -1);
        vector<char> ch = {'A', 'B', 'C', 'D', 'E', 'F'};
        key[src] = 0;

        for(int i=0; i<n; i++){
            int u = extractmin();
            qu[u] = 0;
            for(int v=0; v<n; v++){
                if(isedge(u, v)){
                    if(qu[v] == 1 && key[v] > p[u][v]){
                        key[v] = p[u][v];
                        parent[v] = u;
                    }
                }
                
            }
        }

        cout<<"Selected Bridge.... "<<endl;
        int cost = 0;
        for(int i=0; i<n; i++){
            if(i == src) continue;
            else{
                cout<<"("<<ch[parent[i]]<<","<<ch[i]<<") -->"<<key[i]<<endl;
                cost += key[i];
            }
        }
        cout<<"Total Cost : "<<cost<<endl;
    }
};

int main(){

    Island i(6, false);  // vertices 0..5
    i.addedge(0,1,3);
    i.addedge(0,2,7);
    i.addedge(0,3,6);
    i.addedge(0,5,8);
    i.addedge(1,5,7);
    i.addedge(1,4,5);
    i.addedge(1,3,7);
    i.addedge(2,3,2);
    i.addedge(2,4,3);
    i.addedge(3,4,1);
    i.addedge(4,5,4);
    i.Prims(0);  


    return 0;
}