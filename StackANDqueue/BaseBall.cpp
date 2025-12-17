#include <iostream>
#include <stack>
#include<vector>
using namespace std;

void BaseBall(vector<char> arr)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]=='C'){

            st.pop();
        }
        else if (arr[i] == 'D')
        {
            int val = st.top();
            st.push(val*2);
        }
        else if (arr[i] == '+')
        {
            int temp = st.top();
            st.pop();
            int sum = temp + st.top();
            st.push(temp);
            st.push(sum);
        }
        else{
            st.push(arr[i]-'0');
        }
        
    }

int total = 0;
while (!st.empty())
{
    cout<<st.top()<<" ";
    total += st.top();
    st.pop();
}

cout<<endl<<"the Total is = "<<total;

    
    

}
int main()
{

    // string s = "({(})";
    vector<char> arr = {'2','5','C','5','D','+'};

    BaseBall(arr);
     

    return 0;
}