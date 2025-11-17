#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Graph{
    int n;    //no of vertices
    vector< vector<int> > w; //to represent adjacency matrix
    bool directed;//directed->true, undirected->false
    vector<int> q, d, p;
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
            if( q[i]==1 && d[i] < m){
                m = d[i];
                idx = i;
            }
        }
        return idx;
    }

    void Dijkstra(int src){
        //find the shortest path from src to all other vertices
        q = vector<int> (n, 1);
        d = vector<int> (n, INT_MAX);
        p = vector<int> (n, -1);
        d[src] = 0;

        for(int i = 1; i<=n; i++){
            int u = ExtractMin();
            q[u] = 0; //u is no longer in the queue
            for(int v = 0; v<n; v++){
                if( isEdge(u, v) ){
                    //v is adjacent to u
                    if(d[u]+w[u][v] < d[v]){
                        d[v] = d[u] + w[u][v];
                        p[v] = u;
                    }
                }
            }
        }
    }
    void printPath(int d){
        if(d == -1) return;
        printPath(p[d]);
        cout<<d<<"-->";
    }

    void findPath(int s, int dest){
        Dijkstra(s);
        cout<<"distance from "<<s<<" to "<<dest<<", Cost--->>"<<d[dest]<<endl;
        printPath(dest);

    }
};
int main(){
    Graph g(5, true);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 6);
    g.findPath(0, 3);
}

