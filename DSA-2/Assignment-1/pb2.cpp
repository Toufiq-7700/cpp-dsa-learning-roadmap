#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class xx{
public:
    string name;
    int size;
    int sugar;
    double ratio;

    xx(string n, int s, int su): name(n), size(s), sugar(su), ratio(su/s){}

    void print(){
        cout<<"Name : "<<name<<", Bottle size : "<<size<<", Sugar : "<<sugar<<endl;
    }
};

bool Compare(xx e1, xx e2){
    return e1.ratio < e2.ratio;
}

void minimize(vector<xx> items, int w){
    //sort
    sort(items.begin(), items.end(), Compare);
    int taken = 0;
    int i=0;
    while(i<items.size() && w > 0){
        if(items[i].size <= w){
            taken += items[i].sugar;
            items[i].print();
            w -= items[i].size;
        }
        else{
            int x = w;
            double p = (x*items[i].ratio);
            taken += p;
            cout<<"Name : "<<items[i].name<<", Taken size : "<<x<<", Sugar : "<<p<<endl;
            w -= x;
        }
        i++;
    }
    cout<<"Total taken : "<<taken<<endl;
}


int main(){
    vector<xx> items = {xx("Galxose-D",3,75), xx("GlucoMax",4,80), xx("Sting",5,150)};
    int W = 6;

    minimize(items, W);


    return 0;
}