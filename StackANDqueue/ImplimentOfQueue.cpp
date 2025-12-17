#include<iostream>
using namespace std;

// class MyQueue{

//     public:

//         int arr[4];
//         int start = -1;
//         int end = -1;
//         int size = 0;


//         void push_back(int value){

//             if(size == 3){
//                 cout<<"Queue over flow ";
//                 return;
//             }
//             if(start == -1 && end == -1){

//                 start = start +1;
//                 end = end+1;
//                 arr[end] = value;
//                 size =size+1;
//             }
//             else{
//                 end = (end+1 )% 4;
//                 arr[end] = value;
//                 size = size+1;
//             }
//         }
//         int TopValue(){
//             if(end>-1){

//                 return arr[end];
//             }
//             else{
//                 return -1;
//             }
//         }
//         void pop(){
//             if(size == 1){
//                 end = -1, start = -1;
//             }
//             if(size>1){
//                 start = (start+1 )% 4;
//                 size--;
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
class MyQueue{

    public:
    Node* Top = nullptr;
    Node* Tail;
    void push_back(int value){

        Node* temp = new Node(value);
        if(Top == nullptr){
            Top = temp;
            Tail = temp;
            
        }
        else{

            Tail->next = temp;
            Tail = temp;
        }
    }
    int TopValue(){
        return Top->data;
    }

    void POP(){
        
        Node* temp1 = Top;
        Top = Top->next;
        delete temp1;
    }
};

int main(){

MyQueue qt;

qt.push_back(1);
qt.push_back(10);
qt.push_back(44);
qt.POP();
qt.POP();

// qt.POP();


cout<<qt.TopValue();




    return 0;
}