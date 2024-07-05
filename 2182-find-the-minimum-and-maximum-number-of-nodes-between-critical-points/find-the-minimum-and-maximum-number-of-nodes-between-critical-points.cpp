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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v, re;
        int cnt = 1;
        if (head == NULL || head->next == NULL) {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        int last = 100000, lc;
        ListNode *ptr = head->next, *ptr1 = head;
        while (ptr->next != NULL) {
            if ((ptr1->val) > (ptr->val) && (ptr->val) < ptr->next->val) {
                v.push_back(cnt);
                if (last == 100000) {
                    cout << cnt << endl;
                    // last=cnt;
                    last += 10;
                    lc = cnt;
                } else {
                    cout << cnt - lc << endl;
                    last = min(last, cnt - lc);
                    lc = cnt;
                }
            } else if ((ptr1->val) < (ptr->val) &&
                       (ptr->val) > (ptr->next->val)) {
                v.push_back(cnt);
                if (last == 100000) {
                    cout << cnt << endl;
                    // last=cnt;
                    last += 10;
                    lc = cnt;
                } else {
                    cout << cnt - lc << endl;
                    last = min(last, cnt - lc);
                    lc = cnt;
                }
            }
            cnt++;
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }

        if (v.size() < 2) {
            re.push_back(-1);
            re.push_back(-1);
        } else {
            re.push_back(last);
            re.push_back(v[v.size() - 1] - v[0]);
        }
        return re;
    }
};