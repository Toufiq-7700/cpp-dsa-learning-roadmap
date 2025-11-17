#include<iostream>
using namespace std;
#include<vector>
//Undirected unweighted graph


int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    int u,v;
    vector<int>AdjList[vertex];

    for (size_t i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    for (size_t i = 0; i < vertex; i++)
    {
        cout<<i<<" -> ";
        for (size_t j = 0; j < AdjList[i].size(); j++)
        {
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}