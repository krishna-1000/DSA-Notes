#include <iostream>
using namespace std;
// Check Pelindrom

// Check Pelindrom
int ReverseNumber(int num)
{
    int reverseNum = 0;
    while (num > 0)
    {

        reverseNum = reverseNum * 10 + num % 10;
        num = num / 10;
    }
    return reverseNum;
}
int main()
{
    int number;
    cin >> number;

    if (number == ReverseNumber(number))
    {
        cout << "this is palindrom numner" << endl;
    }
    else
    {
        cout << "this is not palindrom" << endl;
    }

    return 0;
}
