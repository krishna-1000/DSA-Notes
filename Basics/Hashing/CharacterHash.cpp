#include<iostream>
using namespace std;
// Hashmap of Character 
int main(){

   string str = "aabcaadb";


   int Hasharray[8] = {0};

   for (int i = 0; i < str.size(); i++)
   {
    Hasharray[str[i] - 'a'] +=1;
   }

  cout<<Hasharray[1];
   
   

    

    return 0;
}