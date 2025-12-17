#include <iostream>
#include<vector>

using namespace std;

int main()
{

     
vector<int> arr = {1,3,3,5,6,7,6,7,2}; //[1,2,3,4,5,9]
int removeElement  = 6;

int i = 0;
int j = arr.size()-1;

while (i<j)
{
    if(arr[i]==removeElement){
        swap(arr[i],arr[j]);
        j--;
    }
    i++;
}
for(int k : arr){
    cout<<k;
}





    return 0;
}