#include <iostream>
#include<vector>
using namespace std;


string ReverseString(string s,int n,int left = 0,int right = 0){
   
    if(left == 0 && right == 0){
        right = n-1;

    }
    if(left >= right){
        return s;
    }
   
    swap(s[left],s[right]);
   return ReverseString(s,n,left+1,right-1);
    
}

int main()
{

    string s = "Hello krihsna  ";

   cout<<ReverseString(s,s.length());


    return 0;
}