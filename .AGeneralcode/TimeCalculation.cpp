#include<iostream>
using namespace std;

string TimeAddition(string t1,string t2){

    string t3;

    string hour = t1.substr(0,1);
    string hour2 = t2.substr(0,1);
    string minute1 = t1.substr(2);
    string minute2 = t2.substr(2);
    
    cout<<sizeof(t3);
    return t3;
}

int main(){

string t1 = "1:30";
string t2 = "2:40";

TimeAddition(t1,t2);
// string t3 = t1.substr(0,1);
// cout<<t3;




    return 0;
}