#include<iostream>
using namespace std;

int main(){

    int arr[6] = {1,3,1,3,5,1};

    int hashArray[6] = {0};

    for (int i = 0; i < 6; i++)
    {
        hashArray[arr[i]] +=1;
    }

    cout<<hashArray[1];
    

    return 0;
}