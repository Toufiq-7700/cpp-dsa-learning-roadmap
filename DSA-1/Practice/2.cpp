#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

struct Product
{
   int w;
   int p;
};


int main(){
    int n;
    cin>>n;

    Product pp[10];
    for (size_t i = 0; i < n; i++)
    {
        cin>>pp[i].w>>pp[i].p;
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n-1; j++)
        {
            if (pp[j].w < pp[j+1].w)
            {
                Product temp = pp[j];
                pp[j] = pp[j+1];
                pp[j+1] = temp;
            }
            
        }
        
    }
    
    cout<<"Descending the weight "<<endl;
    for (size_t i = 0; i < n; i++)
    {
        cout<<pp[i].w<<" "<<pp[i].p<<endl;
    }
    
   



    return 0;
}