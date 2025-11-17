#include<bits/stdc++.h>
using namespace std;
#define up 1
#define diagonal 2

void knapsack01(vector<string> name, vector<int> w, vector<int> v, int n, int W){
    //find max profit
    vector<vector<int>> p(n+1, vector<int>(W+1,0));
    vector<vector<int>> b(n+1, vector<int>(W+1,0));

    for(int i=0; i<=W; i++){
        p[0][i] = 0;
    }
    for(int i=0; i<=n; i++){
        p[i][0] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(w[i] > j){
                p[i][j] = p[i-1][j];
                b[i][j] = up;
            }
            else{
                if(v[i]+ p[i-1][j-w[i]] > p[i-1][j]){
                    p[i][j] = v[i]+p[i-1][j-w[i]];
                    b[i][j] = diagonal;
                }
                else{
                    p[i][j] = p[i-1][j];
                    b[i][j] = up;
                }
            }
        }
    }

    int profit = p[n][W];
    cout<< "Max Profit : " << profit <<endl ;

    cout<< "Selected Items....."<<endl;
    int i = n, j = W;
    while(i > 0 && W > 0){
        if(b[i][j] == diagonal){
            cout<< "Items name : "<< name[i] << ", Weight = " << w[i] << ", Value = "<< v[i] <<endl;
            j = j-w[i];
        }
        i--;
    }

}

int main(){
    vector<string> name = { " ", "Rice", "Sugar", "Onion", "Salt" };
    vector<int> w = {-1, 2, 1, 3, 2};
    vector<int> v = {-1, 12, 10, 20, 15};
    int n = 4; // no of items
    int W = 5; //knapsack capacity

    knapsack01(name, w, v, n, W);

    return 0;
}
