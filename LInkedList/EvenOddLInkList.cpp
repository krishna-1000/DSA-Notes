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


class OddEven{
    public:

        ListNode* GetOddEven(ListNode* head){
            ListNode* current = head;
            ListNode* Oddhead = new ListNode(-1); 
            ListNode* currOdd = Oddhead;
            ListNode* Evenhead = new ListNode(-1);
            ListNode* currEven = Evenhead;

            while (current != NULL)
            {
                if((current->data)%2 != 0){
                    ListNode* temp = new ListNode(current->data);
                    currOdd->next = temp;
                    currOdd = temp;
                }
                if((current->data)%2 == 0){
                    ListNode* temp = new ListNode(current->data);
                    currEven->next = temp;
                    currEven = temp;
                }
                current  = current->next;
            }
            ListNode * temp1 = Oddhead;
            Oddhead = Oddhead->next;
            ListNode * temp2 = Evenhead;
            Evenhead = Evenhead->next;
            delete temp1;
            delete temp2;
            currOdd->next = Evenhead;

            return Oddhead;
            

        }
};

class FastSLow{
    public:

    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        int check = 0;
//  {1,2,3,4,5}
        while(fast != NULL && fast->next != NULL){
            slow = slow ->next;
            fast = fast->next->next;
            check = check+1;
        }
          if(check%2 != 0){

                return slow;
            }
            if(check%2 == 0){
                 return slow->next;
            }
        return head;
    }
};

class RemoveELem {
    public:
        ListNode* removeElements(ListNode* head, int val) {
            ListNode* DummyListHead = new ListNode(-1);
            ListNode* current = DummyListHead;
    
            while(head != NULL){
                if(head->data != val){
                    cout<<"aya ";
                    ListNode* temp = new ListNode(head->data);
                    current->next = temp;
                    current = temp;
    
                }
                head = head->next;
            }
    
            return DummyListHead->next;
        }
    };

int main(){

    vector<int> arr = {1,2,6,3,4,5,6};

    ListNode* head = ArrayTolist(arr);
    
    // OddEven OE;
    // ListNode* head1 = OE.GetOddEven(head);
    // FastSLow Fs;
    // ListNode* head1 = Fs.middleNode(head);
    RemoveELem RE;

    ListNode * head1 = RE.removeElements(head,6);

    while (head1 != NULL)
    {
        cout<<head1->data<<"->";
        head1 = head1->next;
    }
    

    return 0;
}