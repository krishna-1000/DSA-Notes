#include <iostream>
using namespace std;

int main()
{

    int i = 0; 
    int arr[8] = {1,1,2,2,3,4,4,5}; //[1,2,3,4,5,9]

    for (int j = 1; j < 8; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i];
    }
    

    return 0;
}