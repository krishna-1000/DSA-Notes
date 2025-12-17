#include<iostream>
using namespace std;


int main(){

    string str = "AcaAc";

    int hassArray[256] ={0};

    for(int i = 0 ;i<str.size();i++){
        hassArray[str[i]]++;
    }
        char c = 'A';
    cout<<hassArray[c];

    return 0;
}