#include <iostream>
#include<vector>

using namespace std;

vector<int> AddOne (vector<int> arr){
    
    int carry = 0;
    int digit = 0;

    for (int i = arr.size()-1; i>=0; i--)
    {
        if(i == arr.size()-1){
            digit = arr[i]+1;
        }
        else{
            digit = arr[i]+carry;
        }
        carry = digit /10;
        digit = digit % 10;
        
        arr[i] = digit;

        if(i == 0 && carry != 0){
            arr.insert(arr.begin(),carry);
            carry = 0;
        }
        
        if(carry == 0){
            break;
        }
    }
    return arr;
    
}
int main()
{

     
vector<int> arr = {1,9,9}; //[1,2,3,4,5,9]

vector<int> arr2 = AddOne(arr);

for(int i : arr2){
    cout<<i;
}







    return 0;
}