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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp!=NULL){
          st.push(temp);
          temp=temp->next;        
        }
        int carry = 0; 
        ListNode* resultHead = nullptr;

        while(!st.empty()){
            temp = st.top();
            st.pop();
            int newValue = temp->val * 2 + carry;
            carry = newValue / 10; 

             // Update current node's value
            temp->val = newValue % 10;

            // Link the current node to the result list
            temp->next = resultHead;
            resultHead = temp;
        }
        // If carry exists after processing all nodes, add a new node
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = resultHead;
            resultHead = newHead;
        }

        return resultHead;
    }
};