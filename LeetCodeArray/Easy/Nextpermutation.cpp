#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextPermutation(vector<int> &arr)
{

    int i = 0;
    for (int k = 0; k < arr.size()-1; k++)
    {
        if(arr[k]>arr[i]){
            swap(arr[k],arr[i]);
        }
    }
    

    int j = arr.size() - 1;
    int size = arr.size();
    bool shorted = true;

    //{4,6,7,1,3,2};
    for (int i = 1; i <= size - 1; i++)
    {
        for (int j = i; j <= size - 1; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
                shorted = false;
            }
        }
    }
   
    if(shorted){
        return arr;
    }
   

    return arr;
}

int main()
{

    vector<int> arr = {2,3,1};
    vector<int> arr2 = nextPermutation(arr);

    for (int i = 0; i <= arr2.size() - 1; i++)
    {
        cout << arr2[i];
    }
    return 0;
}