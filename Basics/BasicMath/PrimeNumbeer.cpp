#include<iostream>
using namespace std;

void checkPrime(int num){
int count = 0;
    for (int i = 1; i <= num; i++)
    {
        if(num%i == 0){
            count = count+1;
        }

    }
    if(count>2){
        cout<<"This is not prime number";
    }
    else{
        cout<<"this is PRIME";
    }
    
}
int main(){

checkPrime(7);


    return 0;
}