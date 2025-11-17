#include<bits/stdc++.h>
using namespace std;

class product{
public:
    string name;
    int weight;
    int wholesale;
    double ratio;
    int retail;

    product(string n, int w, int ws, int r):name(n), 
    weight(w), wholesale(ws), ratio((double)r - (double)ws/w), retail(r){}

};

bool Compare(product p1, product p2){
    return p1.ratio > p2.ratio;
}

void profit(vector<product> p, int w){
    //sort with the descending order, i want max profit so, the ratio set with the = retail - wholesale/weight
    sort(p.begin(), p.end(), Compare);
    // store the selected items that should buy
    //vector<product>selected;

    int i=0;
    double profit=0;
    while(w > 0 && i<p.size()){
        if(p[i].weight <= w){
            //selected.push_back(p[i]);
            profit += (p[i].retail - ((double)p[i].wholesale/p[i].weight))* p[i].weight;
            cout<<"Product : "<<p[i].name<<", Taken Weight of a Bundle(kg) : "<<p[i].weight<<", WholeSale Price of the Bundle : "<<p[i].wholesale<<", Retail Price : "<<p[i].retail<<endl;
            w -= p[i].weight;
        }
        else{
            int x=w;
            profit += (p[i].retail - ((double)p[i].wholesale/p[i].weight))* x; 
            cout<<"Product : "<<p[i].name<<", Taken Weight of a Bundle(kg) : "<< x <<", WholeSale Price of the bundle : "<<p[i].wholesale<<", Retail Price : "<<p[i].retail<<endl;
            w -= x;
        }
        i++;
    }

    cout<<endl;
    cout<<"Total Profit : "<<profit<<endl;

}


int main(){
    vector<product> items ={
        product("Rice", 100, 4000, 55),
        product("Sugar", 200, 9000, 62),
        product("Wheat", 350, 7000, 30),
        product("Onion", 250, 12000, 80),
    };
    int W=600;
    profit(items,W);


    return 0;
}