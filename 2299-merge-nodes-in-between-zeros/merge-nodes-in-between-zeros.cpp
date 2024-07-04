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
    ListNode* mergeNodes(ListNode* head) {
        if (!head || !head->next) return head;  
        
        ListNode* dummy = new ListNode(0); 
        ListNode* current = dummy;  
        
        ListNode* start = head;  
        
        while (start && start->next) {
            ListNode* end = start->next;
            
            while (end && end->val != 0) {
                end = end->next;
            }
            
            int sum = 0;
            ListNode* temp = start->next;
            while (temp != end) {
                sum += temp->val;
                temp = temp->next;
            }
            
            current->next = new ListNode(sum);
            current = current->next;

            start = end;
        }
        
        return dummy->next;  
    }
};
