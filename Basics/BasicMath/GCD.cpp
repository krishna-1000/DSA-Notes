#include <iostream>
using namespace std;
// Greatest Common Adviser The largest number which can devide both the bumber

// Check Pelindrom
int GCD(int num1, int num2)
{
    int size;
    int gcd;
    if (num1 > num2)
    {
        size = num2;
    }
    else
    {
        size = num1;
    }
    for (int i = 1; i <= size; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}
int GCDOtherApproach(int num1, int num2){

    while (num1>0 && num2>0)
    {
        if(num1>num2){
            num1 = num1%num2;
        }
        if(num2>num1){
            num2 = num2%num1;
        }

        if(num1 == 0){
            return num2;
        }
        return num1;
    }
    
}
int main()

{
    int num1, num2;
    cin >> num1;
    cin >> num2;

    cout << GCDOtherApproach(num1, num2);

    return 0;
}
