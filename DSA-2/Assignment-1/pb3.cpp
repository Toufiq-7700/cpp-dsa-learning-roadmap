#include<bits/stdc++.h>
using namespace std;

class xx{
public:
    string name;
    int weight,bundle,retail,ratio;

    xx(string n,int w,int b,int r):name(n),weight(w), bundle(b), retail(r), ratio(r-(b/w)){}
};

bool com(xx x1, xx x2){
    return x1.ratio > x2.ratio;
}

void profit(vector<xx> item, int w){
    sort(item.begin(), item.end(), com);
    int total=0,i=0;
    while(w>0 && i<item.size()){
        if(item[i].weight <= w){
            total += (item[i].retail-(item[i].bundle/item[i].weight)) * item[i].weight;
            cout<<item[i].name<<endl;
            w -= item[i].weight;
        }
        else{
            int x = w;
            total += (item[i].retail-(item[i].bundle/item[i].weight)) * x;
            w-=x;
            cout<<item[i].name<<endl;
        }
        i++;
    }

    cout<<"Profit  "<<total<<endl;

}

int main(){
    vector<xx> items ={
        xx("Rice", 100, 4000, 55),
        xx("Sugar", 200, 9000, 62),
        xx("Wheat", 350, 7000, 30),
        xx("Onion", 250, 12000, 80),
    };
    int W=600;
    profit(items,W);


    return 0;
}