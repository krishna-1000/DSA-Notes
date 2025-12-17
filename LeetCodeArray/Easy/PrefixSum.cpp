#include<iostream>
#include<vector>
using namespace std;
vector<int> leftRightDifference(vector<int>& arr) {
        
    vector<int> leftsum(arr.size());
    vector<int> rightsum(arr.size());
    vector<int> ans;
    int i = 0;
    int j = arr.size()-1;
    

    for(int i = 0; i<arr.size()-1;i++){
        if(i==0 && j == arr.size()-1 ){
            leftsum[i] = 0;
          
            rightsum[j] = 0;
            j--;
        }
        else{
            leftsum[i] = leftsum[i-1]+arr[i];
            rightsum[j] = arr[j+1]+arr[j];
            j--;
        }
    }

    for(int i = 0; i<leftsum.size()-1; i++){
        ans.push_back(abs(leftsum[i]-rightsum[i]));

    }
    for (int i = 0; i < leftsum.size()-1; i++)
    {
        cout<<leftsum[i]<<" ";
    }
    
    return ans;
}

int main(){



    vector<int> arr = {10,4,8,3};// [0,10,14,22]
    leftRightDifference(arr);


    
}