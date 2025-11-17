#include<iostream>
using namespace std;
#include<vector>
//directed weighted graph


int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    int u,v,weight;
    vector<pair<int,int> >AdjList[vertex];

    for (size_t i = 0; i < edges; i++)
    {
        cin>>u>>v>>weight;
        AdjList[u].push_back(make_pair(v,weight));
    }

    for (size_t i = 0; i < vertex; i++)
    {
        cout<<i<<" -> ";
        for (size_t j = 0; j < AdjList[i].size(); j++)
        {
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<", ";
        }
        cout<<endl;
    }


    return 0;
}