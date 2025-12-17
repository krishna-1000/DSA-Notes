#include <iostream>
#include <vector>
using namespace std;

bool SortedArray(vector<int> arr, int n, int left = 0, int right = 1)
{

    if (right > n - 1)
    {
        return true;
    }
    // {1,8,3,4}
    if (arr[left] <= arr[right])
    {
        return SortedArray(arr, n, left + 1, right + 1);
    }
    else
    {
        return false;
    }
}

int MinOfArray(vector<int> arr, int n, int curr = 0, int min = 0)
{
    if(curr == 0 ){
        min = arr[0];
        curr = curr +1;
    }
    if (curr > n - 1)
    {
        return min;
    }
    if (arr[curr] < min)
    {
        min = arr[curr];
    }

    return MinOfArray(arr, n, curr + 1, min);
}

int sumOfArrayElemnts(vector<int> arr,int n ,int curr = 0,int sum = 0 ){
    if(curr>n-1){
        return sum;
    }

    sum += arr[curr];
    return sumOfArrayElemnts(arr,n,curr+1,sum);
}
int main()
{

    vector<int> arr = {31,5, 0};

    // string st = SortedArray(arr,4) ? "sorted" : "Not sorted";

    // cout<<st;
    // int min = MinOfArray(arr, 3);
    // cout << min;

    cout<<"the sum is "<<sumOfArrayElemnts(arr,3);
    return 0;
}