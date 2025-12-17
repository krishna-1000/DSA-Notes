#include <iostream>
#include <stack>
using namespace std;

// class MyStack {

//     public:

//         int top = -1;
//        static const int size = 3;
//         int arr[size];
//         void push_back(int value){
//             if(size == top){
//                 cout<<"Stack is full";
//                 return;
//             }
//             top = top + 1;
//             arr[top] = value;
//         }

//         int TopElem(){
//             return arr[top];
//         }
//         void PopElem(){
//             if(top>-1){

//                 top = top - 1;
//             }
//             else{
//                 cout<<"stack is empty";
//             }
//         }
// };
class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
class MyStack
{

public:
    Node *top;

    Node *push_back(int value)
    {

        Node *temp = new Node(value);
       

            temp->next = top;
            top = temp;
        
    }

    int TopElem()
    {
        return top->data;
    }

    void PopElem()
    {
        Node *temp = top;
        top = top->next;

        delete temp;
        return;
    }
};
int main()
{

    MyStack st;
    st.push_back(3);
    st.push_back(1);
    


    cout << st.TopElem();

    return 0;
}