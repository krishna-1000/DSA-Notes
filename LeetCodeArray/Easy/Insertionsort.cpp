#include<iostream>
#include<vector>
using namespace std;


 vector<int> insertionSort(vector<int>& nums) {

       for(int i = 1 ; i < nums.size(); i++){
        int j = i-1;
        while(j>=0){
            if(nums[j]> nums[j+1]){
                swap(nums[j],nums[j+1]);
                j--;
            }
            else{
                break;
            }
        }
       }
       return nums;
    

}

int main(){

    vector<int> nums = {7,4,1,5,3};

    vector<int> temparr = insertionSort(nums);

    for(int i : temparr){
        cout<<i<<" ";
    }




    return 0;
}