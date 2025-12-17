#include <iostream>
using namespace std;
// count the number of digit
int main()
{
   long long int digit;
    cin >> digit;
    int counter = 0;
    while (digit > 0)
    {
        counter = counter+1;
        digit = digit/10;
        cout<<digit<<endl;

    }
    cout<<"the size of digit = " <<counter;

    return 0;
}
