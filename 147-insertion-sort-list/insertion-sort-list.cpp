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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        head->next = insertionSortList(head->next);
        return swapIfLarge(head);
    }
    ListNode* swapIfLarge(ListNode* head) {
        if(head->next == NULL||head->next->val > head->val) {
            return head;
        }
        ListNode* temp = head->next;
        head->next = temp->next;
        temp->next = swapIfLarge(head);
        return temp;
    }
};