#include<iostream>
#include<Map>
#include<unordered_map>
using namespace std;

int main(){

    map<int,string> map1 = {{3,"raj"},{2,"krshna"}};
// INSERTING DATA IN MAP
    map1[1] = "bro";
    map1.emplace(3,"ys");

    //UPDATWE DATA IN MAP

    map1.at(3) = "rajpal";
  
// FINDING DATA IN MAP

auto data  =  map1.find(1);

if(data != map1.end()){

    cout<<data->first;
    cout<<data->second;
}

//DELETING DATA FROMN THE MAP 

if(map1.at(2) == "krshna"){
    map1.erase(2);
}



    for(auto &i : map1){
        cout<<i.first<<" ";
        cout<<i.second;
        cout<<endl;
    }
    cout<<"done";



    return 0;
}