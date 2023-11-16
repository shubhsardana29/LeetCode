/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //break into two halves
       ListNode* midNode= middleNode(head);
       ListNode* head2= midNode->next;
       midNode->next=NULL;


        //reverse 2nd half
        ListNode *prev = NULL;
        ListNode *curr = head2;
        head2= reverseUsingRecursion(prev , curr);

        // compare both l.l
        bool ans = compareLL(head,head2);
        return ans;
        
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL){
            
            fast = fast->next;
            if(fast->next!=NULL){
                fast = fast->next;
                // fast ne 2 step chal liye
                // ab slow 1 baar
                slow=slow->next;
            }
        }
        return slow; 
    }

    ListNode* reverseUsingRecursion(ListNode* prev , ListNode *curr) {

        //base case
        if(curr == NULL){
            return prev;
        }

        ListNode *nextNode=curr->next;
        // 1 case khud ka
            curr->next=prev;
        
        // baaki recursion se
        prev=curr;
        curr=nextNode;
        ListNode* RecursionAns = reverseUsingRecursion(prev,curr);

        return RecursionAns;

    }

    bool compareLL(ListNode* head,ListNode* head2){
        ListNode *temp1 = head;
        ListNode *temp2 = head2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;

            }
        }
        // till this point we have matched the complete l.l in case of even or choti l.l in case of odd is traversed completely
        return true;
    }
};