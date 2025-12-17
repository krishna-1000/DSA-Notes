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

class RemoveDuplicate{

    public:

        ListNode* RemoveDup(ListNode* head){

            if(head == NULL){
                return head;
            }
            if(head->next == NULL){
                return head;
            }
             ListNode* prev = head;
             ListNode* temp = head;

             while (temp != NULL)
             {
                if(prev->data != temp->data){
                    prev->next = temp;
                    prev = temp;
                }
                temp = temp->next;
             }

             prev->next = NULL;

             return head;
             
           
        }
};

int main(){

    vector<int> arr = {1};
    ListNode* head = ArrayTolist(arr);

    RemoveDuplicate Rvs;
    ListNode* head1 = Rvs.RemoveDup(head);
    while (head1 != NULL)
    {
        cout<<head1->data<<"-> ";
        head1 = head1->next;
    }
    






    return  0;
}