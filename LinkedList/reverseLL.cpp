/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};

APPROACH 2

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* ans=reverseList(head->next);// From head next element,LinkedList is sorted
        head->next->next=head; //For remaining part...DRY RUN!!!
        head->next=NULL;
        return ans;
    }
};
*/
