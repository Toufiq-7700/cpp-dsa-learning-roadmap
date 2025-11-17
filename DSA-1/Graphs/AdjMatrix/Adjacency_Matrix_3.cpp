#include<bits/stdc++.h>
using namespace std;
#include<vector>

//Adjqacency Matrix 
//directed weighted graph


int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    vector<vector<int> > AdJacent (vertex, vector<int>(vertex,0));

    int u,v,weight;
    for (size_t i = 0; i < edges; i++)
    {
        cin>>u>>v>>weight;
        AdJacent[u][v] = weight;
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