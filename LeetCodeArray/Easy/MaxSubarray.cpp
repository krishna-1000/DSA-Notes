#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// int maxsum(vector<int> &nums , int k){

//     int sum = 0;
//     int length = 0;
//     int n = nums.size();

//     unordered_map<int,int> map1;
//     for (int i = 0; i < n; i++)
//     {
//         sum += nums[i];
//         map1.insert({sum,i});
//         int tempfind = sum - k; 
//         auto it = map1.find(tempfind);

//         if(it != map1.end()){

//             int templength = i - (it->second);

//             length = max(templength,length);


//         }

//     }
//     return length;
    
// }

int maxsum(vector<int> &nums,int k){

    int maxlenth = 0;
    int sum = nums[0];
    int i = 0;
    int j = 0;
    int n = nums.size();
    // while (i  < n-1)
    // {
    //     if(sum <= k){
    //         if(sum == k){
    //             maxlenth = max(maxlenth,j-i+1 );
    //         }
    //         sum+=nums[j];
    //         j++;
    //     }
    //     else if(sum > k){
    //         sum -= nums[i];
    //         i++;
    //     }

    // }

    while (j < n)
    {
        while (sum > k && i <= j)
        {
     
            sum-=nums[i];
            i++;
        }
        if(sum == k){
        
            maxlenth = max(maxlenth,j-i+1);
           
        }
        j++;
        if(j < n){
           
            sum += nums[j];
            
        }

        
    }


    return maxlenth;

}
int main(){

 vector<int> arr = {1,2,3,1,1,1,1};
 int k = 3;
cout<< maxsum(arr,k);


    return 0;
}