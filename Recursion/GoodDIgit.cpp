#include<iostream>
using namespace std;

void func(int n ,int start,int &count , int &even, int &odd ){

    if(n == 0){
        cout<<"aya";
        count = count+1;
        return;
    }

    for (int i = start; i < n; i++)
    {
        if(i%2 == 0){
            for (int j = even; j <= 8; j=j+2)
            {
                even = even+2;
                func(n-1, start+1, count ,  even, odd );
            }
            
        }
        else if(i%2!=0){
            for (int k = odd; k <=7;k++)
            {
                if((k%2 != 0) || (k == 2)){
                    odd = odd+1;
                    func(n-1, start+1, count ,  even, odd);
                    
                }
            }
            
        }
    }
   return;
}


// void func(int n,int start,int &even){

//     if(n== 0){
//         return;
//     }

//     for (int i = start; i < n; i++)
//     {
//         for(int j = even ; j<=8 ; j=j+2){
//             cout<<start<<even<<endl;
//             even = even+2;
//             func(n-1,start+1,even);
//         }
//     }
//     return;
// }

int main(){
    int even = 0;
    int count = 0;
    int odd = 2;
    func(2,0,count,even,odd);
    cout<<count;
    return 0;
}