#include <iostream>
using namespace std;

int SumOfDigit(int n)
{

    if (n == 0)
    {
        return n;
    }

    return SumOfDigit(n / 10) + n % 10;
    ;
}

int CountDigit(int n,int val=0){
   
    
    if(n == 0){
        return val;
    }
    CountDigit(n/10,val+1);
    
}

int main()
{

    int sum = SumOfDigit(123);
    int count = CountDigit(143523);
    cout << count;

    return 0;
}