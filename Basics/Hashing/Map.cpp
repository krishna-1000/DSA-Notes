#include<iostream>
#include<Map>
#include<unordered_map>
using namespace std;

//HASH Map using map and unorderd map
int main(){

    int arr[12] = {1,3,1,1,3,5,6,5};
    string str = "aBcaBda";

    map<int,int> mp;
    map<char,int>map2;

    for (int  i = 0; i < 12; i++)
    {
        mp[arr[i]]+=1;
    }

    for (int i = 0; i < str.size(); i++)
    {
        map2[str[i]]++;
    }
    
   
    
    // char c = 'B';
    // // cout<<mp[1];

    // cout<<map2[c];
    



    return 0;
}