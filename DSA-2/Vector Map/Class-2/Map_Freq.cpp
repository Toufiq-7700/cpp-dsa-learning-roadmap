#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


int main(){

    map<int, int> numbers;
    int arr[] = {5,1,21,6,5,16,21,5,1};

    for(int x : arr){
        numbers[x]++;
    }

    for(auto  x : numbers){
        cout<< x.first << " --> " << x.second <<endl;
    }


    return 0;
}

