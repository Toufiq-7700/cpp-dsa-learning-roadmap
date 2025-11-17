#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Graph{
    int n;   
    vector< vector<int> > w;
    bool directed; 
    vector<int> q, d, p;

public:
    Graph(int n, bool dir): n(n), directed(dir){
        w = vector< vector<int> > (n, vector<int>(n, 0));
    }

    void addedge(int u, int v, int w1){
        w[u][v] = w1;
        if(!directed) w[v][u] = w1;
    }

    bool isEdge(int u, int v){
        return w[u][v] != 0;
    }

    int ExtractMin(){
        int m = INT_MAX;
        int idx = -1;
        for(int i = 0; i<n; i++){
            if(q[i]==1 && d[i] < m){
                m = d[i];
                idx = i;
            }
        }
        return idx;
    }

    void Dijkstra(int src){
        q = vector<int> (n, 1);
        d = vector<int> (n, INT_MAX);
        p = vector<int> (n, -1);
        d[src] = 0;

        for(int i = 1; i<=n; i++){
            int u = ExtractMin();
            if(u == -1) break;
            q[u] = 0;
            for(int v = 0; v<n; v++){
                if(isEdge(u, v)){
                    if(d[u] + w[u][v] < d[v]){
                        d[v] = d[u] + w[u][v];
                        p[v] = u;
                    }
                }
            }
        }
    }

    void printPath(int dest){
        if(dest == -1) return;
        printPath(p[dest]);
        cout << dest << "-->";
    }

    void findPath(int s, int dest){
        Dijkstra(s);
        cout<<"Distance from "<<s<<" to "<<dest<<" --> "<<d[dest]<<endl;
        printPath(dest);
    }

    void findPath(int s, int gas, int dest){
        Dijkstra(s);
        int dist1 = d[gas];
        vector<int> parent1 = p;

        Dijkstra(gas);
        int dist2 = d[dest];
        vector<int> parent2 = p;
        cout<<"Distance from "<<s<<" to "<<dest<<" along gas station "<<gas<<" --> " << dist1+dist2 << endl;
        print(gas, parent1);
        cout<<endl;
        print(dest, parent2, gas);
    }
    void print(int node, vector<int> &parent, int skip = -1){
        if(node == -1 || node == skip) return;
        print(parent[node], parent, skip);
        cout << node << "-->";
    }
};

int main(){
    Graph i(6, true);

    //addedge(.....)
    //addedge(.....)
    
    i.findPath(0, 4); // S --> D
    i.findPath(0, 3, 6); // s --> G --> D
    

    return 0;
}
