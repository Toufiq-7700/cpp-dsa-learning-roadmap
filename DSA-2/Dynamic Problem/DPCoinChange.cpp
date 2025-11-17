#include<bits/stdc++.h>
#include<vector>
using namespace std;

void DPCoinChange(vector<int> coins, int d, int M){
    //find the min # of coins required to change M amount
    int minCoins[M+1];
    int b[M+1];
    minCoins[0] = 0;

    for(int m = 1; m<=M; m++){
        minCoins[m] = INT_MAX;
        for(int i = 0; i < d; i++){
            if(m >= coins[i]){
                //we can take the coin
                if( 1+minCoins[ m-coins[i] ]  < minCoins[m] ){
                    minCoins[m] = 1+minCoins[ m-coins[i] ];
                    b[m] = coins[i];
                }
            }
        }
        cout<<minCoins[m] << " ";
    }
    cout<<endl;
    cout<<"Minimum coins:"<<minCoins[M]<<endl;
    cout<<"Chosen coins:";
    int i = M;
    while(i>0){
        cout<<b[i]<<", ";
        i = i - b[i];
    }
}

int main(){
    vector<int> coins = {1, 2, 6};
    int d = 3; //no of denominations
    int M = 11; //changed amount
    DPCoinChange(coins, d, M);

}
