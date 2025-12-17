#include <iostream>
#include <vector>
using namespace std;
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
Node *ArrayTolist(vector<int> &arr)
{

    Node *head = new Node(arr[0]);

    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void PrintOfLlist(Node *head)
{

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *insertAtFirst(Node *head, int value)
{

    Node *temp = new Node(value);

    temp->next = head;
    head = temp;
}
Node *insertAtLast(Node *head, int value)
{

    Node *temp = new Node(value);

    Node *mover = head;

    while (mover->next != NULL)
    {
        mover = mover->next;
    }
    mover->next = temp;

    return head;
}

Node* insertAtAnyPosition(Node* head,int value, int postion){

    Node* newNode = new Node(value);

    Node* temp = head;
    Node* prev;

    if(postion == 1){
        return new Node(value,head);
    }

    for (int i = 1; i < postion-1; i++)
    {
       
        temp = temp->next;

    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}


Node* DeleteFromFirst(Node* head){
    Node* temp = head;

    head = head->next;
    delete temp;
    return head;
}
Node* DeleteFromLast(Node* head){
    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
        
    }
    Node* deltemp = temp->next;

    
    temp->next = nullptr;
    delete deltemp;

    return head;
}

Node* DeleteFromAnyPostion(Node* head,int position){
    Node* temp = head;
    Node* pre;
    
    for (int i = 1; i < position; i++)
    {
        if(position-i == 1){
            pre = temp;
        }
        temp = temp->next;
    }
    if(position == 1){
        head = head->next;
        delete temp;
        return head;
    }
    pre->next = temp->next;
    delete temp;

    return head;
}



int main()
{

    vector<int> arr = {32, 2, 3, 4};

    Node *head = ArrayTolist(arr);

    // head = insertAtFirst(head, 20);
    head = insertAtLast(head, 90);
    head = insertAtAnyPosition(head, 11,2);
    // head = DeleteFromFirst(head);
    // head = DeleteFromLast(head);
    // head = DeleteFromAnyPostion(head,1);

    PrintOfLlist(head);
}