#include<iostream>
#include<unordered_map>
using namespace std;


int main(){

    int arr[10] = {2,4,2,3,2,2,2,2,2,2};
    int n = 10;

    unordered_map<int,int> map;

    for (int  i = 0; i < 10; i++)
    {
        map[arr[i]] += 1;
    }
    
    for(auto &i : map){
        cout<<i.first<<" ";
        cout<<i.second<<endl;
    }


    return 0;
}