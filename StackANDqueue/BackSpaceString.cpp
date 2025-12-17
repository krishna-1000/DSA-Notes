#include <iostream>
#include <stack>
#include<vector>
using namespace std;

void BackSpaceString(string s,string t)
{
    stack<int> st;
    string f1 = "";
    string f2 = "";

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '#'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    string first = "";
    while (!st.empty())
    {
        first += st.top();
        st.pop();
    }

    
    for (int i = 0; i < t.size(); i++)
    {
        if(t[i] == '#'){
            st.pop();
        }
        else{
            st.push(t[i]);
        }
    }
    
    string second = "";
    while (!st.empty())
    {
        second += st.top();
        st.pop();
    }

    cout<<first<<"  "<<second;
    
}
int main()
{

     string s = "a#c";
     string t = "t";

    BackSpaceString(s,t);
     

    return 0;
}