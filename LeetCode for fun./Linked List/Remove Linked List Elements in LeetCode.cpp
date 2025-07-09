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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL;
        while(head != NULL && head->val == val) {
            ListNode *tmp2 = head;
            head = head->next;
            delete tmp2;
        }
        ListNode *tmp = head;
        while(tmp != NULL) {
            if (tmp->val == val) {
                prev->next = tmp->next;
                delete tmp;
                tmp = prev->next;
            }
            else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};
