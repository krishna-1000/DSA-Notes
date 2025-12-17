#include <iostream>
#include <stack>
using namespace std;

bool valid(string s)
{

    stack<char> st;
    string temp = "";
    int i = 0;
    while (s[i])
    {
        //((()))
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (st.empty())
        {
            return false;
        }

        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            char temp = st.top();
            st.pop();
            if (s[i] == ')' && temp == '(' || s[i] == '}' && temp == '{' || s[i] == ']' && temp == '[')
            {
            }
            else
            {
                return false;
            }
        }
        i++;
    }
 

    return true;
}
int main()
{

    string s = "({(})";

    cout << valid(s);

    return 0;
}