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

class AddTwoNumber{
    public:

        ListNode* SumOfTwoList(ListNode* head1,ListNode* head2){
            int carry = 0;
            ListNode* currHead1  = head1;
            ListNode* currHead2 = head2;
            ListNode* sumListHead = new ListNode(-1);
            ListNode* currSumList = sumListHead;

            while (currHead1 != NULL || currHead2 != NULL)
            {
                if(currHead1 != NULL && currHead2 != NULL){
                    int sum = currHead1->data + currHead2->data + carry;
                    ListNode* temp = new ListNode(sum%10);
                    carry = sum / 10 ;
                    currSumList->next = temp;
                    currSumList = temp;

                }
                if(currHead1 == NULL){
                    int sum =  currHead2->data + carry;
                    ListNode* temp = new ListNode(sum%10);
                    carry = sum / 10 ;
                    currSumList->next = temp;
                    currSumList = temp;
                }
                if(currHead2 == NULL){
                    int sum =  currHead1->data + carry;
                    ListNode* temp = new ListNode(sum%10);
                    carry = sum / 10 ;
                    currSumList->next = temp;
                    currSumList = temp;
                }

                if(currHead1 != NULL){currHead1 = currHead1->next;}
                if(currHead2 != NULL){currHead2 = currHead2->next;}
            }
            
            if(carry>0){
                ListNode* temp = new ListNode(carry);
               
                currSumList->next = temp;
                currSumList = temp;
            }

            return sumListHead->next;
        }
};




int main(){

    vector<int> arr1 = {9,9,9,9,9,9,9};
    vector<int> arr2 = {9,9,9,9};

    ListNode* head1 = ArrayTolist(arr1);
    ListNode* head2 = ArrayTolist(arr2);
    
    AddTwoNumber ATN;
    ListNode* head = ATN.SumOfTwoList(head1,head2);
    while (head != NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    

    return 0;
}