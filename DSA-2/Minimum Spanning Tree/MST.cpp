#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Graph{
    int n;    //no of vertices
    vector< vector<int> > w; //to represent adjacency matrix
    bool directed;//directed->true, undirected->false
    vector<int> q, key, p;
public:
    Graph(int n, bool dir): n(n), directed(dir){
        w = vector< vector<int> > (n, vector<int>(n, 0));
    }
    void addEdge(int u, int v, int w1){
        w[u][v] = w1;
        if(!directed) w[v][u] = w1;
    }
    bool isEdge(int u, int v){
        if(w[u][v] != 0) return true;
        return false;
    }
    int ExtractMin(){
        int m = INT_MAX;
        int idx = -1;
        for(int i = 0; i<n; i++){
            if(q[i]==1 && key[i] < m){
                m = key[i];
                idx = i;
            }
        }
        return idx;
    }

    void MST_Prim(int r){
        //find the minimum spanning tree
        q = vector<int> (n, 1);
        key = vector<int> (n, INT_MAX);
        p = vector<int> (n, -1);
        key[r] = 0;

        for(int i = 1; i<=n; i++){
            int u = ExtractMin(); // key er min
            q[u] = 0; //u is no longer in the queue
            for(int v = 0; v<n; v++){
                if( isEdge(u, v) ){
                    //v is adjacent to u
                    if(q[v]==1 && w[u][v]<key[v]){
                        key[v] = w[u][v];
                        p[v] = u;
                    }
                }
            }
        }

        cout<<"Selected edges for MST:"<<endl;
        int cost = 0;
        for(int i =0 ;i<n;i++){
            if(i == r) continue;
            cout<<"("<<i<<", "<<p[i]<<")"<<"--->"<<key[i]<<endl;
            cost += key[i];
        }
        cout<<"Cost of MST:"<< cost<< endl;
    }
};
int main(){
    Graph g(5, false);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 4, 9);

    g.MST_Prim(0);
}
