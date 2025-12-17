#include<iostream>
#include<vector>
using namespace std;

int TotalTimeInWateringPlant(vector<int> plants,int A, int B){

    int totaltime = 0;
    int i = 0;
    int j = plants.size()-1;
    int originalA = A;
    int originalB = B;
    //[2,2,3,3]
    //{2,2,5,2,2} 5 5
    while (i<=j)
    {

       if(i == j){
         if(max(A,B)<plants[i]) totaltime += 1;
       }else{
        if(plants[i]<= A){
            A -= plants[i];
            i++;
        }
        else{
            totaltime += 1; 
            A = originalA;
           
        }
        
        if(plants[j] <= B){
            B = plants[j];
            j--;
        }
        else{
            totaltime += 1; 
            B = originalB;
            
        }
    }
        
    }
    return totaltime;

}

int main(){
vector<int> arr = {2,2,3,3};
    cout<<TotalTimeInWateringPlant(arr,5,5);

    return 0;
}