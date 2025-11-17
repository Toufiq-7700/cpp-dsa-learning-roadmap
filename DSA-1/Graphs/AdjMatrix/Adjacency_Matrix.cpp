#include<bits/stdc++.h>
using namespace std;
#include<vector>

//Adjqacency Matrix 
//undirected unweighted graph


int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    vector<vector<bool> > AdJacent (vertex, vector<bool>(vertex,0));

    int u,v;
    for (size_t i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdJacent[u][v] = 1;
        AdJacent[v][u] = 1;
    }
    
    for (size_t i = 0; i < vertex; i++)
    {
        for (size_t j = 0; j < vertex; j++)
        {
            cout<<AdJacent[i][j]<<"  ";
        } 
        cout<<endl;  
    }


    return 0;
}