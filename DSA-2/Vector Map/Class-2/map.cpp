#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    vector<int> arr = {5, 1, 21, 6, 5, 16, 21, 5, 1};
    map<int, int> numbers;
    for(auto x : arr){
        numbers[x]++;
    }
    for(auto y : numbers)
        cout << y.first << "-->" << y.second << endl;
}
