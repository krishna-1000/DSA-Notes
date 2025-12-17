#include <iostream>
#include<vector>

using namespace std;

int search (vector<int> arr,int target){
    int start = 0;
    int end = arr.size()-1;
    int mid = (start+end)/2;
    
    while (start <= end)
    {
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target){
            end = mid-1;
        }
        else if(arr[mid]<target){
            start = mid + 1;
        }
    
        if(start == end){
            if(arr[mid]<target) return start+1;
            else if(arr[mid]> target) return start-1;
        }
        mid = (start+end)/2;
    }
    
}
int main()
{

     
vector<int> arr = {1,2,4,7,9}; //[1,2,3,4,5,9]
int target  = 10;

cout<<search(arr,target);







    return 0;
}