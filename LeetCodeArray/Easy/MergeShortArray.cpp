#include <iostream>
#include <vector>

using namespace std;

vector<int> MergeShort(vector<int> arr, vector<int> arr2)
{

    int i = 0;
    int j = 0;
    while (i <= arr.size() - 1)
    {
        if (arr[i]>arr2[j]){
            swap(arr[i],arr2[j]);
            
        }
        if(arr[i] == 0){
            
            swap(arr[i],arr2[j]);
            j++;
        }
        i++;
    }
    return arr;
}
int main()
{

    vector<int> arr = {1, 2, 3, 0, 0};
    vector<int> arr2 = {2,32};

    vector<int> arr3 = MergeShort(arr, arr2);

    for (int i : arr3)
    {
        cout << i;
    }

    return 0;
}