#include<bits/stdc++.h>
using namespace std;

class hill{
public:
    string name;
    int size;
    double value;
    double ratio;
    hill(string n, int s, double v):name(n),size(s),value(v),ratio(v/s){
    }
};

bool Compare(hill obj1, hill obj2){
    return obj1.ratio < obj2.ratio;
}

void minimize(vector<hill> items, int W){
    sort(items.begin(), items.end(), Compare);
    double consume=0;
    int i=0;
    cout<<"Selected Items That I can Consume : "<<endl;
    while(W > 0 && i<items.size()){
        if(items[i].size <= W){
            consume += items[i].value;
            W -= items[i].size;
            cout<<"Drinks Type : "<<items[i].name<<", Amount : "<<items[i].size<<"L."<<endl;
        }
        else{
            int x = W;
            double cons = (x*items[i].ratio);
            consume += cons;
            cout<<"Drinks Type : "<<items[i].name<< ", Amount : "<<x<<"L."<<endl;
            W -= x;
        }
        i++;
    }
    cout<<endl;
    cout<<"Minimum glucose level I have to consume : "<<consume<<"gm."<<endl;
}


int main(){
    vector<hill> items = {hill("Galxose-D",3,75), hill("GlucoMax",4,80), hill("Sting",5,150)};
    int W=6;
    minimize(items,W);

    return 0;
}

