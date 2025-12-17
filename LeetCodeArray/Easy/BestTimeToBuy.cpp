#include<vector>
#include<iostream>
using namespace std;


int Profit(vector<int> prices){

    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i+1; j < prices.size(); j++)
        {
            if(prices[j] > prices[i]){
                
                int tempProfit = abs(prices[j]-prices[i]);
                if(tempProfit> maxProfit){
                    maxProfit = tempProfit;
                }
            }
        }
        
    }
    
    return maxProfit;

}
int main(){

    vector<int> prices = {7,1,5,3,6,4};

    cout<<"Max profit = " << Profit(prices);

    return 0;
}
