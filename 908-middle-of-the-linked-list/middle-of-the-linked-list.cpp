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
    ListNode* middleNode(ListNode* head) {
        // int n = getLength(head);
        // int middlePos = (n/2)+1;
        // int currentPos = 1;
        
        // while(currentPos!=middlePos){
        //     currentPos++;
        //     head=head->next;
        // }
        // return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL){
            // fast will go only 2 steps but do it 1 by 1 step because possibily next step could be bull
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                // fast ne 2 step chal liye

                // ab slow 1 baar
                slow=slow->next;
            }
        }
        return slow;

        
        
    }
    // int getLength(ListNode* head) {
    //     ListNode* temp = head;
    //     int len=0;
    //     while(temp!=NULL){
    //         len++;
    //         temp=temp->next;
    //     }
    //     return len;
    // }
};