#include <iostream>
#include <stack>
#include <vector>
#include<unordered_map>
using namespace std;

void GreaterElement(vector<int> arr)
{
    // {1,3,0,4,2,5}
    stack<int> st;
    int n = arr.size();
    int Nge[n];

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            Nge[i] = -1;
            st.push(arr[i]);
        }
        else if (arr[i] < st.top())
        {
            Nge[i] = st.top();
            st.push(arr[i]);
        }
        else if (arr[i] >= st.top())
        {
            while (!st.empty())
            {
                if (st.top() >= arr[i])
                {
                    if (st.top() == arr[i])
                    {
                        st.pop();
                    }
                    Nge[i] = st.top();
                    st.push(arr[i]);
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(st.empty()){
                Nge[i] = -1;
                st.push(arr[i]);
            }
        }
    }

    int i = 0;
    int s = sizeof(Nge) / sizeof(Nge[0]);
    while (i < s)
    {
        cout << Nge[i] << " ";
        i++;
    }
}

void GreaterElement2(vector<int> arr)
{
    //  0,1,2,3,4,5,6,7,8,9,10,11
    //{0,9,2,5,8,7}{0,9,2,5,8,7}
    stack<int> st;
    int n = arr.size();
    int Nge[n];

    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        if(i <= n-1){
            if(arr[i]<st.top()){
                Nge[i] = st.top();
                st.push(arr[i]);
            }
            else if (arr[i]>st.top())
            {
                while (!st.empty())
                {
                    st.pop();
                    if(arr[i]<st.top()){
                        Nge[i] = st.top();
                        st.push(arr[i]);
                        break;
                    }
                    else if(arr[i] == st.top()){
                        Nge[i] = -1;
                        st.push(arr[i]);
                        break;
                    }
                }
               
                
            }
            
        }
        else{
            int cur =  i % n;

            if(st.empty()){
                st.push(arr[cur]);
            }
            else if(arr[cur]>st.top()){
                st.pop();
                st.push(arr[cur]);
            }
        }
     
    }
    // cout<<st.top();

    // int n2 = sizeof(Nge)/sizeof(Nge[0]);
    // int i = 0;
    // while (i < 6)
    // {
    //    cout<<Nge[i]<<" ";
    //    i++;
    // }
    
}

void GreateElement3(vector<int> arr1,vector<int> arr2){
    
// {4,1,2} {1,3,4,2}
         //{3,4,-1,-1}

    stack<int> st;
    unordered_map<int,int> pairmap;
    
    int n = arr2.size();
    int Nge[n];
//{1,3,5,2}
    for (int i = n-1; i >= 0; i--)
    {
        pairmap.insert({arr2[i],i});
        if(st.empty()){
            st.push(arr2[i]);
            Nge[i] = -1;
        }
        if(arr2[i]<st.top()){
            Nge[i] = st.top();
            st.push(arr2[i]);
        }
        else if(arr2[i] > st.top()){

            while (!st.empty())
            {
                if(arr2[i]<st.top()){
                    Nge[i] = st.top();
                    st.push(arr2[i]);
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(st.empty()){
                Nge[i] = -1;
                st.push(arr2[i]);
            }
            
        }
    }

    int i = 0;
    while (i < 4)
    {
        cout<<Nge[i]<<" ";
        i++;
    }
    cout<<endl;
    for (auto i = pairmap.begin(); i != pairmap.end(); ++i){
        cout<<i->first<<" : "<<i->second<<endl;
    }
    cout<<endl;

    for (int i = 0; i < arr1.size(); i++)
    {
       int val =  arr1[i];
       int index = pairmap.at(val);
        cout<<Nge[index]<<" ";
    }
    
    


}
int main()
{

    vector<int> arr1 = {1,2}; //{9,-1,5,9,9}
    vector<int> arr2 = {1,3,5,2}; //{9,-1,5,9,9}

    // GreaterElement(arr2);
    GreateElement3(arr1,arr2);

    return 0;
}