/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;

            }
            // check loop
            if(fast==slow){
                break;
            }
        }
            if(fast==NULL){
                // NO CYCLE
                return NULL;
            }
            // yaha tak loop chal gaya matlab slow or fast meet kar gaye
            slow=head;
            // slow & fast -> 1 step
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        
    
    }
};