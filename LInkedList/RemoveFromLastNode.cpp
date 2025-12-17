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
 
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for(int i = 1; i<arr.size();i++){
        ListNode* temp  = new ListNode(arr[i]);
        current->next = temp;
        current = temp;
    }

    return head;
}


class RemoveFromLast
{

public:

     ListNode* RemoveLastNode(ListNode* head, int NodeVal=4){
// {2,3,4,5,6}
        int count = 0;
        ListNode* fast = head;
        while (count != NodeVal)        
        {
            fast = fast->next;
            count++;

        }
        ListNode* slow = head;
        if(fast == NULL){
            ListNode* deleNode = slow;
            head = slow->next;
            delete(deleNode);
            return head;

        }

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* deleteNode = slow->next;
        
        slow->next = slow->next->next;
        delete(deleteNode);
        return head;
        
        
     }

};




int main(){


    vector<int> arr = {2,3,4,5,6};
    ListNode* head = ArrayTolist(arr);

    RemoveFromLast Rvs;
    ListNode* head1 = Rvs.RemoveLastNode(head);
    while (head1 != NULL)
    {
        cout<<head1->data<<"-> ";
        head1 = head1->next;
    }

    return 0;
}