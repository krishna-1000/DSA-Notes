#include <iostream>
#include <math.h>
using namespace std;

bool ArmStrongcheck(int num)
{

    int count = 0;
    int orignal = num;
    int temp = num;
    int digit = 0;
    int armstrong = 0;
    while (temp > 0)
    {
        temp = temp / 10;
        count++;
    }
    while (num > 0)
    {
        digit = num % 10;
        armstrong += pow(digit, count);
        num = num / 10;
        cout << num << " " << armstrong << endl;
    }
    if (orignal == armstrong)
    {
        return true;
    }
    return false;
}

int main()
{
    int num;
    cin >> num;
    int res =  ArmStrongcheck(num);
    string show = res?"this is armstrong":"Not armstrong";
    cout<<show;

    return 0;
}