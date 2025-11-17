#include<bits/stdc++.h>
using namespace std;
#define diogonal 1
#define up 2

void Rod_cutting(vector<int> len, vector<int> price, int l){
    int m = len.size();
    int n = price.size();
    vector<int> dp(l+1, 0);
    vector<int> cut(l+1, 0);

    for(int i=1; i<=l; i++){
        for(int j=0; j<m; j++){
            if(i >= len[j]){
                if(dp[i] < price[j]+dp[i-len[j]]){
                    dp[i] = price[j]+dp[i-len[j]];
                    cut[i] = len[j];
                }
            }
            else break;
        }
    }
    cout<<"For size of "<<l<<" Maximum Profit is : "<<dp[l]<<endl;
    cout<<"Selected size of length is : ";
    int i=l;
    while (i > 0){
        cout<<cut[i]<<", ";
        i -= cut[i];
    }
}

int main(){
    vector<int> len = {1, 3, 4, 5, 7, 8};
    vector<int> price = {2, 8, 9, 10, 20, 22};
    int n;
    cin>> n;

    Rod_cutting(len, price, n);

    return 0;
}
