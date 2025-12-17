#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int maxi = *max_element(piles.begin(), piles.end());
    int low = 1;

    int minimumTime = INT32_MAX;

    while (low <= maxi)
    {

        int mid = (low + maxi) / 2;
        int hourSum = 0;
        
        for (int i = 0; i < piles.size(); i++)
        {
            // {30,11,23,4,20};

            double temp = piles[i] % mid;
            
            if(temp == 0){
                hourSum += piles[i] / mid;
            }
            else if(temp > 0 && temp < 1){
                hourSum += 1;
            }
            else{
                hourSum += (piles[i] / mid)+1;
            }
        }
        cout << mid << " -" << hourSum << endl;

        if (hourSum == h)
        {
            minimumTime = mid;
            maxi = mid - 1;
        }
        else if (hourSum > h)
        {

            low = mid + 1;
        }
        else
        {
            maxi = mid - 1;
            minimumTime = mid;
        }
    }
    return minimumTime;
}
int main()
{

    vector<int> arr = {30, 11, 23, 4, 20};
    int h = 5;
    cout << minEatingSpeed(arr, h);

    return 0;
}