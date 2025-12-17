#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int missingNumber(vector<int> arr){
    int missing = 0;
    // {0,1,3}
    int i = 1;
    sort(arr.begin(),arr.end());
    while (i<=arr.size())
    {
        if(arr.size() == 1){
            return arr[0];
        }
        if(abs(arr[i-1]-arr[i]) > 1){
            
            return arr[i-1]+1;
        }
        else if(i == arr.size()-1){
         
            return arr[i]+1;
        }
        else{
            i++;
        }
    }
    
    return missing;
}

int main(){

    vector<int> arr = {1,0,3,2};
    cout<<missingNumber(arr);


    return 0;
}