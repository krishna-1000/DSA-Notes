#include <iostream>
#include <math.h>
using namespace std;

 int NthRoot(int N, int M) {
      int OriginalM = M;
       int temp = M/N;
       while(M>0){

        
        int temproot = pow(temp,N);

        if(temproot == OriginalM){ 
          return temproot;
        }
        
          M = temp;
          temp = M/N;
       }
       return -1;
    }

int main()
{

    cout << NthRoot(3, 27);

    return 0;
}