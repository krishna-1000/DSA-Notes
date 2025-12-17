#include <iostream>
using namespace std;
// Reverse a number
int main()
{
    int number ;
    cin>>number;

    cout<<"this is input = "<<number<<endl;

    int reverseNum = 0;
    while (number>0)
    {
       
        reverseNum = reverseNum*10+number%10;
        number = number/10;
    }
        cout<<reverseNum;
    

    return 0;
}
