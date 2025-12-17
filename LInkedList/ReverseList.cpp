#include<iostream>
#include<vector>
using namespace std;

class ListNode{
    public:

        int data ;
        ListNode* next ;

        ListNode(int data1,ListNode* next1){
            data = data1;
            next = next1;
        }
        ListNode(int data1){
            data = data1;
            next = nullptr;
        }

    
};

ListNode*  ArrayTolist(vector<int> arr){
    if(arr.empty()){
         ListNode* head = NULL;
         return head;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for(int i = 1; i<arr.size();i++){
        ListNode* temp  = new ListNode(arr[i]);
        current->next = temp;
        current = temp;
    }

    return head;
}

class ReverseLinkedList{

    public:

        ListNode* ReversedList(ListNode* head){

            ListNode* prev = NULL;
            if(head->next == NULL || head == NULL){
                return head;
            }
            ListNode* temp = head;
            ListNode* front = temp->next;

            while (front->next != NULL)
            {
                temp->next=prev;
                prev = temp;
                temp = front;
                front = front->next;

            }
            if(front->next == NULL){
                front->next = temp;
                temp->next = prev;
            }
           
            return front;
        }
};

int main(){

    vector<int> arr = {1,2,3,4,5};
    ListNode* head = ArrayTolist(arr);

    ReverseLinkedList Rvs;
    ListNode* head1 = Rvs.ReversedList(head);
    while (head1 != NULL)
    {
        cout<<head1->data<<"-> ";
        head1 = head1->next;
    }
    






    return  0;
}