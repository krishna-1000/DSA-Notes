#include <iostream>
#include <stack>
#include<vector>
using namespace std;

void OuterMost(string s)
{
    stack<char> st;
    string resut = "";
    int coutnt = 0;
    for (int i = 0; i < s.size(); i++)
    { //(()(()))
        if(s[i] == '('){
            st.push(s[i]);
            coutnt++;
        }
        else if(s[i] == ')'){

            char temp = st.top();

            
            if(!st.empty()){
                if(coutnt>2){
                    resut += temp;
                    coutnt--;
                   
                }
                else if(coutnt>1){

                    resut += st.top();
                    resut += s[i];
                    coutnt--;
                }
                else{
                    resut += s[i];
                }
            st.pop();

            }
           
        }
    }
    cout<<resut;
    
   
    
}
int main()
{

     string s = "()()";

     OuterMost(s);
     

    return 0;
}