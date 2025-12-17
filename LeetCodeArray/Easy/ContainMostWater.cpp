#include<iostream>
#include<vector>
using namespace std;

int ContainWater(vector<int> height){
    int mostwater = 0;
    int i = 0;
    int j = height.size()-1;
    while (i< j)
    {
        if(height[i]<height[j]){
            int water = height[i] * abs(j-i);
            if(water > mostwater) mostwater = water;
            i++;
        }
       else if(height[i]>height[j]){
            int water = height[j] * abs(j-i);
            if(water > mostwater) mostwater = water;
            j--;
        }
       else {
            int water = height[i] * abs(j-i);
            if(water > mostwater) mostwater = water;
            i++;
        }

    }
    

    return mostwater;
}

int main(){

    vector<int> height = {1,2,2,1};//{1,8,6,2,5,4,8,3,7}

   cout<<"Most contain water = "<< ContainWater(height);
}