#include <iostream>
using namespace std;



int powerOfNumber(int n,int power,int ans = 1){
   
    if(power == 0){
        return ans;
    }
    
    ans *= n;

   return powerOfNumber(n,power-1,ans);
    
}
void printNumberFromOneToN(int n, int i = 1){
    if(i == n+1){
        return;
    }

    cout<<i<<endl;
    return printNumberFromOneToN(n,i+1);
}
int printNumberFromNToOne(int n){
    if(n == 0){
        return n;
    }

    cout<<n<<endl;
    return printNumberFromNToOne(n-1);
}
int sumOfNaturalNumber(int n,int sum = 0){
    if(n == 0){
        return sum;
    }
    sum += n;
    sumOfNaturalNumber(n-1,sum); 
}
 int main()
{

    // int n = 2;
    // int power = 6; 

    // cout<<"the ans is = "<<powerOfNumber(n,power);

    // printNumberFromOneToN(10);
    // printNumberFromNToOne(10);
    cout<<"the sum is = "<<sumOfNaturalNumber(3);

    return 0;
}