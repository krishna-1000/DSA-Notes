#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int MaxSumOfKsizeWindow(vector<int> arr, int k)
{
    int n = arr.size();

    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    int maxSum = sum;

    for (int j = k; j < n; j++)
    {
        sum = sum + arr[j] - arr[j - k];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int LongestSubString(string st)
{

    int n = st.length();
    unordered_set<char> hasSet;
    int start = 0;
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        auto insertOrnot = hasSet.insert(st[i]);

        if (insertOrnot.second == 1)
        {
            size = max(size, i - start + 1);
        }
        else
        {
            while (start < i)
            {
                if (st[start] == st[i])
                {
                    hasSet.erase(st[start]);
                }
                start++;
            }
            size = max(size, i - start + 1);
        }
    }

    return size;
}

vector<int> MaxOfEachSubarrayOfSizeK(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    int maxSum = arr[0];
    int start = 0;
    int end = 0;
    for (int i = 0; i < k; i++)
    {
        maxSum = max(maxSum, arr[i]);
    }

    ans.push_back(maxSum);

    for (int end = k; end < n; end++)
    {
        start++;
        if (arr[end] > maxSum)
        {
            maxSum = arr[end];
            ans.push_back(maxSum);
        }
        else
        {
            ans.push_back(maxSum);
        }
    }
    return ans;
}

vector<int> DistincCountInSubarrayOfSizeK(vector<int> arr, int k)
{
    int n = arr.size();
    int start = 0;
    vector<int> result;
    for (int start = 0; start <= n-k; start++)
    {
        unordered_set<int> hasset;
        for (int temp = start; temp < start+k ;temp++)
        {
         hasset.insert(arr[temp]);
          
        }
        result.push_back(hasset.size());
    }
    return result;
}

int main()
{

    // vector<int> arr= {1,24,3,4,5} ;
    // int result = MaxSumOfKsizeWindow(arr,3);

    // cout<<result;

    // cout << "Longest Substring = " << LongestSubString("abcbda");

    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};

    vector<int> ans = DistincCountInSubarrayOfSizeK(arr, 4);

    for (int it : ans)
    {
        cout << it << endl;
    }
    return 0;
}