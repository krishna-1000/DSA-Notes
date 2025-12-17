#include <iostream>
#include<vector>
using namespace std;


bool Palindrom(vector<int> arr,int n,int left = 0,int right = 0){
   
    if(left == 0 && right == 0){
        right = n-1;

    }
    if(left >= right){
        return true;
    }
    if(arr[left] == arr[right]){
        
        return Palindrom(arr,n,left+1,right-1);
    }
    else{

        return false;
    }
    
}

int main()
{

    vector<int> arr = {4,1,2,1,4};
    // bool result = Palindrom(arr,5);
    cout << Palindrom(arr,5);

    return 0;
}