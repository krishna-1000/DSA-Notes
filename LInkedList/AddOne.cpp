#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data1, ListNode *next1)
    {
        data = data1;
        next = next1;
    }
    ListNode(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

ListNode *ArrayTolist(vector<int> arr)
{

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        current->next = temp;
        current = temp;
    }

    return head;
}

class AddOneTwoList
{

public:
    ListNode *AddOne(ListNode *head, int val)
    {
       
         int digit = 0;

         ListNode* temp = head;
         while (temp != NULL)
         {
            digit*=10;
            digit += (temp->data);
            
            temp = temp->next;
         }

         digit = digit+val;
         ListNode* dummy = new ListNode(-1);
         while (digit)
         {
            int nodeval = digit%10;
            digit = digit/10;

            ListNode* newNode = new ListNode(nodeval);
            newNode->next = dummy;
            dummy = newNode;
            if(dummy->next->data == -1){
                ListNode* delenod = dummy->next;
                dummy->next = NULL;
                delete(delenod);
            }

         }

         return dummy;
         
         
    }
};

int main()
{

    vector<int> arr = {2, 6,5,7,8};
    ListNode *head = ArrayTolist(arr);

    AddOneTwoList add;
    ListNode *head1 = add.AddOne(head,33);
    while (head1 != NULL)
    {
        cout << head1->data << "-> ";
        head1 = head1->next;
    }

    return 0;
}