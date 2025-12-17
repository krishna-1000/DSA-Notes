#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> Summeryrange(vector<int> arr)
{

    // {0,1,2,4,5,7}
    vector<vector<int>> outputarr;
    int j = 1;
    int i = 0;
    while (j < arr.size())
    {
        if (abs(arr[j] - arr[j - 1]) == 1)
        {
            j++;
        }
        else
        {
            int first = arr[i];
            int last = arr[j - 1];
            vector<int> temparr= {arr[i],arr[j-1]};
            outputarr.push_back(temparr);
            
            i = j;
            j++;
        }
    }
    return outputarr;
}

int main()
{

    vector<int> arr = {0, 1, 2, 4, 5, 7};

    vector<vector<int>> arr2 = Summeryrange(arr);
    for (int  i = 0; i < arr2.size(); i++)
    {
        arr2.at(i);
    }
   
    return 0;
}