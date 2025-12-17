#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next, Node *prev)
    {
        data = data1;
        next = next;
        prev = prev;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *ConvertoDll(vector<int> &arr)
{

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

void PrintList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

Node *InsertAtHead(Node *head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}
Node *InsertAtTail(Node *head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    while (temp->next != NULL)
    {

        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}
Node *InsertAtAnyPosition(Node *head, int value, int position)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    int count = 1;
    if (position == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    while (temp->next != NULL)
    {
        if (count == position)
        {

            // temp->next->prev = newNode;
            // newNode->next = temp->next;
            // temp->next = newNode;
            // newNode->prev = temp;

            temp->prev->next = newNode;
            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev = newNode;
        }
        count++;
        temp = temp->next;
    }

    if (position - count == 1)
    {
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }

    return head;
}


Node* DeleteFromHead(Node* head){

    Node* temp = head;

    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}
Node* DeleteFromTail(Node* head){

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp ->prev->next = nullptr;
    temp ->prev = nullptr;

    delete temp;
    return head;
}
Node* DeleteFromAnyPostion(Node* head,int position){

    Node* temp = head;
    int count = 1;
   
  
    while (temp->next != NULL)
    {
        
        if(count == position){
            temp ->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            return head;
        }
        count++;
        temp = temp->next;
    }

    if(position == count){
        temp->prev->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
     }
    
    return head;
}

int main()
{

    vector<int> arr = {2, 4, 6, 8};
    Node *head = ConvertoDll(arr);
    // head = InsertAtAnyPosition(head, 300, 5);

    // head = DeleteFromHead(head);
    // head = DeleteFromTail(head);
    head = DeleteFromAnyPostion(head,4);
    PrintList(head);

    return 0;
}