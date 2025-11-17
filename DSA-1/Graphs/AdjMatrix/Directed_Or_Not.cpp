#include<bits/stdc++.h>
using namespace std;
#include<vector>


int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    vector<vector<int> > AdJacent (vertex, vector<int>(vertex,0));

    int u,v;
    for (size_t i = 0; i < edges; i++)
    {
        cin>>u>>v;
        AdJacent[u][v] = 1;
        //AdJacent[v][u] = 1;
    }
    bool x = true;

    for (size_t i = 0; i < vertex; i++)
    {
        for (size_t j = 0; j < vertex; j++)
        {
            if(AdJacent[i][j] != AdJacent[j][i]) x = false;
            break;
        } 
    }

    (x)?cout<<"Undirected"<<endl:cout<<"Directed"<<endl;

    return 0;
}

/*
5 6
0 1
2 0
0 3
1 3
1 4
2 4


*/