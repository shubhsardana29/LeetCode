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
    ListNode* removeNodes(ListNode* head) {
        int maxi=INT_MIN;
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp!=NULL){
          st.push(temp);
          temp=temp->next;        
        }
        temp = st.top();
        st.pop();
        maxi = max(temp->val,maxi);

        ListNode* resultHead = new ListNode(temp->val);

        while(!st.empty()){
            temp = st.top();
            st.pop();

            if(temp->val<maxi){
                continue; //skip this node
            }else{
                ListNode* newNode = new ListNode(temp->val);
                newNode->next = resultHead;
                resultHead = newNode;
                maxi = max(temp->val,maxi);
            }
        }
        return resultHead;
    }
};