#include<iostream>
#include<vector>
#include<stack>
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

class Palindrom{

    public:
// signed integer overflow error on leetcode
        // bool CheckPalindrom(ListNode* head){

        //     stack<int> st;
        //     int digit1 = 0;
        //     int digit2 = 0;
        //     ListNode* temp = head;
            
        //     while (temp!=NULL)
        //     {
        //         st.push(temp->data);
        //         digit1 *= 10;
        //         digit1 += (temp->data);
        //         temp = temp->next;
        //     }

        //     int dummydigit = digit1;
        //     int size = st.size();
        //     for(int i = 0; i<size;i++){
        //         digit2 *= 10;
        //         digit2 += (st.top());
        //         cout<<st.top();
        //         st.pop();
        //     }
        //     // cout<<st.top();
        //     // st.pop();
        //     // cout<<endl<<st.top();
        //     // st.pop();
        //     // cout<<endl<<st.top();
        //     // while (dummydigit)
        //     // {
        //     //     digit2 *= 10;
        //     //     digit2 += dummydigit%10;
        //     //     dummydigit = dummydigit/10;

        //     // }
            
        //     // cout<<digit1<<endl<<digit2<<endl;
        //     if(digit1 == digit2){
        //         return true;
        //     }
        //     return false;

        // }

        bool CheckByOtherMethod(ListNode* head){

            stack<int> st;

            ListNode* temp = head;

            while (temp!= NULL)
            {
                st.push(temp->data);
                temp = temp->next;
            }
            
            while (head != NULL)
            {
                if(head->data == st.top()){
                    st.pop();
                    head = head->next;
                }
                else{

                    return false;
                }
            }

            return true;
            

        }
    };

int main(){

    vector<int> arr = {1,1,3};
    ListNode* head = ArrayTolist(arr);

    Palindrom Rvs;
   bool head1 = Rvs.CheckByOtherMethod(head);

   if(head1 == 1){
    cout<<"true";
   }
   else{
    cout<<"false";
   }
    // while (head1 != NULL)
    // {
    //     cout<<head1->data<<"-> ";
    //     head1 = head1->next;
    // }
    






    return  0;
}